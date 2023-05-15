/***
 * @Author       : baixiaobo
 * @Date         : 2022-07-12 12:45:56
 * @LastEditTime : 2022-07-15 15:52:55
 * @Description  : ins信号解析透传接口与头文件
 * @FilePath     : /Calmcar_Pilot_fusionbackup0626/Calmcar_Pilot_fusion/Calmcar_Pilot/04_SWC/ToEHP/PositionToEHP/src/ins_signal.hpp
 */
// #pragma once

#pragma once
// #include "online_odom_header.h"
#include "common_odom.h"

class InsSubscriber
{
public:
  InsSubscriber(std::string ins_topic_name) : ins_topic_name_(ins_topic_name){};
  void subscribe_callback(std::string type);
  bool parse_ins(std::deque<ins_in::proto::Frame> &ins_queue);
  void print_ins();
  bool check_ins_boundary(ins_in::proto::Frame &ins_in);
  std::string get_ins_topic() { return ins_topic_name_; };

  ins_in::proto::Frame current_ins_frame;
  ins_in::proto::Frame last_ins_frame;

private:
  std::mutex ins_mutex;
  int save_log_tag_global = 20000;
  std::string ins_topic_name_;
  std::deque<ins_in::proto::Frame> new_ins_deque_;
};
void InsSubscriber::print_ins()
{
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().orientation().roll() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().orientation().pitch() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().orientation().heading() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().position().latitude() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().position().longitude() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().position().altitude() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().speed().east_spd() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().speed().north_spd() << std::endl;
  std::cout << std::fixed << std::setprecision(10) << "current_ins_frame.orientation().roll(): " << current_ins_frame.ins().speed().to_ground_spd() << std::endl;
}
void InsSubscriber::subscribe_callback(std::string type)
{
  LOG(INFO) << " 开始调用ins订阅解析程序";
  calmcar::dds::InitSubscribe(type, 5, [&](void *data, uintmax_t size)
                              {
                      LOG_EVERY_N(INFO, save_log_tag_global) << "ins proto解析中";
                      ins_in::proto::Frame ins_frame;
                      if (!ins_frame.ParseFromArray(data, size))
                      {  
                        LOG(WARNING) << "ins proto解析出错";
                      }
                      //if (check_ins_boundary(ins_frame))
                      if (true)
                      {
                        std::lock_guard<std::mutex> lock(ins_mutex);
                        current_ins_frame.Clear();
                        current_ins_frame = ins_frame;
                        // print_ins();
                        new_ins_deque_.push_back(current_ins_frame);
                        last_ins_frame.Clear();
                        last_ins_frame = current_ins_frame;
                        while (new_ins_deque_.size()>200)
                        {
                          new_ins_deque_.pop_front();
                        }
                      }
                      else
                      {
                        LOG(WARNING) << "ins proto中可以提取到ins信号，但信号无效";
                      } });
}
bool InsSubscriber::parse_ins(std::deque<ins_in::proto::Frame> &ins_queue)
{
  std::lock_guard<std::mutex> lock(ins_mutex);
  if (new_ins_deque_.size() > 0)
  {
    ins_queue.insert(ins_queue.end(), new_ins_deque_.begin(), new_ins_deque_.end());
    new_ins_deque_.clear();
    return true;
  }
  else
  {
    return false;
  }
}

bool InsSubscriber::check_ins_boundary(ins_in::proto::Frame &ins_in)
{
  if (last_ins_frame.ins().has_angular_velocity())
  {
    double last_time = (double)last_ins_frame.sys_timestamp() / 1000000;
    double current_time = (double)current_ins_frame.sys_timestamp() / 1000000;
    if (current_time - last_time < 0)
    {
      LOG(WARNING) << "ins 当前帧时间戳小于上一帧时间戳，时间顺序出错";
      LOG(WARNING) << "上帧时间戳:" << std::setprecision(20) << last_time;
      LOG(WARNING) << "本帧时间戳:" << std::setprecision(20) << current_time;
      return false;
    }
    if (current_time - last_time > 1)
    {
      LOG(WARNING) << "ins 为100Hz，当前帧时间戳减掉上一帧时间戳，时间差大于1秒，也即连续丢帧100帧以上，ins_odom模块退出";
      LOG(WARNING) << "上帧时间戳:" << std::fixed << std::setprecision(20) << last_time;
      LOG(WARNING) << "本帧时间戳:" << std::fixed << std::setprecision(20) << current_time;
      return false;
    }
  }
  if (ins_in.sys_timestamp() < 0)
  {
    LOG(WARNING) << "ins时间戳（sys_timestamp）小于0，数据有误，时间:" << std::fixed << std::setprecision(20) << ins_in.sys_timestamp();
    return false;
  }
  if (ins_in.ins().position().longitude() < -180 || ins_in.ins().position().longitude() > 180)
  {
    LOG(WARNING) << "ins经度（longitude）范围超出（-180，180）的范围，经度： " << std::fixed << std::setprecision(20) << ins_in.ins().position().longitude();
    return false;
  }
  if (ins_in.ins().position().latitude() < -90 || ins_in.ins().position().latitude() > 90)
  {
    LOG(WARNING) << "ins维度（latitude）范围超出（-90，90）的范围，维度： " << std::fixed << std::setprecision(20) << ins_in.ins().position().latitude();
    return false;
  }
  if (ins_in.ins().position().altitude() < -10000 || ins_in.ins().position().altitude() > 10000)
  {
    LOG(WARNING) << "ins海拔（altitude）范围超出（-10000，10000）的范围，海拔： " << std::fixed << std::setprecision(20) << ins_in.ins().position().altitude();
    return false;
  }
  if (ins_in.ins().orientation().heading() < -180 || ins_in.ins().orientation().heading() > 180)
  {
    LOG(WARNING) << "ins航向角（heading）范围超出（-180，180）的范围，航向角： " << std::fixed << std::setprecision(20) << ins_in.ins().orientation().heading();
    return false;
  }
  if (ins_in.ins().speed().north_spd() < -100 || ins_in.ins().speed().north_spd() > 100)
  {
    LOG(WARNING) << "ins北向速度（north_spd）范围超出（-180，180）的范围，北向速度： " << std::fixed << std::setprecision(20) << ins_in.ins().speed().north_spd();
    return false;
  }
  if (ins_in.ins().speed().east_spd() < -100 || ins_in.ins().speed().east_spd() > 100)
  {
    LOG(WARNING) << "ins东向速度（east_spd）范围超出（-180，180）的范围，东向速度： " << std::fixed << std::setprecision(20) << ins_in.ins().speed().east_spd();
    return false;
  }
  if (ins_in.ins().speed().to_ground_spd() < -100 || ins_in.ins().speed().to_ground_spd() > 100)
  {
    LOG(WARNING) << "ins地向速度（to_ground_spd）范围超出（-180，180）的范围，地向速度： " << std::fixed << std::setprecision(20) << ins_in.ins().speed().to_ground_spd();
    return false;
  }
  if (ins_in.ins().linear_acceleration().x() < -4 || ins_in.ins().linear_acceleration().x() > 4)
  {
    LOG(WARNING) << "ins x轴向线加速度（linear_acceleration）范围超出（-4，4）的范围，x轴向线加速度： " << std::fixed << std::setprecision(20) << ins_in.ins().linear_acceleration().x();
    return false;
  }
  if (ins_in.ins().linear_acceleration().y() < -4 || ins_in.ins().linear_acceleration().y() > 4)
  {
    LOG(WARNING) << "ins y轴向线加速度（linear_acceleration）范围超出（-4，4）的范围，y轴向线加速度： " << std::fixed << std::setprecision(20) << ins_in.ins().linear_acceleration().y();
    return false;
  }
  if (ins_in.ins().linear_acceleration().z() < -4 || ins_in.ins().linear_acceleration().z() > 4)
  {
    LOG(WARNING) << "ins z轴向线加速度（linear_acceleration）范围超出（-4，4）的范围，z轴向线加速度： " << std::fixed << std::setprecision(20) << ins_in.ins().linear_acceleration().z();
    return false;
  }
  if (ins_in.ins().orientation().pitch() < -90 || ins_in.ins().orientation().pitch() > 90)
  {
    LOG(WARNING) << "ins俯仰角（pitch）范围超出（-90，90）的范围，ins俯仰角： " << std::fixed << std::setprecision(20) << ins_in.ins().orientation().pitch();
    return false;
  }
  if (ins_in.ins().orientation().roll() < -180 || ins_in.ins().orientation().roll() > 180)
  {
    LOG(WARNING) << "ins翻滚角（roll）范围超出（-180，180）的范围，ins翻滚角： " << std::fixed << std::setprecision(20) << ins_in.ins().orientation().roll();
    return false;
  }
  if (ins_in.ins().angular_velocity().x() < -250 || ins_in.ins().angular_velocity().x() > 250)
  {
    LOG(WARNING) << "ins x轴向角速度（angular_velocity）范围超出（-250，250）的范围，x轴向角速度： " << std::fixed << std::setprecision(20) << ins_in.ins().angular_velocity().x();
    return false;
  }
  if (ins_in.ins().angular_velocity().y() < -250 || ins_in.ins().angular_velocity().y() > 250)
  {
    LOG(WARNING) << "ins y轴向角速度（angular_velocity）范围超出（-250，250）的范围，y轴向角速度： " << std::fixed << std::setprecision(20) << ins_in.ins().angular_velocity().y();
    return false;
  }
  if (ins_in.ins().angular_velocity().z() < -250 || ins_in.ins().angular_velocity().z() > 250)
  {
    LOG(WARNING) << "ins z轴向角速度（angular_velocity）范围超出（-250，250）的范围，z轴向角速度： " << std::fixed << std::setprecision(20) << ins_in.ins().angular_velocity().z();
    return false;
  }
  LOG_EVERY_N(INFO, save_log_tag_global) << "ins 数据校验通过";
  return true;
};

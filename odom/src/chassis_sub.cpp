/***
 * @Author       : baixiaobo
 * @Date         : 2022-07-25 16:52:06
 * @LastEditTime : 2022-07-25 17:17:54
 * @Description  : 接收底盘信号,迭代递推轮速odom
 * @FilePath     : /Calmcar_Pilot/04_SWC/Odom/ChassisOdom/src/chassis_signal.hpp
 */

// #pragma once
#pragma once
#include "common_odom.h"

class ChassisSubscriber
{
public:
    ChassisSubscriber(std::string chassis_topic_name) : chassis_topic_name_(chassis_topic_name){};
    Calmcar::drivers::CHASIS::Chasis current_chassis_frame;
    Calmcar::drivers::CHASIS::Chasis last_chassis_frame;
    void subscribe_callback(std::string type);
    bool parse_chassis(std::deque<Calmcar::drivers::CHASIS::Chasis> &chassis_queue);
    void print_chassis();
    bool check_chassis_boundary(Calmcar::drivers::CHASIS::Chasis &chassis_in);
    std::string get_chassis_topic() { return chassis_topic_name_; };
    int save_log_tag_global = 20000;

private:
    std::mutex chassis_mutex;
    std::string chassis_topic_name_;
    std::deque<Calmcar::drivers::CHASIS::Chasis> new_chassis_deque_;
};

void ChassisSubscriber::print_chassis()
{
    // std::cout << std::fixed << std::setprecision(10) << "接收到的底盘信号时间戳: " << current_chassis_frame.header().timestamp_sec() << std::endl;
    // std::cout << std::fixed << std::setprecision(10) << "接收到的底盘后左轮速信号数值: " << current_chassis_frame.wheelspeed_report_6a().rl() << std::endl;
}
void ChassisSubscriber::subscribe_callback(std::string type)
{
    // std::cout << "调用底盘信号订阅程序！" << std::endl;
    LOG(INFO) << " 调用底盘信号订阅程序！";
    calmcar::dds::InitSubscribe(type, 5, [&](void *data, uintmax_t size)
                                {
        // std::cout << "chassis proto解析中" << std::endl;
        LOG_EVERY_N(INFO, save_log_tag_global) << "chassis proto解析中";
        Calmcar::drivers::CHASIS::Chasis chassis_frame;
        if (!chassis_frame.ParseFromArray(data, size))
        {
            LOG(WARNING) << "chassis proto 解析出错";
            // std::cout << "chassis proto 解析出错" << std::endl;
            return;
        }
        // std::cout << "chassis proto 解析成功" << std::endl;
        LOG_EVERY_N(INFO, save_log_tag_global) << "chassis proto 解析成功";
        //if (check_chassis_boundary(chassis_frame)) 
        if (true) 
        {
            current_chassis_frame.Clear();
            current_chassis_frame = chassis_frame;
            std::lock_guard<std::mutex> lock(chassis_mutex);
            new_chassis_deque_.push_back(current_chassis_frame);
            last_chassis_frame.Clear();
            last_chassis_frame = current_chassis_frame;
            print_chassis();
            while (new_chassis_deque_.size()>200)
            {
                new_chassis_deque_.pop_front();
            }
            
        } 
        else
        {
            LOG(WARNING) << "chassis proto 信号可以解析成功，但解析出来的数据经过数据校核，超过预设数据边界，数据有误";
        } });
}
bool ChassisSubscriber::parse_chassis(std::deque<Calmcar::drivers::CHASIS::Chasis> &chassis_queue)
{
    LOG_EVERY_N(INFO, save_log_tag_global) << "开始 parse 底盘信号";
    std::lock_guard<std::mutex> lock(chassis_mutex);
    // std::cout << "开始 parse 底盘信号" << std::endl;
    // std::cout << "new_chassis_deque_.size()" <<new_chassis_deque_.size()<< std::endl;
    if (new_chassis_deque_.size() > 0)
    {
        chassis_queue.insert(chassis_queue.end(), new_chassis_deque_.begin(), new_chassis_deque_.end());
        new_chassis_deque_.clear();
        LOG_EVERY_N(INFO, save_log_tag_global) << "成功 parse 底盘信号";
        // std::cout << "成功 parse 底盘信号------------" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool ChassisSubscriber::check_chassis_boundary(Calmcar::drivers::CHASIS::Chasis &chassis_in)
{
    if (chassis_in.has_header())
    {
        double last_time = (double)last_chassis_frame.header().timestamp_sec() / 1000000;
        double current_time = (double)current_chassis_frame.header().timestamp_sec() / 1000000;
        if (current_time - last_time < 0)
        {
            LOG(WARNING) << "chassis 当前帧时间戳小于上一帧时间戳，时间顺序出错";
            LOG(WARNING) << "上帧时间戳:" << std::setprecision(20) << last_time;
            LOG(WARNING) << "本帧时间戳:" << std::setprecision(20) << current_time;
            return false;
        }
        if (current_time - last_time > 1)
        {
            LOG(WARNING) << "chassis为100Hz，当前帧时间戳减掉上一帧时间戳，时间差大于1秒，也即连续丢帧100帧以上，chassis_odom模块退出";
            LOG(WARNING) << "上帧时间戳:" << std::fixed << std::setprecision(20) << last_time;
            LOG(WARNING) << "本帧时间戳:" << std::fixed << std::setprecision(20) << current_time;
            return false;
        }
    }
    if (chassis_in.header().timestamp_sec() < 0)
    {
        LOG(WARNING) << "chassis时间戳（sys_timestamp）小于0，数据有误，时间:" << std::setprecision(20) << chassis_in.header().timestamp_sec();
        return false;
    }
    if (chassis_in.wheelspeed_report_6a().rl() <= -327.67 || chassis_in.wheelspeed_report_6a().rl() >= 327.67)
    {
        LOG(WARNING) << "后左底盘轮速信号(chassis_rl)范围超出（-327.67，327.6）的范围，后左底盘轮速： " << std::setprecision(20) << chassis_in.wheelspeed_report_6a().rl();
        return false;
    }
    if (chassis_in.wheelspeed_report_6a().rr() <= -327.67 || chassis_in.wheelspeed_report_6a().rr() >= 327.67)
    {
        LOG(WARNING) << "后右底盘轮速信号(chassis_rr)范围超出（-327.67，327.6）的范围，后右底盘轮速： " << std::setprecision(20) << chassis_in.wheelspeed_report_6a().rr();
        return false;
    }
    if (chassis_in.wheelspeed_report_6a().fl() <= -327.67 || chassis_in.wheelspeed_report_6a().fl() >= 327.67)
    {
        LOG(WARNING) << "前左底盘轮速信号(chassis_fl)范围超出（-327.67，327.6）的范围，左底盘轮速： " << std::setprecision(20) << chassis_in.wheelspeed_report_6a().fl();
        return false;
    }
    if (chassis_in.wheelspeed_report_6a().rr() <= -327.67 || chassis_in.wheelspeed_report_6a().rr() >= 327.67)
    {
        LOG(WARNING) << "前右底盘轮速信号(chassis_fr)范围超出（-327.67，327.6）的范围，前右底盘轮速： " << std::setprecision(20) << chassis_in.wheelspeed_report_6a().fr();
        return false;
    }
    //轮速差值判断
    if (abs(chassis_in.wheelspeed_report_6a().rl() - chassis_in.wheelspeed_report_6a().rr()) > 6.06)
    {
        LOG(WARNING) << "左右后轮的速度差值过大，线速度大于2m/s ,heading角速度大于85deg/s，轮速差值为：" << chassis_in.wheelspeed_report_6a().rl() - chassis_in.wheelspeed_report_6a().rr();
        return false;
    }
    if (abs(chassis_in.wheelspeed_report_6a().rl() - chassis_in.wheelspeed_report_6a().fl()) > 6.06)
    {
        LOG(WARNING) << "左后轮和左前轮的速度差值过大，线速度大于2m/s ,heading角速度大于85deg/s，轮速差值为：" << chassis_in.wheelspeed_report_6a().rl() - chassis_in.wheelspeed_report_6a().fl();
        return false;
    }
    if (abs(chassis_in.wheelspeed_report_6a().rl() - chassis_in.wheelspeed_report_6a().fr()) > 6.06)
    {
        LOG(WARNING) << "后左轮和前右轮的速度差值过大，线速度大于2m/s ,heading角速度大于85deg/s，轮速差值为：" << chassis_in.wheelspeed_report_6a().rl() - chassis_in.wheelspeed_report_6a().fr();
        return false;
    }
    if (abs(chassis_in.wheelspeed_report_6a().rr() - chassis_in.wheelspeed_report_6a().fl()) > 6.06)
    {
        LOG(WARNING) << "后右轮和前左轮的速度差值过大，线速度大于2m/s ,heading角速度大于85deg/s，轮速差值为：" << chassis_in.wheelspeed_report_6a().rr() - chassis_in.wheelspeed_report_6a().fl();
        return false;
    }
    if (abs(chassis_in.wheelspeed_report_6a().rr() - chassis_in.wheelspeed_report_6a().fr()) > 6.06)
    {
        LOG(WARNING) << "后右轮和前右轮的速度差值过大，线速度大于2m/s ,heading角速度大于85deg/s，轮速差值为：" << chassis_in.wheelspeed_report_6a().rr() - chassis_in.wheelspeed_report_6a().fr();
        return false;
    }
    if (abs(chassis_in.wheelspeed_report_6a().fl() - chassis_in.wheelspeed_report_6a().fr()) > 6.06)
    {
        LOG(WARNING) << "前左轮和前右轮的速度差值过大，线速度大于2m/s ,heading角速度大于85deg/s，轮速差值为：" << chassis_in.wheelspeed_report_6a().fl() - chassis_in.wheelspeed_report_6a().fr();
        return false;
    }                                                                    
    if (chassis_in.gear_report_67().state() != Calmcar::drivers::CHASIS::Gear_report_67_StateType::Gear_report_67_StateType_STATE_NONE &&
        chassis_in.gear_report_67().state() != Calmcar::drivers::CHASIS::Gear_report_67_StateType::Gear_report_67_StateType_STATE_PARK &&
        chassis_in.gear_report_67().state() != Calmcar::drivers::CHASIS::Gear_report_67_StateType::Gear_report_67_StateType_STATE_REVERSE &&
        chassis_in.gear_report_67().state() != Calmcar::drivers::CHASIS::Gear_report_67_StateType::Gear_report_67_StateType_STATE_NEUTRAL &&
        chassis_in.gear_report_67().state() != Calmcar::drivers::CHASIS::Gear_report_67_StateType::Gear_report_67_StateType_STATE_DRIVE &&
        chassis_in.gear_report_67().state() != Calmcar::drivers::CHASIS::Gear_report_67_StateType::Gear_report_67_StateType_STATE_LOW)
    {
        LOG(WARNING) << "档位值处于预设范围边界之外 " << chassis_in.gear_report_67().state();
        return false;
    }
    if (chassis_in.steering_report_65().angle() < -470 || chassis_in.steering_report_65().angle() > 470)
    {
        LOG(WARNING) << "方向盘转角超过了[-470,470]的数据范围，当前方向盘转角为：" << chassis_in.steering_report_65().angle();
        return false;
    }
    LOG_EVERY_N(INFO, save_log_tag_global) << "chassis 数据校验通过";
    return true;
}


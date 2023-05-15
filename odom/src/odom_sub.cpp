/***
 * @Author       : baixiaobo
 * @Date         : 2022-07-25 16:52:06
 * @LastEditTime : 2022-07-25 17:17:54
 * @Description  : 接收odom盘信号,测试里程计有效性
 * @FilePath     : /Calmcar_Pilot/04_SWC/Odom/ChassisOdom/src/odom_signal.hpp
 */
// #pragma once
#pragma once
// #include "online_odom_header.h"
#include "common_odom.h"

class OdomSubscriber
{
public:
    OdomSubscriber(std::string odom_topic_name);
    void subscribe_callback(std::string type);
    void print_odom();
    std::string get_odom_topic_name() { return odom_topic_name_; };
    bool check_odom_boundary(odom::proto::Frame &odom_in);

    odom::proto::Frame current_odom_frame;
    odom::proto::Frame last_odom_frame;
    int save_log_tag_global = 20000;
    // void parse_odom(std::deque<odom::proto::Frame> &odom_queue);
private:
    std::string odom_topic_name_;
    std::mutex odom_mutex;
    std::deque<odom::proto::Frame> new_odom_deque_;
};
void OdomSubscriber::print_odom()
{
    std::cout << "开始打印odom信号" << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "odom_id: " << current_odom_frame.header().odom_id() << std::endl;
    std::cout << std::fixed << std::setprecision(20) << "sys_timestamp: " << current_odom_frame.header().sys_timestamp() << std::endl;
    std::cout << std::fixed << std::setprecision(20) << "utc_timestamp: " << current_odom_frame.header().ins_utm_timestamp() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "frame_id: " << current_odom_frame.header().frame_id() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "position().x(): " << current_odom_frame.odom().position().x() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "position().y(): " << current_odom_frame.odom().position().y() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "position().z(): " << current_odom_frame.odom().position().z() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "pose_quaternion().w(): " << current_odom_frame.odom().pose_quaternion().w() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "pose_quaternion().x(): " << current_odom_frame.odom().pose_quaternion().x() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "pose_quaternion().y(): " << current_odom_frame.odom().pose_quaternion().y() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "pose_quaternion().z(): " << current_odom_frame.odom().pose_quaternion().z() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "linear_speed().x(): " << current_odom_frame.odom().linear_speed().x() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "linear_speed().y(): " << current_odom_frame.odom().linear_speed().y() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "linear_speed().z(): " << current_odom_frame.odom().linear_speed().z() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "confidence: " << current_odom_frame.info().confidence() << std::endl;
    std::cout << std::fixed << std::setprecision(10) << "status: " << current_odom_frame.info().status() << std::endl;
    std::cout << "本帧odom数据打印完毕" << std::endl;
}

OdomSubscriber::OdomSubscriber(std::string odom_topic_name)
{
    odom_topic_name_ = odom_topic_name;
}

void OdomSubscriber::subscribe_callback(std::string type)
{
    LOG(INFO) << " 调用 odom 订阅程序！";
    calmcar::dds::InitSubscribe(type, 5, [&](void *data, uintmax_t size)
                                {
        LOG_EVERY_N(INFO, save_log_tag_global) << "odom proto 解析中";
        odom::proto::Frame odom_frame;
        if (!odom_frame.ParseFromArray(data, size))
        {
            LOG(WARNING) << "odom proto 解析出错";
        } 
        //if (check_odom_boundary(odom_frame)) 
        if (true) 
        {
            current_odom_frame.Clear();
            current_odom_frame = odom_frame;
            new_odom_deque_.push_back(current_odom_frame);
            while (new_odom_deque_.size()>200)
            {
                new_odom_deque_.pop_front();
            }
            // print_odom();
            last_odom_frame.Clear();
            last_odom_frame=current_odom_frame;
        } else
        {
            LOG(WARNING) << "odom proto 中提取到的底盘信号无效";
        } });
};
// void OdomSubscriber::parse_odom(std::deque<Calmcar::drivers::CHASIS::Chasis> &odom_queue)
// {
//     std::lock_guard<std::mutex> lock(odom_mutex);
//     if (new_odom_deque_.size() > 0)
//     {
//         odom_queue.insert(odom_queue.end(), new_odom_deque_.begin(), new_odom_deque_.end());
//         new_odom_deque_.clear();
//     };
// };

bool OdomSubscriber::check_odom_boundary(odom::proto::Frame &odom_in)
{
    if (odom_in.has_header())
    {
        double last_time = odom_in.header().sys_timestamp();
        double current_time = odom_in.header().sys_timestamp();
        if (current_time - last_time < 0)
        {
            LOG(WARNING) << "odom当前帧时间戳小于上一帧时间戳，时间顺序出错";
            LOG(WARNING) << "上帧时间戳:" << std::setprecision(20) << last_time;
            LOG(WARNING) << "本帧时间戳:" << std::setprecision(20) << current_time;
        }
    }
    if (odom_in.header().sys_timestamp() < 0)
    {
        LOG(WARNING) << "odom时间戳（timestamp）小于0，数据有误，时间:" << std::setprecision(20) << odom_in.header().sys_timestamp();
        return false;
    }
    LOG_EVERY_N(INFO, save_log_tag_global) << "odom 数据校验通过";
    return true;
};


/***
 * @Author       : baixiaobo
 * @Date         : 2022-07-19 14:51:48
 * @LastEditTime : 2022-07-21 14:10:23
 * @Description  : 订阅odom-proto 信号，转为ros2消息
 * @FilePath     : /Calmcar_Pilot/04_SWC/OdomMap/ChassisOdomMap/include/ins_odom_subscriber.hpp
 */
#include "odom_header.h"
using std::placeholders::_1;

class OdomSubscriber
{
public:
    OdomSubscriber(std::shared_ptr<rclcpp::Node> &node,std::string odom_topic);
    void odom_callback(const calmcar::msg::BinraryData &msg);
    bool parse_odom(std::deque<odom::proto::Frame> &odom_queue);

private:
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Subscription<calmcar::msg::BinraryData>::SharedPtr subscription_;
    std::deque<odom::proto::Frame> new_odom_queue_;
    std::mutex odom_mutex_;
    bool check_odom_();
    odom::proto::Frame last_odom_;
    odom::proto::Frame current_odom_;
    std::string odom_topic_;
};
bool OdomSubscriber::check_odom_()
{
    double delta_time = current_odom_.header().sys_timestamp() - last_odom_.header().sys_timestamp();
    if (delta_time < 0)
    {
        return false;
    }
    if (delta_time == 0)
    {
        return false;
    }
    last_odom_ = current_odom_;
    return true;
}
OdomSubscriber::OdomSubscriber(std::shared_ptr<rclcpp::Node> &node,std::string odom_topic) : node_(node),odom_topic_(odom_topic)
{
    std::cout << "odom 订阅中" << std::endl;

    subscription_ = node_->create_subscription<calmcar::msg::BinraryData>(odom_topic_, 50,
                                                                          std::bind(&OdomSubscriber::odom_callback,
                                                                                    this, std::placeholders::_1));
}
void OdomSubscriber::odom_callback(const calmcar::msg::BinraryData &msg)
{
    odom::proto::Frame frame;
    if (msg.size > 0)
    {
        if (!frame.ParseFromArray((void *)msg.data.data(), msg.size))
        {
            std::cout << "odom proto解析出错" << std::endl;
        }
        current_odom_.Clear();
        current_odom_ = frame;
        if (true)
        {
            std::lock_guard<std::mutex> lock(odom_mutex_);
            new_odom_queue_.push_back(frame);
            last_odom_ = current_odom_;
        }
        while (new_odom_queue_.size() > 100000)
        {
            new_odom_queue_.pop_front();
        }
    }
}

bool OdomSubscriber::parse_odom(std::deque<odom::proto::Frame> &odom_queue)
{
    std::lock_guard<std::mutex> lock(odom_mutex_);
    if (new_odom_queue_.size() > 0)
    {
        odom_queue.insert(odom_queue.end(), new_odom_queue_.begin(), new_odom_queue_.end());
        new_odom_queue_.clear();
        return true;
    }
    else
    {
        return false;
    }
}
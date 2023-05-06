
/***
 * @Author       : baixiaobo
 * @Date         : 2022-08-23 15:29:09
 * @LastEditTime : 2022-08-24 09:57:43
 * @Description  :
 * @FilePath     : /ChassisOdomMap/src/local_map_on_odom.cpp
 */

#include "odom_subscriber_for_rviz.hpp"
#include "odom_publisher_for_rviz.hpp"
#include "odom_header.h"

using namespace std;
using std::placeholders::_1;
string tum_address = (std::string)PROJECT_PATH + "/tum_file/";
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = std::make_shared<rclcpp::Node>("odom_map_for_rviz");
    std::shared_ptr<OdomSubscriber> odom_subscriber_chassis_wheel = std::make_shared<OdomSubscriber>(node, "/chassis_odom_wheel_binrarydata_topic");
    std::shared_ptr<OdomSubscriber> odom_subscriber_chassis = std::make_shared<OdomSubscriber>(node, "/chassis_odom_binrarydata_topic");
    std::shared_ptr<OdomSubscriber> odom_subscriber_ins = std::make_shared<OdomSubscriber>(node, "/ins_odom_binrarydata_topic");
    std::shared_ptr<OdomPublisher> odom_publisher_chassis_wheel = std::make_shared<OdomPublisher>(node, "/odom_chassis_wheel", 50, tum_address);
    std::shared_ptr<OdomPublisher> odom_publisher_chassis = std::make_shared<OdomPublisher>(node, "/odom_chassis", 50, tum_address);
    std::shared_ptr<OdomPublisher> odom_publisher_ins = std::make_shared<OdomPublisher>(node, "/odom_ins", 50, tum_address);
    std::deque<odom::proto::Frame> odom_frame_ins;
    std::deque<odom::proto::Frame> odom_frame_chassis;
    std::deque<odom::proto::Frame> odom_frame_chassis_wheel;
    rclcpp::Rate rate(200);
    while (rclcpp::ok())
    {
        if (odom_subscriber_ins->parse_odom(odom_frame_ins))
        {
            odom_publisher_ins->Publish(odom_frame_ins, "ins_odom");
            odom_frame_ins.clear();
        }
        if (odom_subscriber_chassis->parse_odom(odom_frame_chassis))
        {
            odom_publisher_chassis->Publish(odom_frame_chassis, "chassis_odom");
            odom_frame_chassis.clear();
        }
        if (odom_subscriber_chassis_wheel->parse_odom(odom_frame_chassis_wheel))
        {
            odom_publisher_chassis_wheel->Publish(odom_frame_chassis_wheel, "chassis_odom_wheel");
            odom_frame_chassis_wheel.clear();
        }
        rclcpp::spin_some(node);
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}
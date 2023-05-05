/***
 * @Author       : baixiaobo
 * @Date         : 2022-06-28 15:15:15
 * @LastEditTime : 2022-07-19 10:35:44
 * @Description  : 将odom-proto 信号，转为ros2消息，发布出去，以及发布tf
 * @FilePath     : /Calmcar_Pilot/04_SWC/OdomMap/ChassisOdomMap/src/odom_publisher.hpp
 */
// #pragma once
#include "odom_header.h"

class OdomPublisher
{
public:
    OdomPublisher(std::shared_ptr<rclcpp::Node> &node, std::string topic_name, size_t buff_size,string tum_address);
    // OdomPublisher() = default;
    bool init_status = true;
    nav_msgs::msg::Path path_pub;
    std::deque<odom::proto::Frame> odom_queue;
    Eigen::Transform<double, 3, Eigen::Affine> init_transform_affine;
    std::shared_ptr<tf2_ros::TransformBroadcaster> odom_broadcaster; //定义发布器
    double time = 0;
    /* 发布点云*/
    void Publish(std::deque<odom::proto::Frame> &odom_input, std::string odom_source);
    void print_odom(odom::proto::Frame &current_odom_frame);

private:
    int buff_size_;
    string tum_address_;
    std::string frame_id_;
    std::string topic_name_;
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr publisher_path_;
};

OdomPublisher::OdomPublisher(std::shared_ptr<rclcpp::Node> &node,
                             std::string topic_name,
                             size_t buff_size,string tum_address) : node_(node), topic_name_(topic_name), buff_size_(buff_size),tum_address_(tum_address)
{
    publisher_ = node_->create_publisher<nav_msgs::msg::Odometry>(topic_name_, buff_size_);
    publisher_path_ = node_->create_publisher<nav_msgs::msg::Path>("base_link_path_to_map", buff_size_);
    odom_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(node_);
    // std::cout << "开始发布tf " << std::endl;
    // geometry_msgs::msg::TransformStamped trans;
    // trans.header.stamp = node_->now();
    // trans.header.frame_id = "map";
    // trans.child_frame_id = "baselink";
    // trans.transform.translation.x = 0.10869474808375041;
    // trans.transform.translation.y = 0;
    // trans.transform.translation.z = 0;
    // trans.transform.rotation.x = 0;
    // trans.transform.rotation.y = 0;
    // trans.transform.rotation.z = 0;
    // trans.transform.rotation.w = 1;
    // odom_broadcaster->sendTransform(trans);
}
void OdomPublisher::Publish(std::deque<odom::proto::Frame> &odom_input, std::string odom_source)
{
    // double time = node_->now().seconds();
    if (odom_source == "chassis_odom")
    {
        for (size_t i = 0; i < odom_input.size(); i++)
        {
            // geometry_msgs::msg::PoseStamped pose_path;
            // pose_path.pose.position.x = odom_input.at(i).odom().position().x();
            // pose_path.pose.position.y = odom_input.at(i).odom().position().y();
            // pose_path.pose.position.z = odom_input.at(i).odom().position().z();
            // pose_path.header.stamp = node_->now();
            // // printf("chassis_time: %d\n",odom_input.at(i).header().sys_timestamp());
            // pose_path.header.frame_id = "baselink";
            // path_pub.poses.push_back(pose_path);
            // publisher_path_->publish(path_pub);
            /*-----------保存tum轨迹文件------------*/
            //起点初始化
            if (init_status)
            {            
                init_transform_affine.setIdentity();
                Eigen::Matrix<double, 3, 3> rotation;
                float qx = odom_input.at(i).odom().pose_quaternion().x();
                float qy = odom_input.at(i).odom().pose_quaternion().y();
                float qz = odom_input.at(i).odom().pose_quaternion().z();
                float qw = odom_input.at(i).odom().pose_quaternion().w();
                Eigen::Quaterniond quaternion(qw,qx,qy,qz);
                rotation = quaternion.toRotationMatrix();
                Eigen::Matrix<double, 3, 1> position;
                float x = odom_input.at(i).odom().position().x();
                float y = odom_input.at(i).odom().position().y();
                float z = odom_input.at(i).odom().position().z();
                position(0,0) = x;
                position(1,0) = y;
                position(2,0) = z;
                Eigen::Matrix<double, 4, 4> transform_temp;
                transform_temp.setIdentity();
                transform_temp.block<3,3>(0,0) = rotation;
                transform_temp.block<3,1>(0,3) = position;
                init_transform_affine = transform_temp;
                init_status = false;
            }
            Eigen::Transform<double, 3, Eigen::Affine> transform_affine;
            transform_affine.setIdentity();
            Eigen::Matrix<double, 3, 3> rotation;
            float qx = odom_input.at(i).odom().pose_quaternion().x();
            float qy = odom_input.at(i).odom().pose_quaternion().y();
            float qz = odom_input.at(i).odom().pose_quaternion().z();
            float qw = odom_input.at(i).odom().pose_quaternion().w();
            Eigen::Quaterniond quaternion(qw,qx,qy,qz);
            rotation = quaternion.toRotationMatrix();
            Eigen::Matrix<double, 3, 1> position;
            float x = odom_input.at(i).odom().position().x();
            float y = odom_input.at(i).odom().position().y();
            float z = odom_input.at(i).odom().position().z();
            position(0,0) = x;
            position(1,0) = y;
            position(2,0) = z;
            Eigen::Matrix<double, 4, 4> transform_temp;
            transform_temp.setIdentity();
            transform_temp.block<3,3>(0,0) = rotation;
            transform_temp.block<3,1>(0,3) = position;
            transform_affine = transform_temp;
            transform_affine = init_transform_affine.inverse() * transform_affine;
            Eigen::Matrix<double, 4, 4> transform;
            transform = transform_affine.matrix();

            quaternion = transform.block<3,3>(0,0);
            x = transform(0,3);
            y = transform(1,3);
            z = transform(2,3);

            std::ofstream save_chassis_odom(tum_address_+"chassis_odom.txt", ios::app);
            save_chassis_odom.setf(ios::fixed, ios::floatfield);
            save_chassis_odom.precision(15);
            qx = quaternion.x();
            qy = quaternion.y();
            qz = quaternion.z();
            qw = quaternion.w();
            save_chassis_odom << time/100 << " " << x << " " << y << " " << z << " " << qx << " " << qy << " " << qz << " " << qw << std:: endl;
            time++;
            // save_chassis_odom << (double)odom_input.at(i).header().sys_timestamp()/1000000 << " " << x << " " << y << " " << z << " " << qx << " " << qy << " " << qz << " " << qw << std:: endl;
            /*------------------------------------*/
        }
    }
    else if (odom_source == "chassis_odom_wheel")
    {
        for (size_t i = 0; i < odom_input.size(); i++)
        {
            // std::cout << "开始发布ros2_path " << std::endl;
            // geometry_msgs::msg::PoseStamped pose_path;
            // pose_path.pose.position.x = odom_input.at(i).odom().position().x();
            // pose_path.pose.position.y = odom_input.at(i).odom().position().y();
            // pose_path.pose.position.z = odom_input.at(i).odom().position().z();
            // pose_path.header.stamp = node_->now();
            // // printf("wheel_time: %d\n",odom_input.at(i).header().sys_timestamp());
            // pose_path.header.frame_id = "baselink";
            // path_pub.poses.push_back(pose_path);
            // publisher_path_->publish(path_pub);
            /*-----------保存tum轨迹文件------------*/
            //起点初始化
            if (init_status)
            {            
                init_transform_affine.setIdentity();
                Eigen::Matrix<double, 3, 3> rotation;
                float qx = odom_input.at(i).odom().pose_quaternion().x();
                float qy = odom_input.at(i).odom().pose_quaternion().y();
                float qz = odom_input.at(i).odom().pose_quaternion().z();
                float qw = odom_input.at(i).odom().pose_quaternion().w();
                Eigen::Quaterniond quaternion(qw,qx,qy,qz);
                rotation = quaternion.toRotationMatrix();
                Eigen::Matrix<double, 3, 1> position;
                float x = odom_input.at(i).odom().position().x();
                float y = odom_input.at(i).odom().position().y();
                float z = odom_input.at(i).odom().position().z();
                position(0,0) = x;
                position(1,0) = y;
                position(2,0) = z;
                Eigen::Matrix<double, 4, 4> transform_temp;
                transform_temp.setIdentity();
                transform_temp.block<3,3>(0,0) = rotation;
                transform_temp.block<3,1>(0,3) = position;
                init_transform_affine = transform_temp;
                init_status = false;
            }
            Eigen::Transform<double, 3, Eigen::Affine> transform_affine;
            transform_affine.setIdentity();
            Eigen::Matrix<double, 3, 3> rotation;
            float qx = odom_input.at(i).odom().pose_quaternion().x();
            float qy = odom_input.at(i).odom().pose_quaternion().y();
            float qz = odom_input.at(i).odom().pose_quaternion().z();
            float qw = odom_input.at(i).odom().pose_quaternion().w();
            Eigen::Quaterniond quaternion(qw,qx,qy,qz);
            rotation = quaternion.toRotationMatrix();
            Eigen::Matrix<double, 3, 1> position;
            float x = odom_input.at(i).odom().position().x();
            float y = odom_input.at(i).odom().position().y();
            float z = odom_input.at(i).odom().position().z();
            position(0,0) = x;
            position(1,0) = y;
            position(2,0) = z;
            Eigen::Matrix<double, 4, 4> transform_temp;
            transform_temp.setIdentity();
            transform_temp.block<3,3>(0,0) = rotation;
            transform_temp.block<3,1>(0,3) = position;
            transform_affine = transform_temp;
            transform_affine = init_transform_affine.inverse() * transform_affine;
            Eigen::Matrix<double, 4, 4> transform;
            transform = transform_affine.matrix();

            quaternion = transform.block<3,3>(0,0);
            x = transform(0,3);
            y = transform(1,3);
            z = transform(2,3);

            std::ofstream save_chassis_odom(tum_address_+"chassis_odom_wheel.txt", ios::app);
            save_chassis_odom.setf(ios::fixed, ios::floatfield);
            save_chassis_odom.precision(15);
            qx = quaternion.x();
            qy = quaternion.y();
            qz = quaternion.z();
            qw = quaternion.w();
            save_chassis_odom << time/100 << " " << x << " " << y << " " << z << " " << qx << " " << qy << " " << qz << " " << qw << std::endl;
            time++;
            // save_chassis_odom << (double)odom_input.at(i).header().ins_utm_timestamp()/1000000 << " " << x << " " << y << " " << z << " " << qx << " " << qy << " " << qz << " " << qw << std::endl;
            /*------------------------------------*/
        }
    }
    else if (odom_source == "ins_odom")
    {
        for (size_t i = 0; i < odom_input.size(); i++)
        {
            // geometry_msgs::msg::PoseStamped pose_path;
            // pose_path.pose.position.x = odom_input.at(i).odom().position().x();
            // pose_path.pose.position.y = odom_input.at(i).odom().position().y();
            // pose_path.pose.position.z = odom_input.at(i).odom().position().z();
            // pose_path.header.stamp = node_->now();
            // // printf("wheel_time: %d\n",odom_input.at(i).header().sys_timestamp());
            // pose_path.header.frame_id = "baselink";
            // path_pub.poses.push_back(pose_path);
            // publisher_path_->publish(path_pub);
            /*-----------保存tum轨迹文件------------*/

            //起点初始化
            if (init_status)
            {            
                init_transform_affine.setIdentity();
                Eigen::Matrix<double, 3, 3> rotation;
                float qx = odom_input.at(i).odom().pose_quaternion().x();
                float qy = odom_input.at(i).odom().pose_quaternion().y();
                float qz = odom_input.at(i).odom().pose_quaternion().z();
                float qw = odom_input.at(i).odom().pose_quaternion().w();
                Eigen::Quaterniond quaternion(qw,qx,qy,qz);
                rotation = quaternion.toRotationMatrix();
                Eigen::Matrix<double, 3, 1> position;
                float x = odom_input.at(i).odom().position().x();
                float y = odom_input.at(i).odom().position().y();
                float z = odom_input.at(i).odom().position().z();
                position(0,0) = x;
                position(1,0) = y;
                position(2,0) = z;
                Eigen::Matrix<double, 4, 4> transform_temp;
                transform_temp.setIdentity();
                transform_temp.block<3,3>(0,0) = rotation;
                transform_temp.block<3,1>(0,3) = position;
                init_transform_affine = transform_temp;
                init_status = false;
            }
            Eigen::Transform<double, 3, Eigen::Affine> transform_affine;
            transform_affine.setIdentity();
            Eigen::Matrix<double, 3, 3> rotation;
            float qx = odom_input.at(i).odom().pose_quaternion().x();
            float qy = odom_input.at(i).odom().pose_quaternion().y();
            float qz = odom_input.at(i).odom().pose_quaternion().z();
            float qw = odom_input.at(i).odom().pose_quaternion().w();
            Eigen::Quaterniond quaternion(qw,qx,qy,qz);
            rotation = quaternion.toRotationMatrix();
            Eigen::Matrix<double, 3, 1> position;
            float x = odom_input.at(i).odom().position().x();
            float y = odom_input.at(i).odom().position().y();
            float z = odom_input.at(i).odom().position().z();
            position(0,0) = x;
            position(1,0) = y;
            position(2,0) = z;
            Eigen::Matrix<double, 4, 4> transform_temp;
            transform_temp.setIdentity();
            transform_temp.block<3,3>(0,0) = rotation;
            transform_temp.block<3,1>(0,3) = position;
            transform_affine = transform_temp;
            transform_affine = init_transform_affine.inverse() * transform_affine;
            Eigen::Matrix<double, 4, 4> transform;
            transform = transform_affine.matrix();

            quaternion = transform.block<3,3>(0,0);
            x = transform(0,3);
            y = transform(1,3);
            z = transform(2,3);

            std::ofstream save_chassis_odom(tum_address_+"ins_odom.txt", ios::app);
            save_chassis_odom.setf(ios::fixed, ios::floatfield);
            save_chassis_odom.precision(15);
            qx = quaternion.x();
            qy = quaternion.y();
            qz = quaternion.z();
            qw = quaternion.w();
            save_chassis_odom << time/100 << " " << x << " " << y << " " << z << " " << qx << " " << qy << " " << qz << " " << qw << std::endl;
            time++;
            // save_chassis_odom << (double)odom_input.at(i).header().sys_timestamp()/1000000 << " " << x << " " << y << " " << z << " " << qx << " " << qy << " " << qz << " " << qw << std::endl;
            /*------------------------------------*/
        }
    }
}

void OdomPublisher::print_odom(odom::proto::Frame &current_odom_frame)
{
    std::cout << "========================开始打印odom信号========================" << std::endl;
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
    std::cout << "========================本帧odom数据打印完毕========================" << std::endl;
}
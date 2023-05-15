/***
 * @Author       : baixiaobo
 * @Date         : 2022-07-21 14:40:55
 * @LastEditTime : 2022-07-21 16:59:18
 * @Description  : ins里程计，进行坐标转换
 * @FilePath     : /Calmcar_Pilot/04_SWC/OdomMap/ChassisOdomMap/include/ins_odom.hpp
 */
// #pragma once
#pragma once
#include "common_odom.h"

class InsDeadReckoning
{
public:
    InsDeadReckoning(){};
    void DeadReckoningWithIns();
    std::deque<ins_in::proto::Frame> ins_queue;        // CAN输入信号序列
    std::deque<odom::proto::Frame> ins_odom_queue;     // ins里程计序列
    std::deque<odom::proto::Frame> new_ins_odom_queue; // ins里程计序列
    Pose odom_struct;
    void init();
    bool publish_ins_odom(std::string type);
    bool parse_ins_odom(std::deque<odom::proto::Frame> &ins_odom_queue);

private:
    int status_init_ = 0; //初始化状态
    int status_q_ = 0;    //姿态初始化状态
    int status_p_ = 0;    //位置初始化状态

    double utm_x_;
    double utm_y_;
    double utm_z_;
    double first_utm_x_;
    double first_utm_y_;
    double first_utm_z_;
    Eigen::Transform<double, 3, Eigen::Affine> transform_affine;
    Eigen::Transform<double, 3, Eigen::Affine> first_transform_affine;
    std::mutex ins_odom_mutex_;
    std::mutex ins_odom_parse_mutex_;
    uint64_t rolling_counter = 0;
    int save_log_tag_global = 20000;


    std::ofstream save_ins_odom_;

};

void InsDeadReckoning::init()
{
    char name[256] = {0};
    time_t curtime;
    time(&curtime);
    tm  *nowtime = localtime(&curtime);
    int year     = 1900 + nowtime->tm_year;
    int month    = 1 + nowtime->tm_mon;
    int day      = nowtime->tm_mday;
    int hour     = nowtime->tm_hour;
    int min      = nowtime->tm_min;
    int sec      = nowtime->tm_sec;
    system("mkdir -p localization_log/odom_log/txt_log");
    snprintf(name, 256, "%s_%d_%d_%d_%d_%d_%d.%s", "localization_log/odom_log/txt_log/ins_odom", year, month, day, hour, min, sec, "txt");
    save_ins_odom_.open(name, ios::app);
    save_ins_odom_.setf(ios::fixed, ios::floatfield);
    save_ins_odom_.precision(15);
    save_ins_odom_ << "1 time, 2 x, 3 y, 4 z, 5 vx, 6 vy, 7 vz, 8 qx, 9 qy, 10 qz, 11 qw " << std::endl;
}








bool InsDeadReckoning::parse_ins_odom(std::deque<odom::proto::Frame> &ins_odom_queue)
{
    std::lock_guard<std::mutex> lock(ins_odom_parse_mutex_);
    if (new_ins_odom_queue.size() > 0)
    {
        ins_odom_queue.insert(ins_odom_queue.end(), new_ins_odom_queue.begin(), new_ins_odom_queue.end());
        new_ins_odom_queue.clear();
        return true;
    }
    else
    {
        return false;
    }
}
bool InsDeadReckoning::publish_ins_odom(std::string type)
{
    std::lock_guard<std::mutex> lock(ins_odom_mutex_);
    // std::cout << "开始发布 ins odom" << std::endl;
    if (parse_ins_odom(ins_odom_queue))
    {
        for (size_t i = 0; i < ins_odom_queue.size(); i++)
        {
            SerializedData data(ins_odom_queue.at(i).ByteSizeLong());
            ins_odom_queue.at(i).SerializeToArray(data.buffer(), data.size());
            if (Publish(type, std::move(data)))
            {
                // std::cout << "ins odom proto 发布成功! " << std::endl;
            }
        }
        ins_odom_queue.clear();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void InsDeadReckoning::DeadReckoningWithIns()
{
    std::lock_guard<std::mutex> lock(ins_odom_mutex_);
    if (ins_queue.size() == 0)
    {
        // std::cout << "ins信号长度不足为0 ,无法航迹递推" << std::endl;
        return;
    }
    while (ins_queue.size() > 200)
    {
        ins_queue.pop_front();
    }
    LOG_EVERY_N(INFO, save_log_tag_global) << "开始转换ins位姿";
    LOG_EVERY_N(INFO, save_log_tag_global) << "输入的ins序列长度queue_size" << ins_queue.size();
    for (size_t i = 0; i < ins_queue.size(); i++)
    {
        // ins原始数据
        //输入姿态
        double roll    = ins_queue.at(i).ins().orientation().roll();
        double pitch   = ins_queue.at(i).ins().orientation().pitch();
        double heading = ins_queue.at(i).ins().orientation().heading();
        //输入位置
        double longitude = ins_queue.at(i).ins().position().longitude();
        double latitude  = ins_queue.at(i).ins().position().latitude();
        double altitude  = ins_queue.at(i).ins().position().altitude();
        //输入线速度
        double v_x = ins_queue.at(i).ins().speed().north_spd();      //北东地
        double v_y = ins_queue.at(i).ins().speed().east_spd();       //北东地
        double v_z = ins_queue.at(i).ins().speed().to_ground_spd();  //北东地
        if (status_init_ == 0)
        {
            Eigen::Matrix<double, 4, 4> first_transform;
            first_transform.setIdentity();
            Eigen::Matrix<double, 3, 3> rotation;
            Eigen::Vector3d ea(-heading, roll, -pitch);
            rpy_to_rotation<Eigen::Vector3d, Eigen::Matrix<double, 3, 3>>(ea, rotation);
            GC2UTM(longitude, latitude, altitude, utm_x_, utm_y_, utm_z_);
            Eigen::Matrix<double, 3, 1> position;
            position << utm_y_, -utm_x_, utm_z_; //东北天 转 北西天
            first_transform.block<3, 3>(0, 0) = rotation;
            first_transform.block<3, 1>(0, 3) = position;
            first_transform_affine = first_transform;
            status_init_ = 1;
        }
        Eigen::Matrix<double, 4, 4> transform;
        transform.setIdentity();
        Eigen::Matrix<double, 3, 3> rotation;
        Eigen::Vector3d ea(-heading, roll, -pitch);
        rpy_to_rotation<Eigen::Vector3d, Eigen::Matrix<double, 3, 3>>(ea, rotation);
        GC2UTM(longitude, latitude, altitude, utm_x_, utm_y_, utm_z_);
        Eigen::Matrix<double, 3, 1> position;
        position << utm_y_, -utm_x_, utm_z_; //东北天 转 北西天
        transform.block<3, 3>(0, 0) = rotation;
        transform.block<3, 1>(0, 3) = position;
        //第一帧数据初始化，对第一针取逆，使得第一帧数据为全局起点
        transform_affine = transform;
        transform_affine = first_transform_affine.inverse() * transform_affine;
        Eigen::Matrix<double, 3, 3> rotation_now;
        Eigen::Matrix<double, 3, 1> position_now;
        rotation_now = transform_affine.matrix().block<3, 3>(0, 0);
        position_now = transform_affine.matrix().block<3, 1>(0, 3);
        //整理数据
        odom_struct.speed.x = v_x;
        odom_struct.speed.y = -v_y;
        odom_struct.speed.z = -v_z;
        odom_struct.quaternion = rotation_now;
        odom_struct.position.x = position_now(0, 0); 
        odom_struct.position.y = position_now(1, 0); 
        odom_struct.position.z = position_now(2, 0); 
        //发布proto格式ins_odom数据
        odom::proto::Frame current_ins_odom;
        current_ins_odom.mutable_header()->set_odom_id(odom::proto::OdomId::ODOM_INS);
        current_ins_odom.mutable_header()->set_sys_timestamp(ins_queue.at(i).sys_timestamp());           //当前系统时间
        current_ins_odom.mutable_header()->set_rolling_counter(rolling_counter);
        current_ins_odom.mutable_header()->set_frame_id("ins_odom");
        current_ins_odom.mutable_odom()->mutable_position()->set_x(odom_struct.position.x);
        current_ins_odom.mutable_odom()->mutable_position()->set_y(odom_struct.position.y);
        current_ins_odom.mutable_odom()->mutable_position()->set_z(odom_struct.position.z);
        current_ins_odom.mutable_odom()->mutable_pose_quaternion()->set_x(odom_struct.quaternion.x());
        current_ins_odom.mutable_odom()->mutable_pose_quaternion()->set_y(odom_struct.quaternion.y());
        current_ins_odom.mutable_odom()->mutable_pose_quaternion()->set_z(odom_struct.quaternion.z());
        current_ins_odom.mutable_odom()->mutable_pose_quaternion()->set_w(odom_struct.quaternion.w());
        current_ins_odom.mutable_odom()->mutable_linear_speed()->set_x(odom_struct.speed.x);
        current_ins_odom.mutable_odom()->mutable_linear_speed()->set_y(odom_struct.speed.y);
        current_ins_odom.mutable_odom()->mutable_linear_speed()->set_z(odom_struct.speed.z);
        current_ins_odom.mutable_info()->set_status(true);
        current_ins_odom.mutable_info()->set_confidence(1.0);
        new_ins_odom_queue.push_back(current_ins_odom);

        if (test_status)
        {
            save_ins_odom_ << ins_queue.at(i).sys_timestamp() / (double)1000000<<","<<
            odom_struct.position.x<<"," <<
            odom_struct.position.y<<"," <<
            odom_struct.position.z<<"," <<
            odom_struct.speed.x<<"," <<
            odom_struct.speed.y<<"," <<
            odom_struct.speed.z<<"," <<
            odom_struct.quaternion.x()<<"," <<
            odom_struct.quaternion.y()<<"," <<
            odom_struct.quaternion.z()<<"," <<
            odom_struct.quaternion.w()<<"," <<
            std::endl;
        }
    }
    ins_queue.clear();
    return;
}

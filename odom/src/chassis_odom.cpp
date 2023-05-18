/***
 * @Author       : baixiaobo
 * @Date         : 2022-06-28 13:02:42
 * @LastEditTime : 2022-07-10 20:41:56/home/donghao/Documents/project/odom/src/common_odom.h
 * @Description  : 轮速里程计 100Hz
 * @FilePath     : /chassis_odom_map_ws/src/chassis_odom/src/include/wheel_speed_odom.hpp
 */
#pragma once                 //为了避免一个头文件被引用多次，与ifndef类似

#include "common_odom.h"

class ChassisDeadReckoning            //底盘 。。清算
{
public:
    ChassisDeadReckoning(double distance_f2r, double distance_fr2l, double distance_rr2l,
                         double r_rrw, double r_rlw, double r_frw, double r_flw,
                         double front_wheel_weight, double rear_wheel_weight, double steer_transmission_ratio,double yaw_rate_bias);
/*
这段代码是ChassisDeadReckoning类的构造函数。它接受11个参数并将它们赋值给类。
逐步解说:
1. 关键字“public:”表示其他类可以访问此构造函数。
2. 构造函数接受11个参数。
*/
    ChassisDeadReckoning() = default;
    struct Pose delta_dr_transform;                             //增量RT
    struct Pose last_dr_transform;                              //上帧RT
    struct Pose current_dr_transform;                           //本帧RT
    struct Pose result_dr_transform;                            // DR递推结果：相对初始位置世界坐标系下当前帧位置/姿态/速度
    struct VcuVehicleInfo vcu_vehicle_info;                     //底盘信号：时间戳、后轮轮速、角速度yaw/roll,档位，底盘车速
    std::deque<Calmcar::drivers::CHASIS::Chasis> chassis_queue; // CAN输入信号序列
    std::deque<odom::proto::Frame> chassis_odom_queue;          //底盘里程计序列                     proto文件在此处
    std::deque<odom::proto::Frame> new_chassis_odom_queue;      //底盘里程计序列			为何有两个？？？？？？？？？
    void DeadReckoningWithChassis();
    void delta_angle_to_rotation_matrix(Pose &delta_dr_transform);
    bool publish_chassis_odom(std::string type);
    bool parse_chassis_odom(std::deque<odom::proto::Frame> &chassis_odom_queue);
    void init();

private:
    double front_wheel_weight_;       //前轮权重
    double rear_wheel_weight_;        //后轮权重
    int status_chassis_ = 0;          //底盘里程计初始化状态
    double time_stag_ = -1e20;        //初始化轨迹第一帧之前的时间标记，初始化第一帧时间
    double yaw_rate_bias_;             //yaw_rate零偏
    struct VehicleInfo vehicle_info_; //底盘的标定数据，后轮半径，后轮中心距
    void linear_speed_and_angle_speed_compute_();
    std::mutex chassis_odom_mutex_;
    std::mutex chassis_odom_parse_mutex_;
    int save_log_tag_global_ = 20000;
    uint64_t rolling_counter_ = 0;

    std::ofstream save_chassis_odom_;


};

ChassisDeadReckoning::ChassisDeadReckoning(double distance_f2r, double distance_fr2l, double distance_rr2l,
                                           double r_rrw, double r_rlw, double r_frw, double r_flw,
                                           double front_wheel_weight,
                                           double rear_wheel_weight,
                                           double steer_transmission_ratio,
                                           double yaw_rate_bias) : front_wheel_weight_(front_wheel_weight),
                                                                   rear_wheel_weight_(rear_wheel_weight),
                                                                   yaw_rate_bias_(yaw_rate_bias)

{
    vehicle_info_.distance_f2r = distance_f2r;
    vehicle_info_.distance_fr2l = distance_fr2l;
    vehicle_info_.distance_rr2l = distance_rr2l;
    vehicle_info_.r_flw = r_flw;
    vehicle_info_.r_frw = r_frw;
    vehicle_info_.r_rlw = r_rlw;
    vehicle_info_.r_rrw = r_rrw;
    vehicle_info_.steer_transmission_ratio = steer_transmission_ratio;

}
void ChassisDeadReckoning::init()
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
    snprintf(name, 256, "%s_%d_%d_%d_%d_%d_%d.%s", "localization_log/odom_log/txt_log/chassis_odom", year, month, day, hour, min, sec, "txt");
    save_chassis_odom_.open(name, ios::app);
    save_chassis_odom_.setf(ios::fixed, ios::floatfield);
    save_chassis_odom_.precision(15);
    save_chassis_odom_ << "1 time, 2 x, 3 y, 4 z, 5 vx, 6 vy, 7 vz, 8 qx, 9 qy, 10 qz, 11 qw " << std::endl;
}
bool ChassisDeadReckoning::parse_chassis_odom(std::deque<odom::proto::Frame> &chassis_odom_queue)
{
    std::lock_guard<std::mutex> lock(chassis_odom_parse_mutex_);
    if (new_chassis_odom_queue.size() > 0)
    {
        chassis_odom_queue.insert(chassis_odom_queue.end(), new_chassis_odom_queue.begin(), new_chassis_odom_queue.end());
        new_chassis_odom_queue.clear();
        return true;
    }
    else
    {
        return false;
    }
}

bool ChassisDeadReckoning::publish_chassis_odom(std::string type)
{
    std::lock_guard<std::mutex> lock(chassis_odom_mutex_);
    // std::cout << "开始发布chassis odom" << std::endl;
    LOG_EVERY_N(INFO, save_log_tag_global_) << "开始发布chassis odom";
    if (parse_chassis_odom(chassis_odom_queue))
    {
        for (size_t i = 0; i < chassis_odom_queue.size(); i++)
        {
            SerializedData data(chassis_odom_queue.at(i).ByteSizeLong());
            chassis_odom_queue.at(i).SerializeToArray(data.buffer(), data.size());
            if (Publish(type, std::move(data)))
            {
                // std::cout << "chassis_odom_proto发布成功! " << std::endl;
                LOG_EVERY_N(INFO, save_log_tag_global_) << "chassis_odom_proto发布成功!";
            }
        }
        chassis_odom_queue.clear();
    }
}
void ChassisDeadReckoning::linear_speed_and_angle_speed_compute_()
{
    if (vcu_vehicle_info.gear_status == 4 || vcu_vehicle_info.gear_status == 5) //前行档位，x轴向速度为正
    {
        //当前时刻局部坐标系速度计算
        double theta = vcu_vehicle_info.steer_wheel_angle / vehicle_info_.steer_transmission_ratio *
                       M_PI / 180; //前轮与x轴夹角
        double front_wheel_v = (vcu_vehicle_info.front_left_wheel_speed * vehicle_info_.r_flw * cos(abs(theta)) +
                                vcu_vehicle_info.front_right_wheel_speed * vehicle_info_.r_frw * cos(abs(theta))) /
                               2; //前轮x轴线速度平均值
        double rear_wheel_v = (vcu_vehicle_info.rear_left_wheel_speed * vehicle_info_.r_rlw +
                               vcu_vehicle_info.rear_right_wheel_speed * vehicle_info_.r_rrw) /
                              2; //后轮x轴线速度平均值
        current_dr_transform.speed.x = front_wheel_weight_ * front_wheel_v + rear_wheel_weight_ * rear_wheel_v;
        current_dr_transform.speed.y = 0;
        current_dr_transform.speed.z = 0;
        //角速度
        current_dr_transform.angle_speed.roll = 0;
        current_dr_transform.angle_speed.pitch = 0;
        current_dr_transform.angle_speed.yaw = vcu_vehicle_info.yaw_rate - yaw_rate_bias_; //整车综合yaw角速度
    }
    else if (vcu_vehicle_info.gear_status == 2) //后退档位，x轴向速度为负
    {
        //当前时刻局部坐标系速度计算
        double theta = vcu_vehicle_info.steer_wheel_angle / vehicle_info_.steer_transmission_ratio *
                       M_PI / 180; //前轮与x轴夹角
        double front_wheel_v = (vcu_vehicle_info.front_left_wheel_speed * vehicle_info_.r_flw * cos(abs(theta)) +
                                vcu_vehicle_info.front_right_wheel_speed * vehicle_info_.r_frw * cos(abs(theta))) /
                               2; //前轮x轴线速度平均值
        double rear_wheel_v = (vcu_vehicle_info.rear_left_wheel_speed * vehicle_info_.r_rlw +
                               vcu_vehicle_info.rear_right_wheel_speed * vehicle_info_.r_rrw) /
                              2;                                                                                   //后轮x轴线速度平均值
        current_dr_transform.speed.x = -(front_wheel_weight_ * front_wheel_v + rear_wheel_weight_ * rear_wheel_v); //后退为负
        current_dr_transform.speed.y = 0;
        current_dr_transform.speed.z = 0;
        //角速度
        current_dr_transform.angle_speed.roll = 0;
        current_dr_transform.angle_speed.pitch = 0;
        current_dr_transform.angle_speed.yaw = vcu_vehicle_info.yaw_rate - yaw_rate_bias_; //整车综合yaw角速度
    }
    else
    {
        //其他状态为零
        current_dr_transform.speed.x = 0;
        current_dr_transform.speed.y = 0;
        current_dr_transform.speed.z = 0;
        current_dr_transform.angle_speed.roll = 0;
        current_dr_transform.angle_speed.pitch = 0;
        current_dr_transform.angle_speed.yaw = 0;
    }
}

void ChassisDeadReckoning::DeadReckoningWithChassis()
{
    std::lock_guard<std::mutex> lock(chassis_odom_mutex_);
    if (chassis_queue.size() == 0)
    {
        // std::cout << "底盘信号长度不足为0 ,无法航迹递推" << std::endl;
        return;
    }
    while (chassis_queue.size() > 200)
    {
        chassis_queue.pop_front();
    }
    LOG_EVERY_N(INFO, save_log_tag_global_) << "开始底盘航迹递推";
    LOG_EVERY_N(INFO, save_log_tag_global_) << "底盘输入做航迹递推的queue_size:" << chassis_queue.size();
    // std::cout << "底盘输入做航迹递推的queue_size:" << chassis_queue.size() << std::endl;
    for (size_t i = 0; i < chassis_queue.size(); i++)
    {
        if (status_chassis_ == 0) //底盘里程计初始状态
        {
            //----------------------------------------->迭代递推第一帧odom位姿<-----------------------------------------
            //底盘信号
            vcu_vehicle_info.timestamp = (double)chassis_queue.at(i).header().timestamp_sec() / 1000000;
            vcu_vehicle_info.rear_left_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().rl();
            vcu_vehicle_info.rear_right_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().rr();
            vcu_vehicle_info.front_left_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().fl();
            vcu_vehicle_info.front_right_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().fr();
            vcu_vehicle_info.steer_wheel_angle = chassis_queue.at(i).steering_report_65().angle();
            vcu_vehicle_info.gear_status = chassis_queue.at(i).gear_report_67().state();
            vcu_vehicle_info.yaw_rate = chassis_queue.at(i).gyro_report_6c().yaw();
            linear_speed_and_angle_speed_compute_();
            // 发布proto格式chassis_odom数据
            odom::proto::Frame current_chassis_odom;
            current_chassis_odom.mutable_header()->set_odom_id(odom::proto::OdomId::ODOM_CHASSIS);
            current_chassis_odom.mutable_header()->set_ins_utm_timestamp(vcu_vehicle_info.timestamp*1000000);
            current_chassis_odom.mutable_header()->set_sys_timestamp(vcu_vehicle_info.timestamp*1000000);
            current_chassis_odom.mutable_header()->set_rolling_counter(rolling_counter_);
            current_chassis_odom.mutable_header()->set_frame_id("chassis_odom");
            current_chassis_odom.mutable_odom()->mutable_position()->set_x(0);
            current_chassis_odom.mutable_odom()->mutable_position()->set_y(0);
            current_chassis_odom.mutable_odom()->mutable_position()->set_z(0);
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_w(1);
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_x(0);
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_y(0);
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_z(0);
            current_chassis_odom.mutable_odom()->mutable_linear_speed()->set_x(current_dr_transform.speed.x);
            current_chassis_odom.mutable_odom()->mutable_linear_speed()->set_y(current_dr_transform.speed.y);
            current_chassis_odom.mutable_odom()->mutable_linear_speed()->set_z(current_dr_transform.speed.z);
            current_chassis_odom.mutable_info()->set_status(true);
            current_chassis_odom.mutable_info()->set_confidence(1.0);
            new_chassis_odom_queue.push_back(current_chassis_odom);
            //将当前帧系数据保存到last_dr_transform中，参与下次迭代
            last_dr_transform.timestamp = vcu_vehicle_info.timestamp;
            last_dr_transform.angle_speed.roll = current_dr_transform.angle_speed.roll;
            last_dr_transform.angle_speed.pitch = current_dr_transform.angle_speed.pitch;
            last_dr_transform.angle_speed.yaw = current_dr_transform.angle_speed.yaw;
            last_dr_transform.speed.x = current_dr_transform.speed.x;
            last_dr_transform.speed.y = current_dr_transform.speed.y;
            last_dr_transform.speed.z = current_dr_transform.speed.z;
            //将当前帧世界系数据保存到last_dr_transform中，参与下次迭代
            last_dr_transform.position_matrix << 0, 0, 0;
            last_dr_transform.rotation_matrix = Eigen::Matrix3d::Identity();
            last_dr_transform.speed_matrix << current_dr_transform.speed.x, current_dr_transform.speed.y, current_dr_transform.speed.z;
            status_chassis_ = 1;
            if (test_status)
            {
                save_chassis_odom_ << chassis_queue.at(i).header().timestamp_sec() / (double)1000000<<","<<
                0<<"," <<
                0<<"," <<
                0<<"," <<
                current_dr_transform.speed.x<<"," <<
                current_dr_transform.speed.y<<"," <<
                current_dr_transform.speed.z<<"," <<
                0<<"," <<
                0<<"," <<
                0<<"," <<
                1<<"," <<
                std::endl;
            }



        }
        else if (status_chassis_ == 1)
        {
            //----------------------------------------->迭代递推第二帧以及后续帧odom位姿<-----------------------------------------
            //底盘信号
            vcu_vehicle_info.timestamp = chassis_queue.at(i).header().timestamp_sec() / 1000000;
            vcu_vehicle_info.rear_left_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().rl();
            vcu_vehicle_info.rear_right_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().rr();
            vcu_vehicle_info.front_left_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().fl();
            vcu_vehicle_info.front_right_wheel_speed = chassis_queue.at(i).wheelspeed_report_6a().fr();
            vcu_vehicle_info.steer_wheel_angle = chassis_queue.at(i).steering_report_65().angle();
            vcu_vehicle_info.gear_status = chassis_queue.at(i).gear_report_67().state();
            vcu_vehicle_info.yaw_rate = chassis_queue.at(i).gyro_report_6c().yaw();
            linear_speed_and_angle_speed_compute_();
            delta_dr_transform.timestamp = vcu_vehicle_info.timestamp - last_dr_transform.timestamp;
            //======================>姿态DR<======================
            delta_dr_transform.angle.roll = 0;
            delta_dr_transform.angle.pitch = 0;
            delta_dr_transform.angle.yaw = (last_dr_transform.angle_speed.yaw + current_dr_transform.angle_speed.yaw) / 2 * delta_dr_transform.timestamp;
            //瞬时角度增量转换到起始世界坐标系
            // R(起点->t) = R(t-1->t)*R(起点->t-1)
            delta_angle_to_rotation_matrix(delta_dr_transform); //角度增量转成旋转矩阵
            //当前帧世界系下姿态                     瞬时车体姿态增量                      上一帧世界系下的姿态
            result_dr_transform.rotation_matrix = delta_dr_transform.rotation_matrix * last_dr_transform.rotation_matrix;
            result_dr_transform.transform_matrix.block<3, 3>(0, 0) = result_dr_transform.rotation_matrix.block<3, 3>(0, 0);
            Eigen::Quaterniond quaternion(result_dr_transform.rotation_matrix);
            result_dr_transform.quaternion = quaternion;
            result_dr_transform.euler_angle_rpy = result_dr_transform.rotation_matrix.eulerAngles(0, 1, 2) * 180 / M_PI;
            //======================>位置DR<======================
            //瞬时位置增量                     上一帧车体系速度                  当前帧车体系速度
            delta_dr_transform.position.x = (last_dr_transform.speed.x + current_dr_transform.speed.x) / 2 * delta_dr_transform.timestamp;
            delta_dr_transform.position.y = (last_dr_transform.speed.y + current_dr_transform.speed.y) / 2 * delta_dr_transform.timestamp;
            delta_dr_transform.position.z = (last_dr_transform.speed.z + current_dr_transform.speed.z) / 2 * delta_dr_transform.timestamp;
            delta_dr_transform.position_matrix << delta_dr_transform.position.x, delta_dr_transform.position.y, delta_dr_transform.position.z;
            //瞬时位置增量转换到起始世界坐标系
            // 姿态插值，递推位置时，认为位置姿态的变化量为前后两帧之间的均值
            Eigen::Quaterniond qi;
            Eigen::Quaterniond q0;
            Eigen::Quaterniond q;
            qi = result_dr_transform.rotation_matrix;
            q0 = last_dr_transform.rotation_matrix;
            q = q0.slerp(0.5, qi);
            // P(起点->t) = P(起点->t-1)+R*P(t-1->t)，这里的R为上一帧R与本帧R的均值
            // 当前帧世界系下位置                     上一帧世界系位置                      上一帧R与本帧R的均值                  瞬时位置增量
            result_dr_transform.position_matrix = last_dr_transform.position_matrix + last_dr_transform.rotation_matrix * delta_dr_transform.position_matrix;
            result_dr_transform.transform_matrix.block<3, 1>(0, 3) = result_dr_transform.position_matrix.block<3, 1>(0, 0);
            result_dr_transform.position.x = result_dr_transform.position_matrix(0, 0);
            result_dr_transform.position.y = result_dr_transform.position_matrix(1, 0);
            result_dr_transform.position.z = result_dr_transform.position_matrix(2, 0);
            //======================>速度DR<======================
            //瞬时速度增量                 当前帧瞬时速度                    上帧瞬时速度
            delta_dr_transform.speed.x = current_dr_transform.speed.x - last_dr_transform.speed.x;
            delta_dr_transform.speed.y = current_dr_transform.speed.y - last_dr_transform.speed.y;
            delta_dr_transform.speed.z = current_dr_transform.speed.z - last_dr_transform.speed.z;
            delta_dr_transform.speed_matrix << delta_dr_transform.speed.x, delta_dr_transform.speed.y, delta_dr_transform.speed.z;
            //当前帧世界系下速度                     上一帧世界系速度                 上一帧R与本帧R的均值                  瞬时速度增量
            result_dr_transform.speed_matrix = last_dr_transform.speed_matrix + q.toRotationMatrix() * delta_dr_transform.speed_matrix;
            result_dr_transform.speed.x = result_dr_transform.speed_matrix(0, 0);
            result_dr_transform.speed.y = result_dr_transform.speed_matrix(1, 0);
            result_dr_transform.speed.z = result_dr_transform.speed_matrix(2, 0);
            //======================>当前帧数据保存到上一帧状态变量中<======================
            //将当前数据保存到last_dr_transform中，参与下次迭代
            last_dr_transform.timestamp = vcu_vehicle_info.timestamp;
            last_dr_transform.angle_speed.roll = current_dr_transform.angle_speed.roll;
            last_dr_transform.angle_speed.pitch = current_dr_transform.angle_speed.pitch;
            last_dr_transform.angle_speed.yaw = current_dr_transform.angle_speed.yaw;
            last_dr_transform.speed.x = current_dr_transform.speed.x;
            last_dr_transform.speed.y = current_dr_transform.speed.y;
            last_dr_transform.speed.z = current_dr_transform.speed.z;
            last_dr_transform.rotation_matrix = result_dr_transform.rotation_matrix;
            last_dr_transform.position_matrix = result_dr_transform.position_matrix;
            last_dr_transform.speed_matrix = result_dr_transform.speed_matrix;

            // 发布proto格式chassis_odom数据
            odom::proto::Frame current_chassis_odom;
            current_chassis_odom.mutable_header()->set_odom_id(odom::proto::OdomId::ODOM_CHASSIS);
            current_chassis_odom.mutable_header()->set_sys_timestamp(vcu_vehicle_info.timestamp*1000000);
            current_chassis_odom.mutable_header()->set_rolling_counter(rolling_counter_);
            current_chassis_odom.mutable_header()->set_frame_id("chassis_odom");
            current_chassis_odom.mutable_header()->set_ins_utm_timestamp(vcu_vehicle_info.timestamp);
            current_chassis_odom.mutable_odom()->mutable_position()->set_x(result_dr_transform.position.x);
            current_chassis_odom.mutable_odom()->mutable_position()->set_y(result_dr_transform.position.y);
            current_chassis_odom.mutable_odom()->mutable_position()->set_z(result_dr_transform.position.z);
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_w(result_dr_transform.quaternion.w());
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_x(result_dr_transform.quaternion.x());
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_y(result_dr_transform.quaternion.y());
            current_chassis_odom.mutable_odom()->mutable_pose_quaternion()->set_z(result_dr_transform.quaternion.z());
            current_chassis_odom.mutable_odom()->mutable_linear_speed()->set_x(result_dr_transform.speed.x);
            current_chassis_odom.mutable_odom()->mutable_linear_speed()->set_y(result_dr_transform.speed.y);
            current_chassis_odom.mutable_odom()->mutable_linear_speed()->set_z(result_dr_transform.speed.z);
            current_chassis_odom.mutable_info()->set_status(true);
            current_chassis_odom.mutable_info()->set_confidence(1.0);
            new_chassis_odom_queue.push_back(current_chassis_odom);
            

            if (test_status)
            {
                save_chassis_odom_ << chassis_queue.at(i).header().timestamp_sec() / (double)1000000<<","<<
                result_dr_transform.position.x<<"," <<
                result_dr_transform.position.y<<"," <<
                result_dr_transform.position.z<<"," <<
                result_dr_transform.speed.x<<"," <<
                result_dr_transform.speed.y<<"," <<
                result_dr_transform.speed.z<<"," <<
                result_dr_transform.quaternion.x()<<"," <<
                result_dr_transform.quaternion.y()<<"," <<
                result_dr_transform.quaternion.z()<<"," <<
                result_dr_transform.quaternion.w()<<"," <<
                std::endl;
            }

        }
    }
    chassis_queue.clear();
    return;
}
//角度增量转为旋转矩阵
void ChassisDeadReckoning::delta_angle_to_rotation_matrix(Pose &delta_dr_transform)
{
    double cosyaw = cos(delta_dr_transform.angle.yaw);
    double sinyaw = sin(delta_dr_transform.angle.yaw);
    double cospitch = cos(delta_dr_transform.angle.pitch);
    double sinpitch = sin(delta_dr_transform.angle.pitch);
    double cosroll = cos(delta_dr_transform.angle.roll);
    double sinroll = sin(delta_dr_transform.angle.roll);
    delta_dr_transform.rotation_matrix(0, 0) = cosyaw * cospitch;
    delta_dr_transform.rotation_matrix(0, 1) = cosyaw * sinroll * sinpitch - cosroll * sinyaw;
    delta_dr_transform.rotation_matrix(0, 2) = sinyaw * sinroll + cosyaw * cosroll * sinpitch;
    delta_dr_transform.rotation_matrix(1, 0) = cospitch * sinyaw;
    delta_dr_transform.rotation_matrix(1, 1) = cosyaw * cosroll + sinyaw * sinroll * sinpitch;
    delta_dr_transform.rotation_matrix(1, 2) = cosroll * sinyaw * sinpitch - cosyaw * sinroll;
    delta_dr_transform.rotation_matrix(2, 0) = -sinpitch;
    delta_dr_transform.rotation_matrix(2, 1) = cospitch * sinroll;
    delta_dr_transform.rotation_matrix(2, 2) = cosroll * cospitch;
    return;
}

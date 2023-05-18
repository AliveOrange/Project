/*** 
 * @Author       : baixiaobo
 * @Date         : 2022-08-22 14:08:08
 * @LastEditTime : 2022-09-18 16:02:15
 * @Description  : 公共文件
 * @FilePath     : /Calmcar_Pilot/Calmcar_Pilot/04_SWC/CpApOdom/include/common_odom.h
 */
// #ifndef COMMON_HEADER
// #define COMMON_HEADER
#pragma once
#include <glog/logging.h>
#include <dds/dds.h>
#include <iostream>
#include <thread>
#include <deque>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <fcntl.h>
#include <vector>

#include <sys/stat.h>
#include <sys/types.h>

#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigen>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/arena.h>

#include "chasis.pb.h"                           //where is ****************
#include "ins_in.pb.h"
#include "odom.pb.h"

#include <mutex>


#include "yaml-cpp/binary.h"                 //where is  *******************
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/yaml.h"






using namespace std::chrono; 
using namespace calmcar::dds;             //where is **************
using namespace std;

/*全局变量*/
static string chassis_topic;           //底盘topic
static string ins_topic;		//ins——topic
static bool test_status;		//测试状态
// ros参数
static int pub_rate; // ros回调频率
//底盘参数
static double distance_f2r;             //整车轴距      front to rear
static double distance_fr2l;            //前轮中心距	  front right to left
static double distance_rr2l;            //后轮中心距	  rear right to left
static double r_rrw;                    //后右轮半径	  radius_rear right wheel
static double r_rlw;                    //后左轮半径	  radius_rear left wheel
static double r_frw;                    //前右轮半径	  radius_front right wheel
static double r_flw;                    //前左轮半径	  radius_front left wheel
static double front_wheel_weight;       //前轮权重
static double rear_wheel_weight;        //后轮权重
static double steer_transmission_ratio; //方向盘传动比
static double yaw_rate_bias; //方向盘传动比                     ?????what is
std::deque<Calmcar::drivers::CHASIS::Chasis> chassis_buff; //底盘信号序列           命名空间在哪 *************************
/*
这段代码创建了一个名为chassis_buff的队列(双端队列)，该队列存储来自名称空间Calmcar::drivers:: Chasis的Chasis类型的对象。
逐步解说:
1. std:这是c++中的标准名称空间。
2. deque:这是一个来自标准模板库(STL)的容器类，它允许从容器的正面和背面高效地插入和删除元素。
3.Calmcar::drivers::CHASIS:: CHASIS:这是将存储在队列中的对象类型。它来自命名空间Calmcar::drivers::CHASIS。
4. chassis_buff:这是将存储Chasis对象的队列的名称。
*/
std::deque<ins_in::proto::Frame> ins_buff; // ins信号序列
static void param_set()
{
    try
    {
        // YAML::Node config = YAML::LoadFile((std::string)PROJECT_PATH + "/config/config.yaml");
        YAML::Node config = YAML::LoadFile("odom_config.yaml"); 
/*
这段代码加载一个名为“odom_config”的YAML文件。到一个名为config的yaml::Node对象中。
逐步解说:
1. 第一行代码声明了一个名为config的YAML::Node对象。
2. 第二行代码使用YAML::LoadFile()函数加载名为“odom_config”的YAML文件。到配置对象中。
*/                 
        distance_f2r = config["distance_f2r"].as<double>();
/*
This code assigns the value of the "distance_f2r" key from the config map to the double variable distance_f2r.  
 Step-by-step explanation:  
1. The code begins by declaring a double variable called distance_f2r.  
2. It then accesses the config map, which is a data structure that stores key-value pairs.  
3. It looks for the key "distance_f2r" in the map.  
4. If the key is found, it retrieves the associated value and assigns it to the double variable distance_f2r.  
5. The as<double>() function is used to convert the value to a double type.
*/
        distance_fr2l = config["distance_fr2l"].as<double>();
        distance_rr2l = config["distance_rr2l"].as<double>();
        r_rrw = config["r_rrw"].as<double>();
        r_rlw = config["r_rlw"].as<double>();
        r_frw = config["r_frw"].as<double>();
        r_flw = config["r_flw"].as<double>();
        yaw_rate_bias = config["yaw_rate_bias"].as<double>();
        front_wheel_weight = config["front_wheel_weight"].as<double>();
        rear_wheel_weight = config["rear_wheel_weight"].as<double>();
        steer_transmission_ratio = config["steer_transmission_ratio"].as<double>();
        pub_rate = config["pub_rate"].as<int>();
        chassis_topic = config["chassis_topic"].as<std::string>();
        ins_topic = config["ins_topic"].as<std::string>();
        test_status = config["test_status"].as<bool>();
    }
    catch (YAML::BadFile &e)
    {
        std::cout << "配置参数读取错误!" << std::endl;
    }
};

static void GC2UTM(double longitude_, double latitude_, double height_ellipsoid_, double &x, double &y, double &z)
{
    int ProjNo = 0;
    int ZoneWide = 0;
    double longitude1, latitude1, longitude0, latitude0, X0, Y0, xval, yval;
    double a, f, e2, ee, NN, T, C, A, M, iPI;
    iPI = 0.017453293; //=DEGREE_TO_RADIAN;
    ZoneWide = 6;      // 3 DEGREE width

    a = 6378137;
    f = 1 / 298.257223563; // earth ellipse constant

    double longitude = longitude_;
    double latitude = latitude_;
    double altitude = height_ellipsoid_;

    ProjNo = (int)(longitude / ZoneWide);
    longitude0 = ProjNo * ZoneWide + ZoneWide / 2;
    longitude0 = longitude0 * iPI;
    latitude0 = 0;
    longitude1 = longitude * iPI; //经度转换为弧度
    latitude1 = latitude * iPI;   //纬度转换为弧度
    e2 = 2 * f - f * f;
    ee = e2 * (1.0 - e2);
    NN = a / sqrt(1.0 - e2 * sin(latitude1) * sin(latitude1));
    T = tan(latitude1) * tan(latitude1);
    C = ee * cos(latitude1) * cos(latitude1);
    A = (longitude1 - longitude0) * cos(latitude1);
    M = a * ((1 - e2 / 4 - 3 * e2 * e2 / 64 - 5 * e2 * e2 * e2 / 256) * latitude1 - (3 * e2 / 8 + 3 * e2 * e2 / 32 + 45 * e2 * e2 * e2 / 1024) * sin(2 * latitude1) + (15 * e2 * e2 / 256 + 45 * e2 * e2 * e2 / 1024) * sin(4 * latitude1) - (35 * e2 * e2 * e2 / 3072) * sin(6 * latitude1));
    xval = NN * (A + (1 - T + C) * A * A * A / 6 + (5 - 18 * T + T * T + 72 * C - 58 * ee) * A * A * A * A * A / 120);
    yval = M + NN * tan(latitude1) * (A * A / 2 + (5 - T + 9 * C + 4 * C * C) * A * A * A * A / 24 + (61 - 58 * T + T * T + 600 * C - 330 * ee) * A * A * A * A * A * A / 720);
    X0 = 1000000L * (ProjNo + 1) + 500000L;
    Y0 = 0;
    xval = xval + X0;
    yval = yval + Y0;
    x = xval;
    y = yval;
    z = altitude;
}

struct VcuVehicleInfo
{
    double timestamp;               //时间戳
    double rear_left_wheel_speed;   //左后轮角速度，单位rad/s
    double rear_right_wheel_speed;  //右后轮角速度，单位rad/s
    double front_left_wheel_speed;  //左前轮角速度，单位rad/s
    double front_right_wheel_speed; //右前轮角速度，单位rad/s
    double steer_wheel_angle;       //方向盘转角,单位deg
    double roll;                    //底盘roll角
    double pitch;                   //底盘pitch角
    double yaw;                     //底盘yaw角
    double speed;                   //底盘综合自车车速
    double yaw_rate;                //底盘yaw角速度
    double pitch_rate;              //底盘pitch角速度
    double roll_rate;               //底盘roll角速度
    int gear_status;                // 0无，1驻车档，2倒车档，3空档，4前进档，5低速挡
};
struct Position
{
    double x;
    double y;
    double z;
};
struct Angle
{
    double roll;
    double pitch;
    double yaw;
};
struct AngleSpeed
{
    double roll;
    double pitch;
    double yaw;
};
struct Speed
{
    double x;
    double y;
    double z;
    double vehicle;
};
struct VehicleInfo
{
    double steer_transmission_ratio; //方向盘转角与前轮偏转角固定传动比为15.2
    double distance_f2r;             //整车轴距
    double distance_fr2l;            //前轮中心距
    double distance_rr2l;            //后轮中心距
    double r_rrw;                    //后右轮半径
    double r_rlw;                    //后左轮半径
    double r_frw;                    //前右轮半径
    double r_flw;                    //前左轮半径
};
struct Pose
{
    double timestamp;
    Eigen::Matrix<double, 4, 4> transform_matrix; //变换矩阵        c++常规的定义格式
    Eigen::Matrix<double, 3, 3> rotation_matrix;  //旋转矩阵
    Eigen::Matrix<double, 3, 1> position_matrix;  //平移矩阵
    Eigen::Matrix<double, 3, 1> euler_angle_rpy;  //欧拉角
    Eigen::Matrix<double, 3, 1> speed_matrix;     //速度矩阵
    Eigen::Quaterniond quaternion;                //姿态四元数
    struct Position position;                     //位置类
    struct Angle angle;                           //速度类
    struct AngleSpeed angle_speed;                //角速度类
    struct Speed speed;                           //车速
};

/*
    输入角度，
    输出旋转矩阵或者四元数
*/
template <typename T1, typename T2>                 //template主要作用是输入的类型改变也不用改代码
static void rpy_to_rotation(T1 a, T2 &b) //交换数据
{
    a = a * M_PI / 180;                                                   //角度转换为弧度  M_PI是圆周率              1rad=180°/π
    b = Eigen::AngleAxisd(a[0], Eigen::Vector3d::UnitZ()) *              //Vector3d 3*1的double类型的矩阵
        Eigen::AngleAxisd(a[1], Eigen::Vector3d::UnitY()) *              //Eigen::AngleAxis-----将三维旋转表示为围绕任意三维轴的旋转角度   
        Eigen::AngleAxisd(a[2], Eigen::Vector3d::UnitX());
}

// #endif

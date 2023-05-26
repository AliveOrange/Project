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
#include <glog/logging.h> //Google Glog是Google的一个开源库，用于实现应用级别的logging。 
#include <dds/dds.h>      
#include <iostream>
#include <thread>         //生成单个可执行线程，可以在多线程环境中与其他线程并发执行，同时共享相同的地址空间。
#include <deque>
#include <fstream>
#include <iostream>
#include <dirent.h>       // 包含一些遍历目录文件的方法
#include <fcntl.h>        //fcntl.h函数库中的几个常用的原型函数对文件的打开、数据写入、数据读取、关闭文件的操作。
#include <vector>

#include <sys/stat.h>      //函数都是获取文件（普通文件，目录，管道，socket，字符，块（）的属性。
#include <sys/types.h>     //中文名称为基本系统数据类型。在应用程序源文件中包含 <sys/types.h> 以访问 _LP64 和 _ILP32 的定义。

#include <Eigen/Dense>     //Dense：包含了Core、Geometry、LU、Cholesky、SVD、QR、Eigenvalues等模块。
#include <Eigen/Core>      //Core：Matrix和Array类，基础的线性代数运算和数组操作；
#include <Eigen/Eigen>     //Eigen：包含了Dense和Sparse模块。 Sparse：稀疏矩阵的存储和运算

#include <google/protobuf/io/coded_stream.h>  //该文件包含CodedInputStream和CodedOutputStream类，它们分别包装了ZeroCopyInputStream或ZeroCopyOutputStream，并允许您以各种格式读取或写入单个数据块。
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/arena.h>

#include "chasis.pb.h" //其实.pb.h 是 protoc编译器根据 .proto 文件编译生成对应的头文件
#include "ins_in.pb.h"
#include "odom.pb.h"

#include <mutex>       // 在多线程编程中使用互斥体来保护共享数据，防止数据竞争问题的发生。


#include "yaml-cpp/binary.h"
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/yaml.h"






using namespace std::chrono;
using namespace calmcar::dds;
using namespace std;

/*全局变量*/
static string chassis_topic;
static string ins_topic;
static bool test_status;
// ros参数
static int pub_rate; // ros回调频率
//底盘参数
static double distance_f2r;             //整车轴距
static double distance_fr2l;            //前轮中心距
static double distance_rr2l;            //后轮中心距
static double r_rrw;                    //后右轮半径
static double r_rlw;                    //后左轮半径
static double r_frw;                    //前右轮半径
static double r_flw;                    //前左轮半径
static double front_wheel_weight;       //前轮权重
static double rear_wheel_weight;        //后轮权重
static double steer_transmission_ratio; //方向盘传动比
static double yaw_rate_bias; //方向盘传动比
std::deque<Calmcar::drivers::CHASIS::Chasis> chassis_buff; //底盘信号序列
std::deque<ins_in::proto::Frame> ins_buff; // ins信号序列
static void param_set()
{
    try
    {
        // YAML::Node config = YAML::LoadFile((std::string)PROJECT_PATH + "/config/config.yaml");
        YAML::Node config = YAML::LoadFile("odom_config.yaml");
        distance_f2r = config["distance_f2r"].as<double>();
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
    catch (YAML::BadFile &e) //2. YAML::BadFile是被捕获的异常类型，当读取配置文件时发生错误时会引发该异常。 
                             //3. &e是对被捕获的异常的引用，可以用它来访问有关错误的信息
    {
        std::cout << "配置参数读取错误!" << std::endl;
    }
};
//GCJ02坐标系
//为了数据安全和保密，通过地形图非线性保密处理算法（俗称火星加密）加密过的WGS84坐标系，俗称国测局坐标系，或火星坐标系。
//GCJ02坐标系与WGS84坐标系之间的偏差大概在50-700m左右。
//UTM投影
//Universal Transverse Mercator，通用横轴墨卡托投影，是一种国际标准化的地图投影法。使用笛卡尔坐标系，标记南纬80°至北纬84°之间的所有位置，它的坐标基础是WGS84坐标系，因为UTM是一种分度带投影，所以不同经度区间的UTM投影坐标系的EPSG编码不同。
//UTM采用网格编码，每个网格的编码经度在前，纬度在后。
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
    Eigen::Matrix<double, 4, 4> transform_matrix; //变换矩阵
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
    使用Eigen库中的AngleAxisd类，将一个旋转角度和旋转轴作为输入，并返回一个Rotation Matrix作为输出。
    其中，a[0]代表旋转角度，Eigen::Vector3d::UnitZ()代表z轴旋转。
*/
template <typename T1, typename T2>
static void rpy_to_rotation(T1 a, T2 &b) //交换数据
{
    a = a * M_PI / 180;
    b = Eigen::AngleAxisd(a[0], Eigen::Vector3d::UnitZ()) *
        Eigen::AngleAxisd(a[1], Eigen::Vector3d::UnitY()) *
        Eigen::AngleAxisd(a[2], Eigen::Vector3d::UnitX());
}

// #endif

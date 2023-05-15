/***
 * @Author       : baixiaobo
 * @Date         : 2022-07-25 16:32:25
 * @LastEditTime : 2022-07-25 17:00:04
 * @Description  : 接收ins和底盘信号,迭代递推odom
 * @FilePath     : /Calmcar_Pilot/04_SWC/Odom/ChassisOdom/src/chassis_odom.cpp
 */
#include "common_odom.h"
#include "chassis_odom_wheel.cpp"
#include "chassis_odom.cpp"
#include "chassis_odom_processed_frame2frame.cpp"
#include "chassis_sub.cpp"
#include "ins_odom.cpp"
#include "ins_sub.cpp"
#include "odom_sub.cpp"
int main(int argc, char **argv)
{
    param_set();
    //google_log
    google::InitGoogleLogging(argv[0]);
    FLAGS_alsologtostderr = true;
    system("mkdir -p localization_log/odom_log/glog");
    FLAGS_log_dir = "localization_log/odom_log/glog";
    FLAGS_max_log_size = 1000000;
    //chassis_sub
    std::shared_ptr<ChassisSubscriber> chassis_sub = std::make_shared<ChassisSubscriber>(chassis_topic);
    std::thread sub_chassis_thread; // 订阅chassis信号线程
    sub_chassis_thread = std::thread(&ChassisSubscriber::subscribe_callback, chassis_sub, chassis_sub->get_chassis_topic());
    sub_chassis_thread.detach();
    //chassis 航位推算算法1：chassis_yawrate
    std::shared_ptr<ChassisDeadReckoning> chassis_odom = std::make_shared<ChassisDeadReckoning>(distance_f2r, distance_fr2l, distance_rr2l,
                                                                                                r_rrw, r_rlw, r_frw, r_flw,
                                                                                                front_wheel_weight, rear_wheel_weight,
                                                                                                steer_transmission_ratio,yaw_rate_bias);
    //chassis 航位推算算法1-1：chassis_yawrate_处理帧与帧投影关系
    std::shared_ptr<ChassisDeadReckoningFrame2Frame> chassis_odom_processed_frame2frame = std::make_shared<ChassisDeadReckoningFrame2Frame>(distance_f2r, distance_fr2l, distance_rr2l,
                                                                                                r_rrw, r_rlw, r_frw, r_flw,
                                                                                                front_wheel_weight, rear_wheel_weight,
                                                                                                steer_transmission_ratio,yaw_rate_bias);
    //chassis 航位推算算法2：chassis_wheel_speed
    std::shared_ptr<ChassisDeadReckoningWheel> chassis_odom_wheel = std::make_shared<ChassisDeadReckoningWheel>(distance_f2r, distance_fr2l, distance_rr2l,
                                                                                                                r_rrw, r_rlw, r_frw, r_flw,
                                                                                                                front_wheel_weight, rear_wheel_weight,
                                                                                                                steer_transmission_ratio);
    //航位推算对比源：ins
    std::shared_ptr<InsSubscriber>    ins_sub  = std::make_shared<InsSubscriber>(ins_topic);
    std::shared_ptr<InsDeadReckoning> ins_odom = std::make_shared<InsDeadReckoning>();
    if (test_status)
    {
        std::thread sub_ins_thread; // 订阅ins信号线程
        sub_ins_thread = std::thread(&InsSubscriber::subscribe_callback, ins_sub, ins_sub->get_ins_topic());
        sub_ins_thread.detach();
    }
    //初始化日志系统
    chassis_odom->init();
    chassis_odom_wheel->init();
    chassis_odom_processed_frame2frame->init();
    ins_odom->init();
    //开始轨迹迭代
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / pub_rate));
        //构建里程计
        if (chassis_sub->parse_chassis(chassis_buff))
        {
            // yaw_rate推姿态，轮速推位置，同时处理两帧之间的投影关系
            chassis_odom_processed_frame2frame->chassis_queue.insert(chassis_odom_processed_frame2frame->chassis_queue.end(), chassis_buff.begin(), chassis_buff.end());
            chassis_odom_processed_frame2frame->DeadReckoningWithChassis();
            chassis_odom_processed_frame2frame->publish_chassis_odom("chassis_odom");
            // 轮速推姿态，轮速推位置
            if (test_status)
            {
                // yaw_rate推姿态，轮速推位置
                chassis_odom->chassis_queue.insert(chassis_odom->chassis_queue.end(), chassis_buff.begin(), chassis_buff.end());
                chassis_odom->DeadReckoningWithChassis();
                chassis_odom->publish_chassis_odom("chassis_odom_unprocessed_frame2frame");
                // 轮速推姿态
                chassis_odom_wheel->chassis_queue.insert(chassis_odom_wheel->chassis_queue.end(), chassis_buff.begin(), chassis_buff.end());
                chassis_odom_wheel->DeadReckoningWithChassis();
                chassis_odom_wheel->publish_chassis_odom("chassis_odom_wheel");
            }
            chassis_buff.clear();
        }
        // 构建里程计
        if (test_status)
        {
            if (ins_sub->parse_ins(ins_buff))
            {
                ins_odom->ins_queue.insert(ins_odom->ins_queue.end(), ins_buff.begin(), ins_buff.end());
                ins_odom->DeadReckoningWithIns(); //坐标变换
                ins_odom->publish_ins_odom("ins_odom");
                ins_buff.clear();
            }
        }
    }
    google::ShutdownGoogleLogging();
}

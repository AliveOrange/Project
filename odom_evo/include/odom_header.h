/*** 
 * @Author       : baixiaobo
 * @Date         : 2022-08-23 15:29:09
 * @LastEditTime : 2022-09-30 08:37:58
 * @Description  : 
 * @FilePath     : /odom_evo/include/odom_header.h
 */

#ifndef CHASSIS_ODOM_HEADER
#define CHASSIS_ODOM_HEADER

#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <dirent.h>
#include <chrono>
#include <memory>
#include <thread>
#include <dds/dds.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>

#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigen>

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/opencv.hpp>

#include <pcl-1.10/pcl/conversions.h>
#include <pcl-1.10/pcl/PCLPointCloud2.h>
#include <pcl-1.10/pcl/point_types.h>
#include <pcl-1.10/pcl/sample_consensus/ransac.h>
#include <pcl-1.10/pcl/filters/filter.h>
#include <pcl-1.10/pcl/filters/extract_indices.h>
#include <pcl-1.10/pcl/filters/voxel_grid.h>
#include <pcl-1.10/pcl/filters/impl/voxel_grid.hpp>
#include <pcl-1.10/pcl/common/io.h>
#include <pcl-1.10/pcl/io/io.h>
#include <pcl-1.10/pcl/io/pcd_io.h>
#include <pcl-1.10/pcl/point_cloud.h>
#include <pcl-1.10/pcl/common/transforms.h>
#include <pcl-1.10/pcl/impl/pcl_base.hpp>
#include <pcl-1.10/pcl/pcl_base.h>

#include <pcl_conversions/pcl_conversions.h>

#include "sensor_msgs/msg/compressed_image.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "nav_msgs/msg/path.hpp""
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/byte.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>

#include "rclcpp/rclcpp.hpp"

// #include "yaml-cpp/binary.h"
// #include "yaml-cpp/node/node.h"
// #include <yaml-cpp/yaml.h>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

#include "chasis.pb.h"
#include "ins_in.pb.h"
#include "odom.pb.h"
#include "../install/calmcar/include/calmcar/msg/binrary_data.hpp"

using namespace Eigen;
using namespace std;
using namespace cv;

#endif

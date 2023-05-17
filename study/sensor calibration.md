## calib.cpp代码
## main( int argc, char* argv[], char **env ) 
是UNIX、Linux以及Mac OS操作系统中C/C++的main函数标准写法，并且是血统最纯正的main函数写法。

在如今的Visual Studio编译器中，main()函数带有参数argc和argv或者不带，即无论是否在函数体中使用argc和argv，返回值为void或不为void，都是合法的。
一、argc、argv的具体含义 
argc和argv参数在用命令行编译程序时有用。main( int argc, char* argv[], char \**env ) 中 
第一个参数，int型的argc，为整型，用来统计程序运行时发送给main函数的命令行参数的个数，在VS中默认值为1。 
第二个参数，char*型的argv[]，为字符串数组，用来存放指向的字符串参数的指针数组，每一个元素指向一个参数。各成员含义如下： 
argv[0]指向程序运行的全路径名 
argv[1]指向在DOS命令行中执行程序名后的第一个字符串 
argv[2]指向执行程序名后的第二个字符串 
argv[3]指向执行程序名后的第三个字符串 
argv[argc]为NULL 
第三个参数，char\**型的env，为字符串数组。env[]的每一个元素都包含ENVVAR=value形式的字符串，其中ENVVAR为环境变量，value为其对应的值。平时使用到的比较少。

## ros::init()初始化函数
一、定义介绍

  ros::init()函数是ros程序调用的第一个函数，用于初始化ros节点。它有三个重载，一般使用的长这样：

ros::init(argc, argv, "abc_node");/*此处是省略了第四个参数，一般用的时
我们大部分情况下也会省略第四个参数*/
```c
ros::init(argc, argv, "abc_node");/*此处是省略了第四个参数，一般用的时
我们大部分情况下也会省略第四个参数*/

```
  ros::init()函数的声明如下（ros::init()函数的声明源码在./src/ros_comm/roscpp/include/ros/init.h文件中）：
```c
void ros::init	(	int & 	argc,
					char ** 	argv,
					const std::string & 	name,
					uint32_t 	options = 0 
)		
```
ros::init()的参数分别是：
argc：remapping参数的个数
argv：remapping参数的列表
name：节点名，必须是一个基本名称，不能包含命名空间
options：[可选]用于启动节点的选项（ros::init_options中的一组位标志）

调用ros::init()函数后，它会调用五个函数：
network::init(remappings);
master::init(remappings);
this_node::init(name, remappings, options);
file_log::init(remappings);
param::init(remappings);
二、功能作用

  初始化ros节点
三、使用方法

  在代码中使用此函数即可
## Setlocale()
是一个计算机函数，功能是用来配置地域的信息，设置当前程序使用的本地化信息。

## ros::NodeHandle nh
是ros中的一个节点句柄，用于与ROS系统中的节点进行通信和交互。

## nh.param
利用NodeHandle来进行launch文件中的数据获取
```c++
**nh.param<传入的参数类型>(launch文件中的参数名称, 程序中接受该参数的变量名称，该参数默认值）**
```
## int8_t， uint8_t；int16_t， uint16_t；int32_t， uint32_t
1，数据类型中都带有_t, _t 表示这些数据类型是通过typedef定义的，而不是新的数据类型。也就是说，它们其实是我们已知的类型的别名。
2，8，16，32又是什么意思？
这些数字都是位数，即，使用多少位来存储数据，一个字节8位，其中因为数字有正负之粉，对应有符号（signed，最高位为0，表示正数）和无符号（unsigned，最高位为1，表示负数），所以表示的范围不一样，但是因为位数一致，故表示的个数是一样的。
比如使用16位，也就是两个字节来存储
可以是 typedef signed short int int16_t;//给有符号短整型short int，取别名**int16_t**
也可以是 typedef unsigned short int uint16_t;//给无符号短整型short int，取别名为**uint16_t**
uint16_t 表示数据范围则是0 ~65535。
int16_t 表示数据范围为-32768~32767
表示的个数是一样的：65536=2的16次方
## SLAM 
(simultaneous localization and mapping),也称为CML (Concurrent Mapping and Localization), 即时定位与地图构建，或并发建图与定位。
## Eigen编译_Eigen向量化_内存对齐 
**EIGEN_MAKE_ALIGNED_OPERATOR_NEW**

## POINT_CLOUD_REGISTER_POINT_STRUCT????

## PCL
（Point Cloud Library）
是专注于点云操作处理的开源算法库，对于从事三维点云数据处理的道友来说是工作学习中必不可少的工具

为了简化开发，PCL被分成一系列更小的代码库，这些代码库可以单独编译。这种模块化对于将PCL分布在具有较少计算或大小限制的平台上非常重要，这些模块就像是一把瑞士军刀上的各个小工具。
```#include <iostream>          //标准C++库中的输入输出的头文件```
```#include <pcl/point_types.h> //PCL中支持的点类型的头文件```
```$(find lidar_car_calib)/result/```搜索功能包的指令
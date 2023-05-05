cmake_minimum_required(VERSION 3.5)
project(odom_map_tum)
add_definitions(-DPROJECT_PATH="${PROJECT_SOURCE_DIR}")
set(CMAKE_BUILD_TYPE RELEASE)
add_definitions(-O3)
add_compile_options(-Wall)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# set(CMAKE_CXX_FLAG -lboost_system -lboost_filesystem)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(NOT DEFINED ENV{AMENT_PREFIX_PATH})
  message(FATAL_ERROR "Not defined:AMENT_PREFIX_PATH "
    "Please source ROS2 environment")
endif()

set(CMAKE_PREFIX_PATH
  ${CMAKE_PREFIX_PATH}
  $ENV{AMENT_PREFIX_PATH})

# find dependencies
include(FindProtobuf)
find_package(Protobuf REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(PCL REQUIRED QUIET)
find_package(OpenCV)
find_package(nav_msgs REQUIRED)

# find_package(Threads REQUIRED)
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(std_msgs REQUIRED)
# find_package(sensor_msgs REQUIRED)
# find_package(PCL REQUIRED QUIET)
# find_package(OpenCV)
# find_package(yaml-cpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(Boost REQUIRED) # COMPONENTS system)

# find_package(Eigen3 REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/driver/rs_driver/src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/proto)
include_directories(${PCL_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})

# include_directories(${JSONCPP_INCLUDE_DIRS})
# include_directories(${EIGEN3_INCLUDE_DIR})
link_libraries(${JSONCPP_LIBRARIES})

FILE(GLOB_RECURSE PROJECT_SOURCES "proto/*.cc") # "proto/*.cc"

# SET(LIBPROTOBUF /home/baixiaobo/work/Calmcar_Pilot_fusionbackup0626/Calmcar_Pilot_fusion/Calmcar_Pilot/04_SWC/ToEHP/PositionToEHP/lib/libprotobuf-lite.so.17)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/glog)
# include_directories(/home/baixiaobo/work/Calmcar_Pilot_fusionbackup0626/Calmcar_Pilot_fusion/Calmcar_Pilot/08_interfaces/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/install/calmcar/include)

# include_directories(/home/baixiaobo/work/Calmcar_Pilot_fusionbackup0626/Calmcar_Pilot_fusion/Calmcar_Pilot/04_SWC/OdomMap/ChassisOdomMap/install/calmcar/include/calmcar/msg)

# add_executable(lidar src/main.cpp src/pointcloudPublisher.cpp src/lidarprocess.cpp)
# ament_target_dependencies(lidar rclcpp std_msgs sensor_msgs)
# target_link_libraries (lidar pthread boost_system pcap)
add_executable(odom_map_tum src/local_map_on_odom.cpp ${PROJECT_SOURCES})
ament_target_dependencies(odom_map_tum
  rclcpp
  std_msgs
  sensor_msgs
  nav_msgs
  geometry_msgs
  tf2
  tf2_ros)
target_link_libraries(odom_map_tum

  # ${LIBPROTOBUF}
  ${PROTOBUF_LIBRARY}
  ${OpenCV_LIBS}
  ${PCL_LIBRARIES}
  # yaml-cpp
  # libyaml-cpp.so

  # ${jsoncpp_LIBRARIES}
)

set(CMAKE_PREFIX_PATH
  ${CMAKE_PREFIX_PATH}
  ${CMAKE_CURRENT_LIST_DIR}/install/calmcar
)
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_LIST_DIR}/install/calmcar
)
find_package(calmcar REQUIRED)
ament_export_dependencies(calmcar)
target_include_directories(${PROJECT_NAME} SYSTEM
  PRIVATE
  ${rclcpp_INCLUDE_DIRS}
  ${calmcar_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME}

  # PRIVATE
  ${rclcpp_LIBRARIES}
  ${calmcar_LIBRARIES}
)
target_link_options(${PROJECT_NAME}
  PRIVATE ${calmcar_LINK_FLAGS}
)

install(TARGETS

  # lidar
  # listener
  odom_map_tum
  DESTINATION lib/${PROJECT_NAME})

ament_package()

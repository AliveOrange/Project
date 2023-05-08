http://172.18.1.11/CpApPosToEHP/CpApOdom.git

**export命令可用于显示或设置环境变量**

实例1：显示当前所有的环境变量
```s
$ export -p
```
实例2：设置环境变量
```s
$ export PATH=$PATH:/home/dabai/test/bin
```

##vpn
https://v2raya.org/

## riviz
\#启动rviz
cbp_dh run

cd /home/donghao/tools_v4.6/tools
export ROS_DOMAIN_ID=12
\# ./boot_all.sh
./boot_all_offline.sh


## rviz不显示rosbag文件,重启docker 
cdp_dh remove
cdp_dh run


## 缺少yaml文件
ros2 bag reindex rosbag2_2023_03_29-14_27_34/ sqlite3  

##启动RoadTestAnalysis
cd /home/alexdong/Desktop/data/LUILogger2.1-ubuntu20.04-5964.11.11-01/LUILogger2.1-ubuntu2004-5964.11.10-02
./RoadTestAnalysis

## 查看rosbag包的通道
ros2 bag info  *.db3


## pip加快安装（解决pip安装网络不可达）
sudo pip3 install pandas -i https://pypi.mirrors.ustc.edu.cn/simple/


## linux卸载软件并删除配置文件
sudo apt-get remove  --purge  appname

## 根目录修复工具
sudo add-apt-repository ppa:yannubuntu/boot-repair && sudo apt update
sudo apt install -y boot-repair && boot-repair

## ubuntu换源
deb https://mirrors.ustc.edu.cn/ubuntu/ focal main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ focal-security main restricted universe multiverse

## docker网段冲突了怎么办

最近ssh登陆公司远程服务器，突然登不进去，后经排查是因为有个docker容器的网段和公司的网段冲突了，导致登陆不上去。
如何解决
docker默认网段是172.17，和公司的网段冲突，因此解决的办法其实也挺简单的，要么换公司网段，要么换docker网段，是个正常人都会选择换docker网段

解决方案
方案一：不改docker网段，创建不和公司网段冲突的docker子网段
docker network create --driver=bridge --subnet=192.161.0.0/16 monitor_net
运行容器时指定

docker run -it --name <容器名> ---network monitor_net  <镜像名
在docker-compose同样通过networks指定，形如下

version: '3'
networks:
   monitor:
   #使用已经存在的网络
     external:
       name: monitor_net  

services:
    prometheus:
        image: prom/prometheus
        container_name: prometheus
        hostname: prometheus
        privileged: true
        restart: always
        volumes:
            - /usr/local/src/config/prometheus.yml:/etc/prometheus/prometheus.yml
            - /usr/local/src/config/node_down.yml:/etc/prometheus/node_down.yml
        ports:
            - "9091:9090"
        networks:
            - monitor
        links:
            - alertmanager
            - node-exporter
### 方案二：修改docker默认网段
1、停止docker
```
systemctl stop docker
```
2、删除原有网桥
```
ip link del docker0 down
```
3、
```
vim /etc/docker/daemon.json
```
添加如下内容
"bip":"192.161.20.1/24"
如果没有daemon.json文件，则新建

文件内容形如下
```
{
  "registry-mirrors": ["https://zq2cvqfe.mirror.aliyuncs.com"],
"insecure-registries":["192.168.1.30:5002"],
"bip":"192.161.20.1/24"
}
```
4、重启docker服务
```
systemctl restart docker
```
5、通过ifconfig 查看docker网段是否已经变更

总结
==安装docker时，记得修改docker默认，以免和公司的网段冲突==
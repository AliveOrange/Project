---
html:
  toc: true
---
https://www.bilibili.com/video/BV1ty4y1q72g/?p=37&spm_id_from=pageDriver&vd_source=d7bcde14a5aba250f0f145435d887db0
内容编码 utf-8
## 优先和最后执行线程组
## 线程组
线程数 （访问人数）
循环次数（数字或永远）
持续时间（秒）
自动延迟（秒）
## http请求默认值
配置http请求默认值
## 新增接口
如果需要新增数据：设置http信息头管理器
## 参数化
### 用户定义的变量
添加-配置元件-用户定义的变量
### csv批量添加
添加-配置元件-csv数据文件。。
## 用户参数
http请求右键添加
## 计算器函数
函数助手动画框-选择-_counter
## 随机数函数
__Random，用法和上面类似
## 时间函数
__time  （默认显示的是时间戳可更改）
## 直连数据库
不添加http；
添加jar包
JDBC Connection Configuration
添加JDBC请求；
## 断言
http请求右键添加断言-响应断言
![](images/2023-05-04-11-06-52.png)
响应文本断言和响应代码断言常用
## 大小断言和持续时间断言
持续时间断言用来判断响应时间长短

## if逻辑控制器
![](images/2023-05-04-11-19-57.png)
控制器生效必须是控制器与请求为父子关系
![](images/2023-05-04-11-24-07.png)
## for each逻辑控制器
![](images/2023-05-04-11-25-15.png)
控制器生效必须是控制器与请求为父子关系
![](images/2023-05-04-11-30-44.png)
![](images/2023-05-04-11-29-39.png)
## 循环逻辑控制器
主要是为了让不同的http单独控制循环次数，比在线程组里控制更加灵活。
![](images/2023-05-04-11-33-04.png)
## 关联-xpath提取器
![](images/2023-05-04-11-35-33.png)
主要是提取html格式
## 关联-正则表达式提取器
http请求右键添加后置提取器
给它一个模板 
![](images/2023-05-04-11-49-40.png)
![](images/2023-05-04-11-47-52.png)
## 跨越线程组传值
提取器 取样器
## 性能测试
模拟各种正常的、峰值的测试环境、检测程序的各项性能指标是否达标。
### 高并发 
![](images/2023-05-04-13-37-32.png)
同步计时器设置模拟用户组的数量
![](images/2023-05-04-13-41-15.png)
超时时间（等待时间）不要设置为0，为了让程序不要卡死；
![](images/2023-05-04-13-46-01.png)
### 高频率
QPS每秒钟查询数
![](images/2023-05-04-13-49-35.png)
![](images/2023-05-04-13-53-15.png)
### 分布式
![](images/2023-05-04-13-55-10.png)
![](images/2023-05-04-13-55-57.png)
## 总结
![](images/2023-05-04-14-01-29.png)
## 实战简介
![](images/2023-05-04-14-02-16.png)
根据原始api文档提取三要素 路径 方法 数据结构
![](images/2023-05-04-14-06-52.png)
测试用例准备
## 接口功能测试
![](images/2023-05-04-14-17-54.png)
![](images/2023-05-04-14-19-37.png)
![](images/2023-05-04-14-20-54.png)

## 生成图形化报告
![](images/2023-05-04-14-25-52.png)
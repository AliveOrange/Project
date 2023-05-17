终端执行
```
make
```
会自动寻找并执行makefile文件
makefile在不同系统上会出现使用障碍，cmake解决了这个问题
CMakeList.txt是cmake程序要读的文件
执行cmake会自动生成适合当前系统的makefile文件
```
cmake .
```
在bash中，$( )与` `（反引号）都是用来作命令替换的。
命令替换与变量替换差不多，都是用来重组命令行的，先完成引号里的命令行，然后将其结果替换出来，再重组成新的命令行。

exp 1
```
[root@localhost ~]# echo today is $(date "+%Y-%m-%d")
today is 2017-11-07
[root@localhost ~]# echo today is `date "+%Y-%m-%d"`
today is 2017-11-07
```

${ }变量替换

一般情况下，$var与${var}是没有区别的，但是用${ }会比较精确的界定变量名称的范围

exp 1
```
[root@localhost ~]# A=Linux
[root@localhost ~]# echo $AB    #表示变量AB

[root@localhost ~]# echo ${A}B    #表示变量A后连接着B
LinuxB
```


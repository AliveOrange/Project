
# Git基础入门

## 一、安装与配置

### 1.下载与安装:

https://git-scm.com/download/


### 2.使用入口

win：右键菜单—git bash

linux：终端窗口


### 3.基础配置

a.首次使用添加身份说明，使用以下两个命令：
```shall
git config --global user.name "你的昵称"
git config --global user.email 邮箱@example.com
```

b.创建仓库

①linux在项目文件夹下使用终端输入
```shall
git init
```
②使用他人项目创建仓库

clone项目
```
git clone <项目url>
```

## 二、状态与提交版本

### 1.跟踪

a.跟踪文件
```
git add <name>
```
b.跟踪当前目录
```
git add .
```

### 2.取消跟踪

a.rm删除
```
git rm <name>
```
b.保留但不跟踪
```
git rm-cache <name>
```

### 3.文件状态修改

a.将修改文件缓存
```
git add <file-name>
```
b.取消缓存
```
git reset HEAD <name>
```
c.提交缓存的修改
```
git commit
```

d.文件状态总结

一个文件的四个状态

e.git commit 具体操作

commit 操作
```
git commit  # 进入提交界面, 
```
按" i "键进入输入模式后输入本次提交详情,

然后esc退出编辑模式, 按" : "进入命令栏, 输入"wq"保存并退出.

```
git commit -m  <你对提交内容的描述>
```

commit 的简洁操作
```
git commit -a    #连带未暂存文件一起提交
```
```    
git commit -am '提交描述'
```

取消本次提交
```
git reset head~ --soft  #使用该命令取消本次提交, 但是首次提交不可
```

f.查看文件状态

```
git status
```
    红色代表 已修改, 未暂存

    绿色代表 已暂存

    提交后, 则不显示

更详细地查询修改,详细查看文件的第几行第几个字母被修改了
```
git diff
```
查看提交历史信息
```
git log
```
查看所有分支的提交
```
git log --all
```
图形化查看所有分支的提交
```
git log --all --graph
```
图形化界面查看(结合分支)
```
git log--graph
```

## 三、远程仓库

### 1.新建远程仓库

本地添加远程仓库

```
git remote add origin <远程仓库链接>
```
查看本地仓库当前链接的远程仓库地址
```
git remote -v
```
修改本地仓库的远程链接地址为新仓库地址
```
git remote set-url origin git_url_new
```

### 2.重命名仓库
```
git remote rename <目标仓库名> <修改内容>
```

### 3.本地代码推送到远程仓库
```
git push 仓库名 分支名(master)
```

b.GitHub已禁止使用用户名与密码验证

①使用token令牌验证
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

②简单方式:ssh鉴权
```
ssh-keygen -t rsa
```
会在根目录自动生成.ssh文件夹，复制里面的id_rsa.pub内容到github-setting-SSH and GPG keys-New SSH key
验证 
```
ssh -T git@github.com
```

## 四、分支

### 1.分支的概念


### 2.经典git模型


### 3.创建分支

创建分支
```
git branch 分支名
```

新建并切换到该分支
```
git checkout -b 分支名
```

### 4.查看分支
```
git branch --list

```
### 5.切换分支

```
git checkout 分支名
```

## 五、分支合并


### 1.无冲突合并

```
git merge <要合并的分支>      #(合并到当前分支上)
```

### 2.分支冲突 merge conflict


将 分支2 合并到 master分支 时, 与 分支1 冲突了. 原因是 分支1 和 分支2 修改了同一处内容.


解决冲突
```
git status  #查看哪里有冲突
```
vi 到冲突文件中, 选择一个分支的内容保留下来, 保存退出

git add <文件名>

git commit -m '提交描述'

git log --all --graph #查看合并状态


##六、推拉与远程跟踪分支 

### 1.推送
```
git push 仓库名 分支名
```
或者
```
git push -u 仓库名 分支名
```
第一次使用 -u 指定推送目标后, 此后可直接使用git push

注意：在我将本地代码提交至远程仓库时，报如下错误：

![](https://img-blog.csdnimg.cn/c55679a6ba55465f91a72cbfdbb029bb.png)

之所以出现这个原因，是因为我在线上远程仓库生成、编辑了README.md文件，而本地代码文件中不包含它，所以线上线下就对不上了报错。

解决办法：将线上、线下代码进行合并：
```
git pull --rebase origin master
```

### 2.拉取

拉取远程分支
```
git fetch
```
远程代码和本地合并
```
git merge origin/master # 合并远程这个分支的代码到本地当前分支
```
远程分支本地化
```
git checkout 远程分支  #其实是创建了一个远程分支的跟踪
```
```
git checkout -b 本地分支名 远程分支 #比较正宗的远程分支本地化写法
```
```
git checkout --track 远程分支   #第三种写法
```

## 七、贮藏功能
### 1.储存
代码写到一半有事儿来了, 要切换到其他分支是不允许的, 提交写了一半的代码也不太好，可以把当前分支修改的东西储藏起来再切换.

```
git stash
```
切换回分支后恢复贮存内容
```
git stash apply
```

### 2.多次存储


a.回看存储记录
```
git stash list
```
b.恢复指定记录
```
git stash apply stash@{记录号}
```
c.恢复并删除记录

①恢复并删除最近一次记录
```
git stash pop
```
②删除指定记录
```
git stash drop @stash{记录号}
```

### 八、重置与变基

1.reset(重置)

a.head

head~ 的含义

	head: 当前的提交

	head~: 上次的提交

	head~2: 倒数第二次的提交

b. --soft

--soft 的含义

	仅取消commit操作, 把修改文件暂存.

	如果不加 --soft 则表示恢复到暂存前, 修改的内容是存在的.

c. --hard

--hard 的含义

	取消暂存, 还取消修改内容, 彻底回到上次提交的状态.

	不推荐使用, 可能丢失数据.


2.rebase(变基)

变基(搬家)

a.将B分支的修改移动到A分支


git rebase
﻿

	git checkout B

	git rebase A


b.注意事项


27:04
注意远程分支

注意他人在远程分支二次开发时, 审慎使用变基


c.交互式操作

rebase -i

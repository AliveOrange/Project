## if name == main
通俗的理解__name__ == '__main__'：假如你叫小明.py，在朋友眼中，你是小明(__name__ == '小明')；在你自己眼中，你是你自己(__name__ == '__main__')。

if __name__ == '__main__'的意思是：当.py文件被直接运行时，if __name__ == '__main__'之下的代码块将被运行；当.py文件以模块形式被导入时，if __name__ == '__main__'之下的代码块不被运行。
## sys
1、sys是什么？
sys是python的一个【标准库】，是【system】的简写，封装了一些与系统相关的信息和接口。

2、argv是什么？
argv是【argument variable】的缩写，意为“参数变量”，这个参数变量是一个List列表。
argv[0] 是“被调用脚本文件的相对路径或者绝对路径”，例如：
这里的有一个test.py脚本文件：

# test.py
import sys
a=sys.argv[0]
print(a)

它的绝对路径为“F:\PythonCode\test.py”，在控制台这就有两种命令调用方式：
（1）绝对路径调用

python F:\PythonCode\test.py

得到的输出结果为F:\PythonCode\test.py,为被调用脚本文件的绝对路径。
（2）相对路径调用
进入到“F:\PythonCode”目录下，进行命令调用：

python test.py

得到的输出结果为test.py,为被调用脚本文件的相对路径。

argv[1]和以后的元素是“自己传入的参数”，例如：
（1）将上述test.py脚本的sys.argv[0]改为sys.argv[1]：

a=sys.argv[1]

使用相对路径调用的方式，

python test.py I

得到的输出结果为I。
（2）将上述test.py脚本的sys.argv[0]改为sys.argv[2：]：

a=sys.argv[2:]

使用相对路径调用的方式，

python test.py I am cn

得到的输出结果为am cn。
————————————————
版权声明：本文为CSDN博主「不一样的天蝎座」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Mr____Cheng/article/details/124734356
## exit(0) exit(1) return 0 的区别


exit（0）：正常运行程序并退出程序；

exit（1）：非正常运行导致退出程序；

return（）：返回函数，若在主函数中，则会退出函数并返回一值。
## python 中__file__代表什么 怎么使用


**__file__是Python中内置的变量，它表示当前文件的文件名。可以在脚本或模块中使用它来访问当前文件的路径。**例如：

importos
print(os.path.abspath(__file__))
————————————————
版权声明：本文为CSDN博主「low sapkj」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_35749786/article/details/129505090
## python format用法

format用法
 相对基本格式化输出采用‘%’的方法，format()功能更强大，该函数把字符串当成一个模板，通过传入的参数进行格式化，并且使用大括号‘{}’作为特殊字符代替‘%’

使用方法由两种：b.format(a)和format(a,b)。

1、基本用法

　　（1）不带编号，即“{}”

　　（2）带数字编号，可调换顺序，即“{1}”、“{2}”

　　（3）带关键字，即“{a}”、“{tom}”





 1 >>> print('{} {}'.format('hello','world'))  # 不带字段
 2 hello world
 3 >>> print('{0} {1}'.format('hello','world'))  # 带数字编号
 4 hello world
 5 >>> print('{0} {1} {0}'.format('hello','world'))  # 打乱顺序
 6 hello world hello
 7 >>> print('{1} {1} {0}'.format('hello','world'))
 8 world world hello
 9 >>> print('{a} {tom} {a}'.format(tom='hello',a='world'))  # 带关键字
10 world hello world
————————————————
版权声明：本文为CSDN博主「发狂的蜗牛」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/digitalkee/article/details/120575834

## Python subprocess中的run方法 
调用subprocess的推荐方法是对于它可以处理的所有使用场景都使用run()函数。

run()函数是在Python 3.5中添加的,如果在老版本中使用,需要下载并扩展。
```
扩展安装方式:

$ pip install subprocess.run
使用方式:

subprocess.run(args, *, stdin=None, input=None, stdout=None, stderr=None, shell=False, timeout=None, check=False)
运行args描述的命令。等待命令完成，然后返回一个CompletedProcess实例。

完整的函数形式很大程度上与Popen构造函数相同 —— 除timeout、input和check之外，该函数的所有参数都传递给Popen接口。

>>> subprocess.run(["ls", "-l"])  # doesn't capture output
CompletedProcess(args=['ls', '-l'], returncode=0)

>>> subprocess.run("exit 1", shell=True, check=True)
Traceback (most recent call last):
  ...
subprocess.CalledProcessError: Command 'exit 1' returned non-zero exit status 1

>>> subprocess.run(["ls", "-l", "/dev/null"], stdout=subprocess.PIPE)
CompletedProcess(args=['ls', '-l', '/dev/null'], returncode=0,
stdout=b'crw-rw-rw- 1 root root 1, 3 Jan 23 16:23 /dev/null\n')
class subprocess.CompletedProcess表示从run()返回的值，表示已完成的进程。
```
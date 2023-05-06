# -*- coding:utf8 -*-
import numpy as np

array = np.array([[1, 2, 2],       # 注意逗号
                  [2, 3, 4]])

print(array)
print('number of dim:', array.ndim)  # 注意这里是ndim
print('shape:', array.shape)
print('size：', array.size)
print('----------------------------------------------------------------')

a = np.array([2, 3, 45], dtype=np.int64)        # dtype：定义类型，int64 表示64位 64占用空间大 精确度较高 也可定义16位 空间小
print(a.dtype)

b = np.zeros((3, 4))
print(b)

c = np.ones((3, 2))
print(c)

d = np.arange(2, 10, 2)
print(d)
print('-------------a-d----------------------------------')

e = np.arange(2, 10, 2).reshape((2, 2))         # reshape函数：重新定义类型
print(e)

f = np.linspace(1, 10, 4).reshape((2, 2))      # linspace为生成线段的函数，1，10，4分别为起点终点和数字数量（数字减去1才等于线段数）。
print(f)

print(f < 3)                                   # 判断矩阵里数字的大小
print(np.sin(f))                               # sin,cos，tan 三角函数的用法
print(e-f)                                     # 矩阵加减法，幂，
print(e**2)


print(e*f)                                     # （逐个相乘，不是矩阵的正规乘法）
print(np.dot(e, f))                            # dot函数：矩阵的乘法
print(e.dot(f))                                # 与上一行表达意思一样，不同写法
print('-----------e-f--------------------')

h = np.random.random((2, 3))                   # 第一个random是random模块，第二个random是random函数,返回随机数矩阵、
print(h)
print(np.sort(h))                              # 不是全排列，而是对每一行进行排列。
g = np.arange(2, 14).reshape((3, 4))
print(g)
print('总和：', np.sum(g))
print('平均值：', np.mean(g))                    # 平均值用mean函数，本行代码也可写成g.mean()
print(np.sum(g, axis=1))                       # axis = 1 表示行 ，axis = 0 表示列。
print(np.min(g, axis=0))
print(np.max(g, axis=1))
print('最大值索引', np.argmax(g))                # argmax 表示最大值的索引，同理argmin。
print('最小值索引', np.argmin(g))
print('中位数', np.median(g))                   # median() 中位数函数，中位数表示一组数字处在中间的一位 或 两位的平均值。
print('累加：', np.cumsum(g))                   # cumsum函数 ：表示累加，第二个为第1个+第2位，第三个为1+2+3。
print(np.diff(g))                              # diff函数： 第一位为第二位减去第一位，第三位为3-2，会比原矩阵少一列。
print('转置矩阵：', np.transpose(g))
print('转置矩阵:', g.T)                                     # 矩阵的转置，与上面一行代码相同作用。
print((g.T).dot(g))                            # 矩阵的转置再乘以本身。
print(np.clip(g, 4, 8))                        # clip函数：限定一个array的上下限，所有小于下限的数都等于下限，所有大于上限的数。。。

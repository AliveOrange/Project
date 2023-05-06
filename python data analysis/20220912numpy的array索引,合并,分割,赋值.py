import numpy as np

# 1.numpy的索引
print('1.numpy的索引')
a = np.arange(2, 14).reshape(3, 4)
print(a)
print(a[2])
print(a[2, 3])                                       # 第三行第四列，注意索引值是从0开始
print(a[:, 2])
print(a[1:3, 1])

for raw in a:                                        # 这里raw相当于i，默认每一行为一个元素。
    print(raw)

for column in a.T:                                   # 矩阵的一个元素默认为每一行，要求每一列，只需将矩阵转置即可。
    print(column)

print(a.flatten())                                   # flatten()函数，相当于把矩阵展开成一个列表。
for item in a.flatten():                             # 用此方法可以将矩阵内的每个数字输出.
    print(item)

# 2.numpy的array合并
print('2.numpy的array合并')

b = np.array([2, 3, 4])
c = np.array([2, 2, 2])

print(np.vstack((b, c)))                             # vertical stack 垂直方向合并
print(np.hstack((b, c)))                             # horizontal stack 水平方向合并

print(b[:, np.newaxis])                              # 给矩阵加一个纵向的维度
print(np.concatenate((b[:, np.newaxis], b[:, np.newaxis]), axis=0))    # 指定方向的合并.

# 3.numpy的array分割
print('3.numpy的array分割')

d = np.arange(12).reshape(3, 4)
print(d)

print(np.split(d, 4, axis=1))                        # 等量分割:对每一行进行等分,得出来的就是列.
print(np.array_split(d, 3, axis=1))                  # 不等量分割:4列分成3份,第一份得到两列,其他都是一列.

print(np.vsplit(d, 3))                               # 竖直方向上分割,得出来的是行,水平方向上同理,hsplit().


# 4.numpy的array赋值,copy,deep copy
print('4.numpy的array赋值')

e = np.array([2, 4, 3, 4])
print(e)
f = e
g = e.copy()                                         # g为e的copy,但不等同于e,不会随着e的改变而改变.
e[2] = 22
print(e)
print(f)
print(g)

 


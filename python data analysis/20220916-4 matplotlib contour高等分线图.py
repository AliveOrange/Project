import matplotlib.pyplot as plt
import numpy as np

def f(x, y):                                             # 定义等高线表达式
    return(1 - x/2 + x**5 + y**3)*np.exp(-x**2 - y**2)

n = 256
x = np.linspace(-3, 3, n)
y = np.linspace(-3, 3, n)
X, Y = np.meshgrid(x, y)            # 从坐标向量中返回坐标矩阵

# use plt.contourf to filling contours(轮廓，外形)
# X,Y and value for (X，Ｙ）　ｐｏｉｎｔ
plt.contourf(X, Y, f(X, Y), 8, alpha=0.5, cmap=plt.cm.hot)           # cmap是颜色参数

# use plt.contour to add contour lines                              # 添加轮廓线
C = plt.contour(X, Y, f(X, Y), 8, colors='black')
# adding label
plt.clabel(C, inline=True, fontsize=10)

plt.xticks(())
plt.yticks(())
plt.show()

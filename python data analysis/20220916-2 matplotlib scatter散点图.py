import matplotlib.pyplot as plt
import numpy as np

n = 1024
X = np.random.normal(0, 1, n)            # np.random.normal 从正态分布中抽取随机样本。0是均值，1是标准差
Y = np.random.normal(0, 1, n)
T = np.arctan2(Y, X)                     # 表述颜色的函数

plt.xlim(-1, 1)
plt.ylim(-1, 1)
plt.scatter(x=X, y=Y, c=T, alpha=0.5)
plt.xticks(())
plt.yticks(())                          # 不输入ticks的参数就不显示ticks

plt.show()

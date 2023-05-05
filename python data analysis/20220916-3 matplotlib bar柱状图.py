import matplotlib.pyplot as plt
import numpy as np

n = 12
X = np.arange(n)

Y1 = 1/(11+X)+np.random.uniform(0.5, 1, n)                  # np.random.uniform()均匀分布中随机采样，区间左闭右开
Y2 = 1/(11+X)+np.random.uniform(0.5, 1, n)                  # 1/(11+x) 没什么含义，只是为了让x和y挂钩

plt.bar(X, Y1, facecolor='red', edgecolor='white')         # plt.bar()柱状图
plt.bar(X, -Y2, facecolor='blue', edgecolor='white')

for x, y in zip(X, Y1):                                    # 用zip（）才能保证xy同时输出
    plt.text(x+0.1, y+0.05, '%.2f' % y, ha='center', va='bottom')        # ha:horizontal alignment 水平对齐线 va垂直对齐线

for x, y in zip(X, Y2):
    plt.text(x+0.1, -y-0.2, '-%.2f' % y, ha='center', va='bottom')

plt.xlim(-.5, n)
plt.xticks(())
plt.ylim(-1.25, 1.25)

plt.show()

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y = 0.1*x
plt.figure(num=1, figsize=[5, 5])
plt.plot(x, y, linewidth=10, zorder=1)               # zorder表顺序，也可设置等于2，3，4。。。来进行表示绘画先后顺寻。
plt.ylim(-2, 2)                                      # 限制x或y的范围的方法

ax = plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')         # 将右轴和上轴隐藏处理
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')        # 将下轴和左轴设置为x，y
ax.spines['bottom'].set_position(('data', 0))
ax.spines['left'].set_position(('data', 0))    # 设置将xy轴的交点位置

for label in ax.get_xticklabels() + ax.get_yticklabels():
    label.set_fontsize(12)
    label.set_bbox(dict(facecolor='gray', edgecolor='None', alpha=0.7))
#  以上三行代码都是对ticklabels进行的更改，以提高能见度。

plt.show()

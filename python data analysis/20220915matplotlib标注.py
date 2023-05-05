import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y = 2*x + 1
plt.figure(num=1, figsize=[5, 5])
plt.plot(x, y)

ax = plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')         # 将右轴和上轴隐藏处理
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')        # 将下轴和左轴设置为x，y
ax.spines['bottom'].set_position(('data', 0))
ax.spines['left'].set_position(('data', 0))    # 设置将xy轴的交点位置

x0 = 1
y0 = 2*x0 + 1
plt.scatter(x0, y0, s=50, color='black')      # scatter 表示点 plot表示线，注意size必须缩写成s，否则打印出错，color可缩可不缩写。
plt.plot([x0, x0], [y0, 0], 'k--', lw=2.5)    # 这里一定要注意两个点的写法，此处表达的是（x0，y0）和（x0，0） k表示线型，lw线宽
# 标注一
plt.annotate('2x+1=%s' % y0, xy=(x0, y0), xytext=(+30, -30), xycoords='data', textcoords='offset points', fontsize=16, arrowprops=dict(arrowstyle='->', connectionstyle='arc3,rad=.2'))
# arrowprops表示那条指示线，xytext=是偏移量，基于textcoords=。。
# 标注2：文本标注
plt.text(-4.2, 3, 'This is the some text.', fontdict={'size': 16, 'color': 'red'})
# (-4.2,3)是位置，
plt.show()

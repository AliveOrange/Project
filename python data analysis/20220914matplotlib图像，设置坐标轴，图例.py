import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-1, 1, 20)
y1 = x**2
y2 = x*2
plt.figure()                                # 当需要建立多张图表时
plt.plot(x, y1)

plt.figure(num=3, figsize=(8, 7))           # num=10，输出就是figure10，为了命名。 figsize=（8， 7）是规定figure的尺寸。
plt.plot(x, y2, label='aaa')
plt.plot(x, y1, color='red', linewidth=1.0, linestyle='--', label='bbb')          # plt.plot（）相当于给figure添加数据，可以添加多组数据。
# 也可以对图线格式进行更改，linewidth表示线宽，linestyle线的样式。,label是指给线一个标签，便于打印出哪个线是什么。
plt.legend(loc='best')                    # plt.legend()是设置图例框，还可改变其他参数，自行查略，实现这一步必须先有上面每条线的label，另外注意loc位置还可设置为其他的。
plt.xlim(-1, 2)                           # 限定x或y轴的坐标区间
new_ticks = np.linspace(-1, 2, 5)
plt.xticks(new_ticks)                     # 更改x或y轴显示的单位坐标
plt.ylabel('I am y')                      # 更改坐标标签
plt.yticks([-2, -1.8, -1, 1.22, 3], ['really bad', 'bad', 'normal', 'good', 'very good'])
# 可以将坐标刻度显示为数字外的其他形式
ax = plt.gca()                             # gca ='get current axis'
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')         # 将右轴和上轴隐藏处理
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')        # 将下轴和左轴设置为x，y
ax.spines['bottom'].set_position(('data', 0))
ax.spines['left'].set_position(('data', 0))    # 设置将xy轴的交点位置
plt.show()



import matplotlib.pyplot as plt

fig = plt.figure()
x = [1, 2, 3, 4, 5, 6, 7]
y = [1, 3, 4, 2, 5, 8, 6]

ax1 = fig.add_axes([.1, .1, .8, .8])           # 括号内数字前两个表起点位置，后两个表大小
ax1.plot(x, y, 'red')
ax1.set_xlabel('x')
ax1.set_ylabel('y')
ax1.set_title('title1')

# 图中图，图2，只需要改变位置即可

ax2 = fig.add_axes([.2, .6, .2, .2])
ax2.plot(x, y, 'red')
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_title('title2')

# 图中图，图3，只需要改变位置即可

ax3 = fig.add_axes([.6, .2, .2, .2])
ax3.plot(x, y, 'red')
ax3.set_xlabel('x')
ax3.set_ylabel('y')
ax3.set_title('title3')

plt.show()

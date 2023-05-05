import matplotlib.pyplot as plt
import numpy as np
from matplotlib import animation

fig, ax = plt.subplots()

x = np.arange(0, 2*np.pi, 0.01)                       # np.pi=Π， np.e = e
line, = ax.plot(x, np.sin(x))                         # line，表示列表的第一位，因为右侧返回的是列表

def animate(i):                                       # 第i帧
    line.set_ydata(np.sin(x+i/10))
    return line,

def init():
    line.set_ydata(np.sin(x))
    return line,

ani = animation.FuncAnimation(fig=fig, func=animate, frames=100, init_func=init, interval=20, blit=True)
# 这一步是产生动画的关键，func是动画，frames帧数，init_func,最开始的， interval间隔，20毫秒一次 blit=True时，只更新变化的点

plt.show()

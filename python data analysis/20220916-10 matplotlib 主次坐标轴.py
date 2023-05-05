import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0, 10, 0.1)
y1 = 0.05*x**2
y2 = -1*y1

fig, ax1 = plt.subplots()
ax2 = ax1.twinx()                                 # twinx表示共享x轴，twiny表共享y轴

ax1.plot(x, y1, 'g-')                             # 这里打green为何会报错呢？
ax2.plot(x, y2, 'b--')

ax1.set_xlabel('X data')
ax1.set_ylabel('Y1',color='g')
ax2.set_ylabel('Y2', color='b')

plt.show()



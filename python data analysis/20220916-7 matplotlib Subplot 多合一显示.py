import matplotlib.pyplot as plt

plt.figure()

plt.subplot(2, 2, 1)                         # 建立子图，2，2，1代表子表为2行2列，的第一个位置
plt.plot([0, 1], [0, 1])                     # 代表横纵坐标轴的区间

plt.subplot(2, 2, 2)
plt.plot([0, 1], [0, 2])

plt.subplot(2, 2, 3)
plt.plot([0, 1], [0, 3])

plt.subplot(2, 2, 4)
plt.plot([0, 1], [0, 4])

plt.show()

# 如果不均分，比如四张图第一张图占一行，第2，3，4张图占第二行，可设置为数字 2，1，1，  2，3，4，  2，3，5，  2，3，6

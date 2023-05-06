import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

# method 1: subplot2.grid

plt.figure()
ax1 = plt.subplot2grid((3, 3), (0, 0), colspan=3, rowspan=1)  #3,3 代表分成三行三列9块部分，0，0代表起始点，colspan代表占几个列
ax1.plot([1, 2], [1, 2])
ax1.set_xlim(-1, 1)                     # plt.xlim()在这里要改成ax.set_xlim(),所有参数都要这样设置，如下一行也是
ax1.set_title('image1')
ax2 = plt.subplot2grid((3, 3), (1, 0), colspan=2)
ax3 = plt.subplot2grid((3, 3), (2, 0))
ax4 = plt.subplot2grid((3, 3), (2, 1))
ax5 = plt.subplot2grid((3, 3), (1, 2), rowspan=2)

# -----------method 2：gridspec

# gs = gridspec.GridSpec(3, 3)
# ax1 = plt.subplot(gs[0, :])
# ax2 = plt.subplot(gs[1, :2])
# ax3 = plt.subplot(gs[2, 0])
# ax4 = plt.subplot(gs[2, 1])
# ax5 = plt.subplot(gs[1:, 2])

# method3: easy to define structure

# f, ((ax11, ax12), (ax21, ax22)) = plt.subplots(2, 2, sharex=True, sharey=True)   # 注意是subplots，带s,sharex，y共享xy轴
# ax11.scatter([1, 2], [1, 2])
# plt.tight_layout()


plt.show()

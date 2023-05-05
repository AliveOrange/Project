import matplotlib.pyplot as plt
import numpy as np

# image data
a = np.array([0.31, 0.36, 0.27, 0.38, 0.39, 0.40, 0.23, 0.44, 0.53]).reshape(3, 3)

# plt.imshow()的用法，将数组转换为图像
plt.imshow(a, interpolation='nearest', cmap='bone', origin='upper')         # interpolation，cmap都是颜色参数，origin是排序参数
plt.colorbar(shrink=0.5)                        # 表示颜色的柱状图

plt.xticks(())
plt.yticks(())
plt.show()

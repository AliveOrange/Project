import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Series
data = pd.Series(np.random.randn(1000), index=np.arange(1000))        # random.randn(dn)是返回dn个数，符合正态分布。
data = data.cumsum()
data.plot()
plt.show()

# DataFrame
data = pd.DataFrame(np.random.randn(1000, 4), index=np.arange(1000), columns=list('ABCD'))
data = data.cumsum()
data.plot()
plt.show()

# plot method: 'bar', 'hist', 'box', 'kde', 'area', 'scatter'
ax = data.plot.scatter(x='A', y='B', color='Red', label='CLASS-1')      # 这里以scatter举例
data.plot.scatter(x='A', y='C', color='Black', label='CLASS-2', ax=ax)  # ax=ax,是将第二张图附在第一张图的关键。
plt.show()
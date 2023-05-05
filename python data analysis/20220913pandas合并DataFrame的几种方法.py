import numpy as np
import pandas as pd

print('1. pandas合并concatenating')

df1 = pd.DataFrame(np.ones((3, 4))*0, columns=['a', 'b', 'c', 'd'])
df2 = pd.DataFrame(np.ones((3, 4))*1, columns=['a', 'b', 'c', 'd'])
df3 = pd.DataFrame(np.ones((3, 4))*2, columns=['a', 'b', 'c', 'd'])
print(df1)
print(df2)
print(df3)
print(pd.concat([df1, df2, df3], axis=0, ignore_index=True))                   # 默认ignore_index为false,表示不忽略原index.

print("1.1 join联结, inner内联结,outer外联结")
df5 = pd.DataFrame(np.ones((3, 4))*0, columns=['a', 'b', 'c', 'd'])
df6 = pd.DataFrame(np.ones((3, 4))*1, columns=['e', 'b', 'c', 'd'])
print(df5)
print(df6)
print(pd.concat([df5, df6]))                      # 当columns不完全相同时,就要用到内外联结,如下.

res = pd.concat([df5, df6], join='inner', ignore_index=True)         # inner 内联结 合并相同列部分,这里默认axis =0.
print(res)

res2 = pd.concat([df5, df6], join='outer', ignore_index=True)        # outer 外联结 没有的columns默认为nan
print(res2)

print('1.2 pandas合并 join_axes方法')                        # 目前版本已经没有join_axes方法了
df7 = pd.DataFrame(np.ones((3, 4))*0, columns=['a', 'b', 'c', 'd'], index=[1, 2, 3])
df8 = pd.DataFrame(np.ones((3, 4))*1, columns=['e', 'b', 'c', 'd'], index=[2, 3, 4])
print(df7)
print(df8)
print(df8.values)



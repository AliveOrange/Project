#  numpy是一个序列化好的矩阵或序列0-n是排列好的,而pandas更像一个字典形式的numpy,可以给不同行不同列进行命名.
import numpy as np
import pandas as pd

print('1.创建pandas')

a = pd.Series([1, 3, 4, np.nan, 44, 2])                 # nan相当于non
print(a)

dates = pd.date_range('20220912', periods=6)
print(dates)

df1 = pd.DataFrame(np.arange(12).reshape((3, 4)))            # 注意DataFrame()函数是pandas重要的一个函数
print(df1)

df = pd.DataFrame(np.random.randn(6, 4), index=dates, columns=['a', 'b', 'c', 'd'])   # 同上一行代码,另外自定义行和列的索引
print(df)

# 对于DataFrame还可以直接写入DataFrame(每一列的字典形式)

df2 = pd.DataFrame({'a': 1, 'b': np.array([3]*4, dtype='int32'), 'c': pd.Categorical(['test', 'test2', 'test3', 'train'])})
print(df2)
print(df2.dtypes)
print(df2.index)
print(df2.columns)
print(df2.values)                                   # 只打印出pandas的值，不打印行名和列名。
print(df2.describe())                               # describe函数只能对数字形式进行汇总
print(df2.T)
print(df2.sort_index(axis=1, ascending=False))      # 对列名进行排序（正序或倒序）,将axis=0就是对行名排序
print(df2.sort_values(by='c'))                      # 对某一行或某一列的值进行排序

print('2.pandas 选择数据')

dates3 = pd.date_range('20220913', periods=6)
df3 = pd.DataFrame(np.arange(24).reshape((6, 4)), index=dates3, columns=['a', 'b', 'c', 'd'])
print(df3)
print(df3.values[0])                              # 这两个都是打印df2的第a列。
# print(df3[1:2])     # 打印第二行，单独写df2[1]无法打印。也可以打印第n行到第m行、
#
# print('2.1 根据索引（标签）打印出更某行某列，甚至某行某列的一个数,select by label:loc')
# print(df3.loc['20220914'])                          # 根据行的索引打印某一行
# print(df3.loc['20220914':'20220915', ['a', 'b']])                       # 根据列的索引打印全部行或部分行的某一列
#
# print('2.2 根据位置（数字）打印出某行某列，select by position:iloc')
# print(df3)
# print(df3.iloc[3, 1])                               # 也可进行切片或者用元组形式[[1,2,4],1:3]如下一行
# print(df3.iloc[[1, 2, 4], 1:3])
#
# print(df3[df3.a > 8])                               # df3.a > 8 可进行判断某一行（列）的值，然后输出true or false

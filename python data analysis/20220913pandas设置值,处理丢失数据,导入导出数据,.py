import numpy as np
import pandas as pd

print('1. pandas设置值')
dates = pd.date_range('20220913', periods=6)
df = pd.DataFrame(np.arange(24).reshape((6, 4)), index=dates, columns=['a', 'b', 'c', 'd'])
print(df)

df.iloc[2, 2] = 111                        # pandas设置值
df.b[df.a > 8] = 0                         # 根据条件来更改值
df['f'] = np.nan                           # 添加行
df['e'] = pd.Series([1, 2, 3, 5, 6, 7], index=pd.date_range('20220913', periods=6))
# 注意 上一行的index =...是必须的,一定要与原来的行的标签对应,不然输入的全部都是nan
print(df)

print('1.1 pandas处理丢失数据')

print(df.dropna(axis=1, how='any'))       # 丢弃nan数据,dropna()函数how={'any','all'} ,当how =all时,只有某一列或某一行全为nan时才丢弃.

print(df.fillna(value=0))                 # 填充nan数据,fillna()函数可以设置所有nan为默认值.

print(df.isnull())                        # isnull()函数,判断是否为空,数值为nan是返回Ture,按照原pandas格式.

print(np.any(df.isnull()) == True)        # 判断数据中是否含有nan,只要有一个nan就返回Ture.

print('1.2 pandas导入导出数据')
# csv ,pickle excel 都是常用的数据文件格式

data = pd.read_csv('students information.csv')        # 注意,如果导入数据中有中文,需要做其他处理
print(data)

data.to_pickle('students information.pickle')         # to_pickle是存储为pickle形式,其他形式类似,read_csv为读取scv类型的文件.



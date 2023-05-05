import numpy as np
import pandas as pd
left = pd.DataFrame({
    "key": ["K0", "K1", "K2", "K3"],
    "A": ["A0", "A1", "A2", "A3"],
    "B": ["B0", "B1", "B2", "B3"],
})

right = pd.DataFrame({
    "key": ["K0", "K1", "K2", "K3"],
    "C": ["C0", "C1", "C2", "C3"],
    "D": ["D0", "D1", "D2", "D3"],
})
print(left)
print(right)
res = pd.merge(left, right, on='key')           # 重点注意merge（）函数的使用，on来指定列，注意merge只能做左右拼接
print(res)
print('1.1 merge（）函数中还有how =left,right,inner,outer方法')
left1 = pd.DataFrame({
    "key1": ["K0", "K0", "K1", "K2"],
    "key2": ["K0", "K1", "K0", "K1"],
    "A": ["A0", "A1", "A2", "A3"],
    "B": ["B0", "B1", "B2", "B3"],
})


right1 = pd.DataFrame({
    "key1": ["K0", "K1", "K1", "K2"],
    "key2": ["K0", "K0", "K0", "K0"],
    "C": ["C0", "C1", "C2", "C3"],
    "D": ["D0", "D1", "D2", "D3"],
})
print(left1)
print(right1)
res1 = pd.merge(left1, right1, how='left', on=['key1', 'key2'])   # 默认how='inner'，求得的是相交的结果
print(res1)

# outer: 集合两个 df 所有 的 key
# inner: 集合两个 df 同时拥有 的 key
# left: 仅考虑左边 df 所有 的 key
# right: 仅考虑右边 df 所有 的 key
res1a = pd.merge(left1, right1, how='outer', on=['key1', 'key2'], indicator=True)   # 比起上面，加入indicator参数，可以看出整合的情况
print(res1a)
# 注意上面indicator打印出来的column为——merge，如果想改成其他名字(name)，可直接令indicator = 'name'

print('1.2 利用index合并,上面的是根据某一列为基准进行合并')

left2 = pd.DataFrame({
    "A": ["A0", "A1", "A2", "A3"],
    "B": ["B0", "B1", "B2", "B3"]}, index=["K0", "K1", "K2", "K3"])

right2 = pd.DataFrame({
    "C": ["C0", "C1", "C2", "C3"],
    "D": ["D0", "D1", "D2", "D3"]}, index=["K0", "K1", "K2", "K4"])
print(left2)
print(right2)
res2 = pd.merge(left2, right2, left_index=True, right_index=True, how='outer')
# 默认left_index=NON，这里表示考虑以左右两个的index为基准，而不是以column的某一列为基准
print(res2)

print('1.3 merge合并时如果有列名相同的情况，怎么区分,用到suffixes')
# 比如这里要统计男员工等级年龄和女员工等级年龄
boy = pd.DataFrame({
    "k": ["k1", "k5", "k2", "k3"],
    "age": ["2", "4", "3", "5"]})

girl = pd.DataFrame({
    "k": ["k0", "k1", "k2", "k3"],
    "age": ["3", "4", "5", "7"]})
print(boy)
print(girl)
res3 = pd.merge(boy, girl, on='k', suffixes=['_boy', '_girl'], how='outer')   # suffixes添加后缀区分
print(res3)

# F : 合并石子

Time Limit: `1 Sec`,   Memory Limit: `128 Mb`

## Description

在一个圆形操场的四周摆放 N 堆石子,现要将石子有次序地合并成一堆.规定每次只能选相邻的2堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。

试设计出一个算法,计算出将 N堆石子合并成 1堆的最小得分和最大得分。

## Input

数据的第 1行是正整数 N，表示有 N 堆石子, N <= 500。

第 2 行有 N 个整数，第 i个整数 ai 表示第 i 堆石子的个数, ai <= 50。

## Output

输出共 2 行，第 1 行为最小得分，第 2 行为最大得分。

## Sample Input

```
4
4 5 9 4
```

## Sample Output

```
43
54
```

[参考代码](../Solution/F.cpp)
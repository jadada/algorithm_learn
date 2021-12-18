# D : 数的划分

Time Limit: `1 Sec`,   Memory Limit: `128 Mb`

## Description

将整数 n 分成 k 份，且每份不能为空，任意两个方案不相同（不考虑顺序）。

例如：$n = 7, k = 3$，下面三种分法被认为是相同的。

1 , 1 , 5

1 , 5 , 1

5 , 1 , 1

问有多少种不同的分法。

## Input

$n,k$ （$6 < n \leq 200$，$2 \leq k \leq 6$）

## Output

1 个整数，即不同的分法。

## Sample Input

```
7 3
```

## Sample Output

```
4
```

## Hint

对于样例的输入输出

四种分法为：

1 , 1 , 5

1 , 2 , 4

1 , 3 , 3

2 , 2 , 3



[参考代码](../Solution/D.cpp)
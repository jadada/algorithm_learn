# A : 防守战线

Time Limit: `1 Sec`,   Memory Limit: `128 Mb`

## Description

战线可以看作一个长度为 $n$ 的序列，现在需要在这个序列上建塔来防守敌兵，在序列第 *i* 号位置上建一座塔的花费为 $C_i$，且一个位置可以建任意多的塔，费用累加计算。有 *m* 个区间 $[L_1,R_1]$, , $[L_2,R_2]$ ...,  $[L_m,R_m]$，在第 *i* 个区间的范围内要建至少 $D_i$ 座塔，求最少花费。

## Input

第一行为两个数 $n$, $m$ ( $n\leq1000$, $m\leq10000$)，分别表示序列长度及区间个数

第二行有 $n$ 个数，描述序列 $C$ ($C_i\leq 10000$)

接下来 $m$ 行，每行有三个数 $L_i$, $R_i$, $D_i$，描述一个区间 ( $1\leq L_i \leq R_i\leq n$,  $D_i\leq10000$)

## Output

一个整数，代表最少花费

## Sample Input

```
5 3
1 5 6 3 4
2 3 1
1 5 4
3 5 2
```

## Sample Output

```
11
```

## Hint

位置 1 建 2 个塔，位置 3 建 1个塔，位置 4 建 1 个塔，共花费 1 * 2 + 6 + 3 = 11 。



[参考代码](../solution/A.cpp)
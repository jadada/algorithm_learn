# D : 矩阵链相乘

Time Limit: `5 Sec`,    Memory Limit: `128 Mb`

## Description

设A1,A2,…,An为矩阵序列，Ai是阶为Pi−1∗Pi的矩阵(1≤i≤n)。

试确定矩阵的乘法顺序，使得计算A1 A2 … An 过程中元素相乘的总次数最少。

## Input

多组数据

第一行一个整数n(n <= 300)，表示一共有n个矩阵。

第二行n个整数B1, B2, B3… Bn(Bi <= 100)，第i个数Bi表示第i个矩阵的行数和第i-1个矩阵的列数。

等价地，可以认为第j个矩阵Aj(1 <= j <= n)的行数为Bj，列数为Bj+1。

## Output

对于每组数据，输出一个最优计算次数

## Sample Input

```
5
74 16 58 58 88 80 
5 
10 1 50 50 20 5 
```

## Sample Output

```
342848
3650
```

[参考代码](../Solution/D.cpp)
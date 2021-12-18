# B : 矩阵相乘

Time Limit: `1 Sec`,   Memory Limit: `128 Mb`

## Description

输入两个矩阵，大小均为*n* * *n*，(n为2的整数次幂）。

矩阵里每个数为自然数且均小于10。

输出两个矩阵相乘的结果。

## Input

第一行一个整数：n。 2 ≤ *n* ≤ 128

接下来n行，每行n个空格隔开的整数，表示矩阵 *A*(*i*, *j*)。

接下来n行，每行n个空格隔开的整数，表示矩阵 *B*(*i*, *j*)。

## Output

n行，每行n个空格隔开的整数，输出相乘後的矩阵 *C*(*i*, *j*) 的值。

## Sample Input

```
2
1 2
3 4
0 1
0 0
```

## Sample Output

```
0 1
0 3
```

[参考代码](../Solution/B.cpp)
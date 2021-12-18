# A : 数字三角形

Time Limit: `1 Sec`,   Memory Limit: `128 Mb`

## Description

给出如下图的数字三角形，要求从顶层走到底层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？ ![img](https://images1.tqwba.com/20200930/fopfndh4huk.png)

## Input

输入数据首先包括一个整数T,表示测试实例的个数。

每个测试实例的第一行是一个整数N(1 <= N <= 100)，表示数塔的高度。

接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。

## Output

对于每个测试实例，输出可能得到的最大和，每个实例的输出占一行。

## Sample Input

```
1
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
```

## Sample Output

```
30
```

[参考代码](../Solution/A.cpp)
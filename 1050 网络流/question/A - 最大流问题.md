# A : 最大流问题

Time Limit: `1 Sec`, Memory Limit: `128 Mb `

## Description

给出一张网络有向图，源点及汇点，计算其最大流。

## Input

第一行给出四个整数N(1 <= N <= 200), M(N <= M <= 5000),S,T，分别表示节点数量、有向边数量、源点序号、汇点序号。

接下来M行每行包括三个正整数ui，vi，wi，表示第 i条有向边从 ui出发，到达 vi，边权为 wi。

## Output

一行，包括一个正整数，为该网络流最大流。

## Sample Input

```
6 9 4 2
1 3 10
2 1 20
2 3 20
4 3 10
4 5 30
5 2 20
4 6 20
5 6 10
6 2 30
```

## Sample Output

```
50
```

[参考代码](../solution/1050%20A.cpp)
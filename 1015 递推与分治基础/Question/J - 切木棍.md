# J : 切木棍

Time Limit: `2 Sec`,   Memory Limit: `1024 Mb`

## Description

 有*n*根长为，$a_1,a_2⋯,a_n$的木棍。

 对*n*根木棍总共切*k*次（可以在任意点切割），即最后变成*n* + *k*根木棍。

 请输出各种切法种得到的*n* + *k*根木棍中最长那根在各种切法中的最短值（答案需要四舍五入）。

- $1 ≤ n ≤ 2 × 10^5$
- $0 ≤ k ≤ 10^9$
- $1 ≤ a_i ≤ 10^9$
- 所有值都是整数。

## Input

*n* *k*

$a_1,a_2⋯,a_n$

## Output

输出一个整数

## Sample Input

```
2 3
7 9
```

## Sample Output

```
4
```

## Hint

二分

[参考代码](../Solution/J.cpp)
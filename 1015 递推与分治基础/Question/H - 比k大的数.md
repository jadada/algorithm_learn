# H : 比k大的数

Time Limit: `2 Sec`   Memory Limit: `128 Mb`

## Description

给出一个由n个整数组成的数列 $a_1, a_2, a_3, ..., a_n$ 之后给出m个整数k，问：对于每一个k，数列中有多少个数比k大？

## Input

输入共包括三行

第一行是两个由空格隔开的正整数n和m

第二行是由n个整数组成的数列 $a_1, a_2, a_3, ..., a_n$  ，数与数之间由空格隔开。

第三行有m个整数k，数与数之间由空格隔开。

保证 $0 < n ≤ 1 × 10^3$; $0 < m ≤ 1 × 10^3$;  $−1 × 10^3 ≤ a_1, a_2, a_3, ...,a_n ≤ 1 × 10^3$;  $−1 × 10^6 ≤ k ≤ 1 × 10^6$;

## Output

输出共包括m行，每行一个整数，表示数列中有多少个数比k大

## Sample Input

```
5 5
1 2 3 4 5
3 5 4 6 -1
```

## Sample Output

```
2
0
1
0
5
```


[参考代码](../Solution/H.cpp)
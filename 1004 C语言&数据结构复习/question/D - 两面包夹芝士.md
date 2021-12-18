# D : 两面包夹芝士

Time Limit: `1 Sec`, Memory Limit: `128 Mb` 

## Description

给你两个长度为 $N$ 的整型(int)数组 $A=(A_1,A_2,\cdots,A_N)$ 和 $B=(B_1,B_2,\cdots,B_N)$

请你找出有多少整型(int)数字 $x$，满足 $A_i \leq x \leq B_i$，其中 $1 \leq i \leq N$

## Input

第一行输入N，第二行输入 $N$ 个数字 $A_i$，第三行输入N个数字 $B_i$

- $1 leq N \leq 100$
- $1 \leq A_i \leq B_i \leq 1000$
- 所有输入均为int

## Output

输出有多少个符合题意的 $x$，然后换行

## Sample Input

```
3
3 2 5
6 9 8
```

## Sample Output

```
2
```

[参考代码](../Solution/D.cpp)

# I : 异或最大值升级版

Time Limit: `2 Sec`, Memory Limit: `128 Mb`

## Description

给 $n$ 个数 `a[1] ~ a[n]`，求 `(a[i] + a[j]) ⊕ a[k]` 的最大值，其中 `i, j, k` 为互不相同的序号，“⊕”表示按位异或。

## Input

多组数据，每组数据第一行一个 n ，第二行 n 个正整数 `a[i]`。

其中 `3 <= n <= 2000`， `0 <= a[i] <= 10^9`。

## Output

每组数据输出最大的结果。

## Sample Input

```
3
3 1 2
5
1 7 6 8 9
```

## Sample Output

```
6
24
```

[参考代码](../Solution/I.cpp)


# F : 模拟计算器

Time Limit: `1 Sec`, Memory Limit: `128 Mb`

## Description

给出 $n$ 个数，和 $n-1$个运算符（只含有加减乘号，不含除号，按顺序填入 $n$ 个数之间），要求输出该式的答案。

## Input

单组数据。

第一行为 $n$（$2 \leq n \leq 100$），且 $n$ 为整数。

第二行为 $n$ 个数，每个数 $a$ 保证 $1 \leq a \leq 10$，且为整数。

第三行为 $n-1$个运算符，运算符之间由空格隔开。

## Output

如题。

## Sample Input

```
4
1 2 3 4
+ * -
```

## Sample Output

```
3
```

## Hint

1 + 2 * 3 - 4 = 3

[参考代码](../Solution/F.cpp)

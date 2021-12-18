# A : A*B

Time Limit: `2 Sec`,   Memory Limit: `200 Mb`

## Description

如题，计算A*B的值并输出。

## Input

两行，分别代表A和B。

A和B的位数不超过2000位。

## Output

一行一个整数表示乘积。

## Sample Input

```
1 
2
```

## Sample Output

```
2
```

## Hint

普通高精度乘法可以过， 但你也可以试试看分治优化的高精度乘法

- $X = A2^{n/2} + B, Y = C2^{n/2} + D$
- $XY = AC2^n + (AD + BC)2^{n/2} + BD$
- $AD+BC=(A-B)(D-C)+AC+BD$


[参考代码](../Solution/A.cpp)
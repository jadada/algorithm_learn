# I : 汉诺塔

Time Limit: `2 Sec`,   Memory Limit: `1024 Mb`

## Description

 汉诺塔，是一个源于印度的玩具。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。

 现在给你一个n片圆盘的汉诺塔，并从小到大编号为1

至*n*。请你输出搬动*n*个圆盘最少次数的全过程。

- 1 ≤ *n* ≤ 10

## Input

*n*

## Output

输出搬动圆盘最少次数的全过程，格式见案例。

## Sample Input

```
3
```

## Sample Output

```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```


[参考代码](../Solution/I.cpp)
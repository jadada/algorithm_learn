# D : 单设备区间调度

Time Limit: `1 Sec`   Memory Limit: `128 Mb`

## Description

给出调度任务的开始时间和结束时间*l*,*r*，同一时间段仅能调度一个任务，要求最多能调度多少个任务

## Input

多组输入，每组输入第一行包含一个正整数*t*(*t* ≤ 100)，代表共有*t*个调度任务。接下来输入*t*行，每一行包含两个正整数*l*和*r*(0 ≤ *l* < *r* ≤ $10^9$)，分别一个调度任务的开始时间和结束时间*l*,*r*。当*t* = 0时，代表输入结束，不做处理。

## Output

对于每个测试实例，输出能调度的最多任务的个数，每个实例的输出占一行

## Sample Input

```
5
1 3
3 6
2 4
4 7
6 9
0
```

## Sample Output

```
3
```

[参考代码](../Solution/D.cpp)


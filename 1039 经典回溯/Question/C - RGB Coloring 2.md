# C : RGB Coloring 2

Time Limit: `1 Sec`,   Memory Limit: `128 Mb`

## Description

We have a simple undirected graph with *N* vertices and *M* edges. The vertices are numbered 1 through *N* and the edges are numbered 1 through *M*. Edge *i* connects Vertex $A_i$ and Vertex $B_i$. Find the number of ways to paint each vertex in this graph red, green, or blue so that the following condition is satisfied:

- two vertices directly connected by an edge are always painted in different colors.

Here, it is not mandatory to use all the colors.

## Input

Input is given from Standard Input in the following format:

$N\text{ }M$

$A_1\text{ }B_1$

$A_2\text{ }B_2$

 .

$A_M\text{ }B_M$

### 

## Output

Print the answer.

## Sample Input

```
3 3
1 2
2 3
3 1
```

## Sample Output

```
6
```

## Hint

### 数据范围

- $1 \leq N \leq20$
- $0≤M≤\frac{N(N−1)}{2}$
- $1 \leq A_i \leq N$
- $1 \leq B_i \leq N$
- The given graph is simple (that is, has no multi-edges and no self-loops).
- Note that the graph may not be connected.



[参考代码](../Solution/C.cpp)
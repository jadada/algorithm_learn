/* 
C - 斐波那契数列

reference:
https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/fei-bo-na-qi-shu-lie-by-leetcode-solutio-hbss/
 */
#include <bits/stdc++.h>
using namespace std;

int fib( int n ) {
    if ( n < 2 ) return n;

    int p = 0, q = 0, r = 1;
    for ( int i = 2; i <= n; ++i ) {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}

int main() {
    int a, b;
    while ( scanf( "%d%d", &a, &b ) != EOF ) {
        printf( "%d\n", fib( b ) - fib( a ) );
    }
    return 0;
}

/*
Sample Input
0 1 
2 3
3 4

Sample Output
1
1
1
*/
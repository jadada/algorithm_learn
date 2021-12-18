/*
A - 打家劫舍问题

reference:
https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-leetcode-solution/
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;

int get_max( Array &values ) {
    if ( values.empty() ) return 0;

    if ( 1 == values.size() ) return values[ 0 ];

    int first = values[ 0 ];
    int second = std::max( values[ 0 ], values[ 1 ] );
    for ( int i = 2; i < values.size(); ++i ) {
        int temp = second;
        second = std::max( first + values[ i ], second );
        first = temp;
    }
    return second;
}

int main() {
    int N;
    while ( scanf( "%d", &N ) != EOF ) {
        Array values( N );
        for ( int i = 0; i < N; ++i )
            scanf( "%d", &values[ i ] );

        printf( "%d\n", get_max( values ) );
    }

    return 0;
}

/* 
Sample Input
4
1 3 2 1
5
2 7 9 3 1

Sample Output
4
12
 */
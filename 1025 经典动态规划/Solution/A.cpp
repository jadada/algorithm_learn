/* 
A - 数字三角形
 */
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using Array = vector<int>;

void display( Array &nums, int N ) {
    for ( int i = N; i >= 1; --i ) {
        for ( int j = ( i - 1 ) * i / 2; j < ( i + 1 ) * i / 2; ++j )
            printf( "%d ", nums[ j ] );
        printf( "\n" );
    }
}

int get_max_sum( Array &nums, int N ) {
    if ( nums.empty() ) return 0;
    if ( nums.size() == 1 ) return nums[ 0 ];

    for ( int i = N - 1; i >= 1; --i ) {
        for ( int j = ( i - 1 ) * i / 2; j < ( i + 1 ) * i / 2; ++j ) {
            int left = j + i;
            int right = left + 1;
            nums[ j ] += std::max( nums[ left ], nums[ right ] );
        }
    }

#ifdef DEBUG
    display( nums, N );
#endif

    return nums[ 0 ];
}

int main() {
    int T, N;
    scanf( "%d", &T );
    while ( T-- > 0 && scanf( "%d", &N ) != EOF ) {
        int len = ( N + 1 ) * N / 2;
        Array nums( len );
        for ( int i = 0; i < len; ++i )
            scanf( "%d", &nums[ i ] );

        printf( "%d\n", get_max_sum( nums, N ) );
    }

    return 0;
}

/* 
Sample Input
1
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5

Sample Output
30
 */
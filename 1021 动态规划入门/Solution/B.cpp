/*
B - 最大子序列和
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;

int max_seq_sum( Array &nums ) {
    if ( nums.empty() ) return 0;

    if ( 1 == nums.size() ) return nums[ 0 ];

    int seq_max = nums[ 0 ];
    int max = seq_max;
    for ( int i = 1; i < nums.size(); ++i ) {
        seq_max = std::max( seq_max + nums[ i ], nums[ i ] );
        max = ( seq_max > max ) ? seq_max : max;
    }
    return max;
}

int main() {
    int N;
    while ( scanf( "%d", &N ) != EOF ) {
        Array nums( N );
        for ( int i = 0; i < N; ++i )
            scanf( "%d", &nums[ i ] );

        printf( "%d\n", max_seq_sum( nums ) );
    }
    return 0;
}

/* 
Sample Input
9
-2 1 -3 4 -1 2 1 -5 4

Sample Output
6
 */
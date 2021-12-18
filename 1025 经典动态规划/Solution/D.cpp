/*
D - 连续数组最大和问题
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;

void find_max_seq( Array &nums ) {

    int n = nums.size();
    Array S( n ), E( n ), dp( n );

    dp[ 0 ] = nums[ 0 ];
    for ( int i = 1; i < n; ++i ) {
        if ( dp[ i - 1 ] <= 0 ) {
            S[ i ] = i;
            E[ i ] = i;
            dp[ i ] = nums[ i ];
        } else {
            S[ i ] = S[ i - 1 ];
            E[ i ] = i;
            dp[ i ] = dp[ i - 1 ] + nums[ i ];
        }
    }

    int best_index = 0;
    int best = dp[ 0 ];
    for ( int i = 1; i < n; ++i ) {
        if ( dp[ i ] > best ) {
            best = dp[ i ];
            best_index = i;
        }
    }

    int start = nums[ S[ best_index ] ];
    int end = nums[ E[ best_index ] ];
    printf( "%d %d %d\n", dp[ best_index ], start, end );
}

int main() {
    int N;
    while ( scanf( "%d", &N ) != EOF && N != 0 ) {
        bool isAllNegative = true;

        Array nums( N );
        for ( int i = 0; i < N; ++i ) {
            scanf( "%d", &nums[ i ] );

            if ( nums[ i ] >= 0 ) isAllNegative = false;
        }

        if ( isAllNegative )
            printf( "%d %d %d\n", 0, nums[ 0 ], nums[ N - 1 ] );
        else
            find_max_seq( nums );
    }
    return 0;
}

/*
Sample Input
6
-2 11 -4 13 -5 -2
10
-10 1 2 3 4 -5 -23 3 7 -21
6
5 -8 3 2 5 0
1
10
3
-1 -5 -2
3
-1 0 -2
0

Sample Output
20 11 13
10 1 4
10 3 5
10 10 10
0 -1 -2
0 0 0
 */
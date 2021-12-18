/*
F - 合并石子

reference:
https://www.cnblogs.com/onetrainee/p/11955567.html
https://blog.csdn.net/weixin_43899069/article/details/111469996
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;
using Matrix = vector<Array>;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

Matrix dp_min( MAXN, Array( MAXN, INF ) );
Matrix dp_max( MAXN, Array( MAXN ) );
Array costs( MAXN );

void merge( Array &arr, int n ) {
    for ( int i = 1; i <= 2 * n; ++i )
        costs[ i ] = costs[ i - 1 ] + arr[ i ];

    for ( int len = 2; len <= n; ++len ) {
        for ( int i = 1; len + i - 1 <= 2 * n; ++i ) {
            int j = len + i - 1;
            for ( int k = i; k < j; ++k ) {
                dp_min[ i ][ j ] = std::min(
                    dp_min[ i ][ j ], dp_min[ i ][ k ] + dp_min[ k + 1 ][ j ] +
                                          costs[ j ] - costs[ i - 1 ] );
                dp_max[ i ][ j ] = std::max(
                    dp_max[ i ][ j ], dp_max[ i ][ k ] + dp_max[ k + 1 ][ j ] +
                                          costs[ j ] - costs[ i - 1 ] );
            }
        }
    }

    int ans_min = INF;
    int ans_max = -1;
    for ( int i = 1; i <= n; i++ ) {
        ans_min = min( ans_min, dp_min[ i ][ i + n - 1 ] );
        ans_max = max( ans_max, dp_max[ i ][ i + n - 1 ] );
    }

    printf( "%d\n", ans_min );
    printf( "%d\n", ans_max );
}

int main() {
    int N;
    scanf( "%d", &N );

    Array arr( 2 * N + 1 );
    for ( int i = 1; i <= N; ++i ) {
        scanf( "%d", &arr[ i ] );
        arr[ i + N ] = arr[ i ];
        dp_min[ i ][ i ] = 0;
        dp_min[ i + N ][ i + N ] = 0;
    }

    merge( arr, N );

    return 0;
}

/* 
Sample Input
4
4 5 9 4

Sample Output
43
54
 */
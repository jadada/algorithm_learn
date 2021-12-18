/*
D - 矩阵链相乘
 */
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using Array = vector<int>;
using Matrix = vector<Array>;

const int MAXN = 310;

Matrix m( MAXN, Array( MAXN ) );
Matrix s( MAXN, Array( MAXN ) );

void matrix_chain( Array &arr, int n ) {
    if ( arr.empty() ) return;

    for ( int r = 2; r <= n; ++r ) {
        for ( int i = 1; i <= ( n - r + 1 ); ++i ) {
            int j = i + r - 1;
            m[ i ][ j ] = m[ i + 1 ][ j ] + arr[ i - 1 ] * arr[ i ] * arr[ j ];
            s[ i ][ j ] = i;

            for ( int k = i + 1; k < j; ++k ) {
                int temp = m[ i ][ k ] + m[ k + 1 ][ j ] +
                           arr[ i - 1 ] * arr[ k ] * arr[ j ];
                if ( temp < m[ i ][ j ] ) {
                    m[ i ][ j ] = temp;
                    s[ i ][ j ] = k;
                }
            }
        }
    }

#ifdef DEBUG
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n; ++j )
            printf( "%8d", m[ i ][ j ] );
        printf( "\n" );
    }
#endif
}

int main() {
    int n;
    while ( scanf( "%d", &n ) != EOF ) {
        Array arr( n + 1 );
        for ( int i = 0; i <= n; ++i )
            scanf( "%d", &arr[ i ] );

        matrix_chain( arr, n );
        printf( "%d\n", m[ 1 ][ n ] );
    }
    return 0;
}

/*
Sample Input
5
74 16 58 58 88 80
5
10 1 50 50 20 5

Sample Output
342848
3650
 */
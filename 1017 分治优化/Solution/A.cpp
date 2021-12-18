/*
A - AxB

reference:
https://oi-wiki.org/math/poly/fft/
https://paste.ubuntu.com/p/hmK9JR6SgT/
*/
#include <bits/stdc++.h>
using namespace std;

using Complex = std::complex<double>;

const double PI = acos( -1.0 );
const int MAXN = 2e5 + 20;
char a[ MAXN ], b[ MAXN ];
Complex xa[ MAXN ], xb[ MAXN ];

void bit_reverse( Complex N[], int len ) {
    // len should be 2^k
    int i, j, k;
    for ( int i = 1, j = len / 2; i < len - 1; i++ ) {
        if ( i < j ) std::swap( N[ i ], N[ j ] );

        k = len / 2;
        while ( j >= k ) {
            j = j - k;
            k = k / 2;
        }

        if ( j < k ) j += k;
    }
}

void fft( Complex N[], int len, int on ) {
    // on == 1: DFT; on == -1: IDFT; len should be 2^k
    bit_reverse( N, len );
    for ( int h = 2; h <= len; h <<= 1 ) {
        Complex wn( cos( 2 * PI / h ), sin( on * 2 * PI / h ) );
        for ( int j = 0; j < len; j += h ) {
            Complex w( 1, 0 );
            for ( int k = j; k < j + h / 2; k++ ) {
                Complex u = N[ k ];
                Complex t = w * N[ k + h / 2 ];
                N[ k ] = u + t;
                N[ k + h / 2 ] = u - t;
                w = w * wn;
            }
        }
    }

    if ( on == -1 ) {
        for ( int i = 0; i < len; i++ )
            N[ i ].real( N[ i ].real() / len );
    }
}

int main() {
    while ( scanf( "%s%s", a, b ) != EOF ) {
        int len1 = strlen( a ), len2 = strlen( b );
        int len = 1;
        while ( len < len1 * 2 || len < len2 * 2 )
            len <<= 1;

        for ( int i = 0; i < len1; i++ )
            xa[ i ] = a[ len1 - i - 1 ] - '0';
        for ( int i = 0; i < len2; i++ )
            xb[ i ] = b[ len2 - i - 1 ] - '0';

        for ( int i = len1; i < len; i++ )
            xa[ i ] = 0;
        for ( int i = len2; i < len; i++ )
            xb[ i ] = 0;

        fft( xa, len, 1 );
        fft( xb, len, 1 );

        for ( int i = 0; i < len; i++ )
            xa[ i ] *= xb[ i ];
        fft( xa, len, -1 );

        for ( int i = 0; i < len; i++ ) {
            a[ i ] = int( xa[ i ].real() + 0.5 ) % 10 + '0';
            xa[ i + 1 ].real( xa[ i + 1 ].real() +
                              int( xa[ i ].real() + 0.5 ) / 10 );
        }

        for ( len1 = len - 1; a[ len1 ] == '0' && len1 > 0; len1-- )
            ;
        for ( ; len1 >= 0 && printf( "%c", a[ len1 ] ); len1-- )
            ;
        printf( "\n" );
    }
    return 0;
}

/*
Input:
1
2

Output:
2
*/
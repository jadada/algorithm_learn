/*
B - 矩阵相乘

refernce:
https://www.cnblogs.com/wuyudong/p/matrix-multiply
 */
#include <bits/stdc++.h>
using namespace std;

using Vec = vector<int>;
using Vec2d = vector<Vec>;

void display( Vec2d &M, int n ) {
    // printf("\n");
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j )
            printf( "%d ", M[ i ][ j ] );
        printf( "\n" );
    }
}

// 二维方阵乘法
void multiply_2nd( Vec2d &A, Vec2d &B, Vec2d &R ) {
    int M1 = A[ 0 ][ 0 ] * ( B[ 0 ][ 1 ] - B[ 1 ][ 1 ] );
    int M2 = ( A[ 0 ][ 0 ] + A[ 0 ][ 1 ] ) * B[ 1 ][ 1 ];
    int M3 = ( A[ 1 ][ 0 ] + A[ 1 ][ 1 ] ) * B[ 0 ][ 0 ];
    int M4 = A[ 1 ][ 1 ] * ( B[ 1 ][ 0 ] - B[ 0 ][ 0 ] );
    int M5 = ( A[ 0 ][ 0 ] + A[ 1 ][ 1 ] ) * ( B[ 0 ][ 0 ] + B[ 1 ][ 1 ] );
    int M6 = ( A[ 0 ][ 1 ] - A[ 1 ][ 1 ] ) * ( B[ 1 ][ 0 ] + B[ 1 ][ 1 ] );
    int M7 = ( A[ 0 ][ 0 ] - A[ 1 ][ 0 ] ) * ( B[ 0 ][ 0 ] + B[ 0 ][ 1 ] );

    R[ 0 ][ 0 ] = M5 + M4 - M2 + M6;
    R[ 0 ][ 1 ] = M1 + M2;
    R[ 1 ][ 0 ] = M3 + M4;
    R[ 1 ][ 1 ] = M5 + M1 - M3 - M7;
}

void add( int n, Vec2d &A, Vec2d &B, Vec2d &R ) {
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j )
            R[ i ][ j ] = A[ i ][ j ] + B[ i ][ j ];
    }
}

void sub( int n, Vec2d &A, Vec2d &B, Vec2d &R ) {
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j )
            R[ i ][ j ] = A[ i ][ j ] - B[ i ][ j ];
    }
}

void strassen( int n, Vec2d &A, Vec2d &B, Vec2d &R ) {
    int n_ = n / 2;

    Vec2d A11( n_, Vec( n_ ) );
    Vec2d A12( n_, Vec( n_ ) );
    Vec2d A21( n_, Vec( n_ ) );
    Vec2d A22( n_, Vec( n_ ) );

    Vec2d B11( n_, Vec( n_ ) );
    Vec2d B12( n_, Vec( n_ ) );
    Vec2d B21( n_, Vec( n_ ) );
    Vec2d B22( n_, Vec( n_ ) );

    Vec2d R11( n_, Vec( n_ ) );
    Vec2d R12( n_, Vec( n_ ) );
    Vec2d R21( n_, Vec( n_ ) );
    Vec2d R22( n_, Vec( n_ ) );

    Vec2d tempA( n_, Vec( n_ ) );
    Vec2d tempB( n_, Vec( n_ ) );

    Vec2d M1( n_, Vec( n_ ) );
    Vec2d M2( n_, Vec( n_ ) );
    Vec2d M3( n_, Vec( n_ ) );
    Vec2d M4( n_, Vec( n_ ) );
    Vec2d M5( n_, Vec( n_ ) );
    Vec2d M6( n_, Vec( n_ ) );
    Vec2d M7( n_, Vec( n_ ) );

    if ( n == 2 ) {
        multiply_2nd( A, B, R );
    } else {
        for ( int i = 0; i < n_; ++i ) {
            for ( int j = 0; j < n_; ++j ) {
                A11[ i ][ j ] = A[ i ][ j ];
                A12[ i ][ j ] = A[ i ][ j + n_ ];
                A21[ i ][ j ] = A[ i + n_ ][ j ];
                A22[ i ][ j ] = A[ i + n_ ][ j + n_ ];

                B11[ i ][ j ] = B[ i ][ j ];
                B12[ i ][ j ] = B[ i ][ j + n_ ];
                B21[ i ][ j ] = B[ i + n_ ][ j ];
                B22[ i ][ j ] = B[ i + n_ ][ j + n_ ];
            }
        }

        // M1 = A11(B12 - B22)
        sub( n_, B12, B22, tempB );
        strassen( n_, A11, tempB, M1 );

        // M2 = (A11+A12)B22
        add( n_, A11, A12, tempA );
        strassen( n_, tempA, B22, M2 );

        // M3 = (A21+A22)B11
        add( n_, A21, A22, tempA );
        strassen( n_, tempA, B11, M3 );

        // M4 = A22(B21-B11)
        sub( n_, B21, B11, tempB );
        strassen( n_, A22, tempB, M4 );

        // M5 = (A11+A22)(B11+B22)
        add( n_, A11, A22, tempA );
        add( n_, B11, B22, tempB );
        strassen( n_, tempA, tempB, M5 );

        // M6 = (A12-A22)(B21+B22)
        sub( n_, A12, A22, tempA );
        add( n_, B21, B22, tempB );
        strassen( n_, tempA, tempB, M6 );

        // M7 = (A11-A21)(B11+B12)
        sub( n_, A11, A21, tempA );
        add( n_, B11, B12, tempB );
        strassen( n_, tempA, tempB, M7 );

        // R11 = M5 + M4 - M2 + M6
        add( n_, M5, M4, tempA );
        sub( n_, M6, M2, tempB );
        add( n_, tempA, tempB, R11 );

        // R12 = M1 + M2
        add( n_, M1, M2, R12 );

        // R21 = M3 + M4
        add( n_, M3, M4, R21 );

        // R22 = M5 + M1 - M3 - M7
        add( n_, M5, M1, tempA );
        add( n_, M3, M7, tempB );
        sub( n_, tempA, tempB, R22 );

        for ( int i = 0; i < n_; ++i ) {
            for ( int j = 0; j < n_; ++j ) {
                R[ i ][ j ] = R11[ i ][ j ];
                R[ i ][ j + n_ ] = R12[ i ][ j ];
                R[ i + n_ ][ j ] = R21[ i ][ j ];
                R[ i + n_ ][ j + n_ ] = R22[ i ][ j ];
            }
        }
    }
}

int main() {
    int n;
    scanf( "%d", &n );

    Vec2d A( n, Vec( n ) );
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j )
            scanf( "%d", &A[ i ][ j ] );
    }

    Vec2d B( n, Vec( n ) );
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j )
            scanf( "%d", &B[ i ][ j ] );
    }

    Vec2d C( n, Vec( n ) );
    strassen( n, A, B, C );
    display( C, n );
    return 0;
}

/*
Sample Input
2
1 2
3 4
0 1
0 0

Sample Output
0 1
0 3
*/
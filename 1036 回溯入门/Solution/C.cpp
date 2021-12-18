/*
C - 自然数的拆分问题

reference:
https://www.luogu.com.cn/blog/user67087/solution-p2404
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> dp( 16 );

int n;

void display( int t ) {
    for ( int i = 1; i <= t - 1; ++i ) {
        printf( "%d+", dp[ i ] );
    }
    printf( "%d\n", dp[ t ] );
}

void breakdown( int s, int t ) {
    for ( int i = dp[ t - 1 ]; i <= s; ++i ) {
        if ( i < n ) {
            dp[ t ] = i;
            s -= i;

            if ( s == 0 )
                display( t );
            else
                breakdown( s, t + 1 );

            s += i;
        }
    }
}

int main() {
    dp[ 0 ] = 1;
    scanf( "%d", &n );
    breakdown( n, 1 );

    return 0;
}

/*
Sample Input
7

Sample Output
1+1+1+1+1+1+1
1+1+1+1+1+2
1+1+1+1+3
1+1+1+2+2
1+1+1+4
1+1+2+3
1+1+5
1+2+2+2
1+2+4
1+3+3
1+6
2+2+3
2+5
3+4
 */
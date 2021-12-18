/*
G - 查找[二分]
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000010;
int nums[ MAXN ];
int Query[ MAXN ];

int search( int q, int n ) {
    int len = n;
    int ret = -1;

    int l = 1, r = len;
    while ( len > 0 ) {
        if ( nums[ l ] >= q ) {
            ret = l;
            break;
        }

        int mid = l + ( r - l ) / 2;
        if ( nums[ mid ] < q ) {
            l = mid + 1;
        } else {
            l += 1;
            r = mid;
        }

        len = r - l + 1;
    }
    return ret;
}

int main() {
    int N, M;
    scanf( "%d %d", &N, &M );

    for ( int i = 1; i <= N; ++i )
        scanf( "%d", &nums[ i ] );

    for ( int i = 0; i < M; ++i ) {
        scanf( "%d", &Query[ i ] );
        printf( "%d\n", search( Query[ i ], N ) );
    }

    return 0;
}

/*
input:
5 3
1 3 5 7 9
1
3
6

output:
1
2
4
*/
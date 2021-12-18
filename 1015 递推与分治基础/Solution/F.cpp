/*
F - 区间和
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;

long long nums[ MAXN ];
long long sums[ MAXN ];

int main() {
    long long N, M;
    scanf( "%lld %lld", &N, &M );

    nums[ 0 ] = sums[ 0 ] = 0;
    for ( long long i = 1; i <= N; ++i )
        scanf( "%lld", &nums[ i ] );

    sums[ 1 ] = nums[ 1 ];

    for ( long long i = 2; i <= N; ++i )
        sums[ i ] = sums[ i - 1 ] + nums[ i ];

    for ( long long i = 0; i < M; ++i ) {
        long long l, r;
        scanf( "%lld %lld", &l, &r );
        printf( "%lld\n", sums[ r ] - sums[ l - 1 ] );
    }

    return 0;
}

/*
input:
5 8
1 2 3 4 5
1 3
2 5
2 3
1 1
5 5
1 5
3 4
4 5

output:
6
14
5
1
5
15
7
9
*/
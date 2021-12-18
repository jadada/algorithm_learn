/* 
C - 最小延迟调度问题
 */
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using Pair = pair<int, int>;
using Item = vector<Pair>;

struct {
    bool operator()( const Pair &a, const Pair &b ) const {
        return a.second < b.second;
    }
} compare_second;

int main() {
    int t;
    scanf( "%d", &t );
    while ( t-- ) {
        int n;
        scanf( "%d", &n );

        Item jobs( n );
        for ( int i = 0; i < n; ++i )
            scanf( "%d%d", &jobs[ i ].first, &jobs[ i ].second );

        std::sort( jobs.begin(), jobs.end(), compare_second );

        int finish_time = 0;
        int max_time = 0;
        for ( int i = 0; i < n; ++i ) {
            finish_time += jobs[ i ].first;
            int latency = finish_time - jobs[ i ].second;

            if ( latency > 0 )
                max_time = ( latency > max_time ) ? latency : max_time;
        }

        printf( "%d\n", max_time );
    }

    return 0;
}

/*
Sample Input
1
6
3 6
2 8
1 9
4 9
3 14
2 15

Sample Output
1
 */
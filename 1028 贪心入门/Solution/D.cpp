/*
D - 单设备区间调度
 */
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using Pair = pair<int, int>;
using Item = vector<Pair>;
using Array = vector<int>;

struct {
    bool operator()( const Pair &a, const Pair &b ) const {
        return a.second < b.second;
    }
} compare_second;

int main() {
    int t;
    while ( scanf( "%d", &t ) != EOF && t != 0 ) {
        Item items( t );
        for ( int i = 0; i < t; ++i )
            scanf( "%d%d", &items[ i ].first, &items[ i ].second );

        std::sort( items.begin(), items.end(), compare_second );

#ifdef DEBUG
        printf( "\n" );
        for ( int i = 0; i < t; ++i )
            printf( "%d %d\n", items[ i ].first, items[ i ].second );
        printf( "\n" );
#endif

        int cnt = 0;
        Array dp( t, -1 );
        for ( int i = 0; i < t; ++i ) {
            if ( items[ i ].first >= dp[ cnt ] ) {
                ++cnt;
                dp[ cnt ] = items[ i ].second;
#ifdef DEBUG
                printf( "[%d] %d (%d %d)\n", cnt, dp[ cnt ], items[ i ].first,
                        items[ i ].second );
#endif
            }
        }
        printf( "%d\n", cnt );
    }
    return 0;
}

/*
Sample Input
5
1 3
3 6
2 4
4 7
6 9
0

Sample Output
3
 */
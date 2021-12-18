/*
B - XHD来寻宝
 */
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using Pair = pair<int, int>;
using Item = vector<Pair>;

struct {
    bool operator()( const Pair &a, const Pair &b ) const {
        return a.first < b.first;
    }
} compare_first;

int main() {
    int v; // capacity of pocket
    while ( scanf( "%d", &v ) != EOF && v != 0 ) {
        int n; // kinds of treasure
        scanf( "%d", &n );

        Item item( n );
        for ( int i = 0; i < n; ++i )
            scanf( "%d%d", &item[ i ].first,
                   &item[ i ].second ); // first-price, second-volume

        std::sort( item.rbegin(), item.rend(),
                   compare_first ); // sort by item price

#ifdef DEBUG
        printf( "\n" );
        for ( int i = 0; i < n; ++i )
            printf( "%d %d\n", item[ i ].first, item[ i ].second );
        printf( "\n" );
#endif

        int total_value = 0;
        for ( int i = 0; v > 0 && i < n; ++i ) {
            int w = ( v < item[ i ].second )
                        ? v
                        : item[ i ].second; // the volume can take
            total_value += item[ i ].first * w;
            v -= w;

#ifdef DEBUG
            printf( "[%d] %d %d | %d\n", i, w, v, total_value );
#endif
        }
        printf( "%d\n", total_value );
    }
    return 0;
}

/*
Sample Input
2 2
3 1
2 3
0

Sample Output
5
 */
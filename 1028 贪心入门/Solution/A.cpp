/*
A - 买最多
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
    int t;
    scanf( "%d", &t );
    while ( t-- ) {
        int n, m; // n-total money, m-kinds of items
        scanf( "%d%d", &n, &m );

        Item item( m );
        for ( int i = 0; i < m; ++i )
            scanf( "%d%d", &item[ i ].first,
                   &item[ i ].second ); // first-price, second-total weight

        std::sort( item.begin(), item.end(),
                   compare_first ); // sort by item price

#ifdef DEBUG
        printf( "\n" );
        for ( int i = 0; i < m; ++i )
            printf( "%d %d\n", item[ i ].first, item[ i ].second );
        printf( "\n" );
#endif

        double total_weight = 0.0;
        double money_left = n;
        for ( int i = 0; money_left > 0 && i < m; ++i ) {
            double w = money_left /
                       item[ i ].first; // the money left can buy w item[i]
            w = ( w < item[ i ].second ) ? w : item[ i ].second;
            total_weight += w;
            money_left -= w * item[ i ].first;

#ifdef DEBUG
            printf( "[%d] %lf %lf | %lf\n", i, w, money_left, total_weight );
#endif
        }
        printf( "%.2lf\n", total_weight );
    }
    return 0;
}

/*
Sample Input
1
6 3
4 2
3 2
2 2

Sample Output
2.67
 */
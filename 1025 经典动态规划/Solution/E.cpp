/* 
E - 01饭卡

reference:
https://www.cnblogs.com/-Ackerman/p/12253268.html
https://docs.qq.com/pdf/DRHdIcGltTllSVVVp
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;

int ZeroOnePack( Array &prices, int total ) {
    int n = prices.size();
    Array dp( total + 1 );

    std::sort( prices.begin(), prices.end() );

    for ( int i = 1; i < n; ++i ) {
        for ( int j = total - 5; j >= prices[ i - 1 ]; --j )
            dp[ j ] = std::max( dp[ j ],
                                dp[ j - prices[ i - 1 ] ] + prices[ i - 1 ] );
    }

    return total - dp[ total - 5 ] - prices[ n - 1 ];
}

int main() {
    int n, m;
    while ( scanf( "%d", &n ) != EOF && n != 0 ) {
        Array prices( n );
        for ( int i = 0; i < n; ++i )
            scanf( "%d", &prices[ i ] );

        scanf( "%d", &m );

        if ( m < 5 )
            printf( "%d\n", m );
        else
            printf( "%d\n", ZeroOnePack( prices, m ) );
    }

    return 0;
}

/* 
Sample Input
1
50
5
10
1 2 3 2 1 1 2 3 2 1
50
0

Sample Output
-45
32
 */
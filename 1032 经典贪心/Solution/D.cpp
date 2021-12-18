/* 
D - 最优装载
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf( "%d", &t );
    while ( t-- ) {
        int n, m;
        scanf( "%d%d", &n, &m );

        vector<int> w( m );
        for ( int i = 0; i < m; i++ )
            scanf( "%d", &w[ i ] );

        std::sort( w.begin(), w.end() );

        int ans = 0;
        for ( int i = 0; i < m; ++i ) {
            if ( n >= w[ i ] ) {
                n -= w[ i ];
                ++ans;
            }
        }
        printf( "%d\n", ans );
    }
    return 0;
}

/* 
Sample Input
1
10 4
3
4
5
6

Sample Output
2
 */
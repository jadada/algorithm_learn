/* 
C - 招募员工

reference:
https://blog.csdn.net/consciousman/article/details/53812818
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 30, M = 1010;
const int INF = 0x3f3f3f3f;

struct edge {
    int v, d, next;
    edge( int v, int d, int n )
        : v( v )
        , d( d )
        , next( n ) {}
    edge() {}
} ed[ M ];

int k;
vector<int> head, d, R, tim;
vector<bool> visited;
queue<int> q;

void init() {
    k = 0;
    head = vector<int>( N, -1 );
    d = vector<int>( N, -INF );
    visited = vector<bool>( N, false );

    while ( !q.empty() )
        q.pop();
}

void add( int u, int v, int d ) {
    ed[ k ] = edge( v, d, head[ u ] );
    head[ u ] = k++;
}

int cal( int m ) {
    q.push( 0 );
    d[ 0 ] = 0;
    while ( !q.empty() ) {
        int x = q.front();
        q.pop();

        visited[ x ] = false;
        if ( x == 24 && d[ x ] > m ) return 0;
        for ( int i = head[ x ]; i != -1; i = ed[ i ].next ) {
            int t = ed[ i ].v;
            if ( d[ t ] < d[ x ] + ed[ i ].d ) {
                d[ t ] = d[ x ] + ed[ i ].d;
                if ( !visited[ t ] ) {
                    visited[ t ] = true;
                    q.push( t );
                }
            }
        }
    }
    return d[ 24 ] == m ? 1 : 0;
}

int main() {
    int t;
    cin >> t;
    while ( t-- ) {
        R = vector<int>( N );
        for ( int i = 0; i < 24; i++ )
            cin >> R[ i ];

        int n;
        cin >> n;

        tim = vector<int>( N );
        for ( int i = 0; i < n; i++ ) {
            int tmp;
            cin >> tmp;
            tim[ tmp ]++;
        }
        int r = n + 1, l = -1;
        while ( r - l > 1 ) {
            int m = ( r + l ) / 2;
            init();
            for ( int i = 0; i <= 23; i++ )
                add( i + 1, i, -tim[ i ] ), add( i, i + 1, 0 );
            for ( int i = 7; i <= 23; i++ )
                add( i - 7, i + 1, R[ i ] );

            add( 0, 24, m );
            add( 24, 0, -m );

            for ( int i = 0; i < 7; i++ )
                add( i + 17, i + 1, R[ i ] - m );
            cal( m ) ? r = m : l = m;
        }
        l >= n ? puts( "No Solution" ) : printf( "%d\n", r );
    }
    return 0;
}

/*
Sample Input
1
1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
5
0
23
22
1
10

Sample Output
1
*/
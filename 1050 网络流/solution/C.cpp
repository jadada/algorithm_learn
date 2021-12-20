/*
C - 最小割点
*/
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using Array = vector<int>;

const int maxn = 1e4 + 3, maxm = 1e5 + 3;
const LL inf = 1ll << 62;

int n, m, s, t, cnt;
Array head( maxn ), d( maxn ), cur( maxn );

struct Edge {
    int to, next;
    LL cap;
    Edge( int to = -1, int next = -1, int cap = -1 )
        : to( to )
        , next( next )
        , cap( cap ) {}
} edge[ maxm << 1 ];

void Link( int u, int v, int w ) {
    edge[ ++cnt ] = Edge( v, head[ u ], w );
    head[ u ] = cnt;
}

void addlink( int u, int v, int w ) { Link( u, v, w ), Link( v, u, 0 ); }

inline bool bfs() {
    queue<int> q;
    for ( int i = 0; i <= n; i++ )
        cur[ i ] = head[ i ];
    d = Array( maxn, 0 );
    q.push( s ), d[ s ] = 1;
    while ( q.size() ) {
        int u = q.front();
        q.pop();
        for ( int i = head[ u ]; i; i = edge[ i ].next ) {
            int v = edge[ i ].to, w = edge[ i ].cap;
            if ( d[ v ] || !w ) continue;
            d[ v ] = d[ u ] + 1;
            q.push( v );
        }
    }
    return d[ t ];
}

LL dfs( int u, LL flow ) {
    if ( u == t ) return flow;
    LL rest = flow, f;
    for ( int i = cur[ u ]; i && rest; i = edge[ i ].next ) {
        cur[ u ] = i;
        int v = edge[ i ].to;
        LL w = edge[ i ].cap;
        if ( d[ u ] + 1 != d[ v ] || w <= 0 ) continue;
        f = dfs( v, min( rest, w ) );
        if ( f == 0 ) d[ v ] = 0;
        rest -= f;
        edge[ i ].cap -= f;
        edge[ i ^ 1 ].cap += f;
    }
    return flow - rest;
}

LL Dinic() {
    LL max_flow = 0, f;
    while ( bfs() )
        while ( f = dfs( s, inf ) )
            max_flow += f;
    return max_flow;
}

int main() {
    while ( cin >> n >> m ) {
        head = Array( maxn, 0 );
        cnt = 1;
        n = 2 * n + 1;
        while ( m-- ) {
            int u, v;
            cin >> u >> v;
            addlink( 2 * u, 2 * u + 1, 1 );
            addlink( 2 * v, 2 * v + 1, 1 );
            addlink( 2 * u + 1, 2 * v, 1 );
            addlink( 2 * v + 1, 2 * u, 1 );
        }
        s = 2, t = 5;
        cout << Dinic() << endl;
    }
    return 0;
}

/*
Sample Input
4 3
1 3
2 4
3 4

Sample Output
1
*/
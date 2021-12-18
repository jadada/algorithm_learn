/* 
A - 最大流问题

reference:
https://oi-wiki.org/graph/flow/max-flow/
 */
#include <bits/stdc++.h>
using namespace std;

namespace dicnic {
const int maxn = 250;
const int INF = 0x3f3f3f3f;

struct Edge {
    int from, to, cap, flow;
    Edge( int u, int v, int c, int f )
        : from( u )
        , to( v )
        , cap( c )
        , flow( f ) {}
};

struct Dinic {
    // n：点数，m：边数，s：源，t：汇
    int n, m, s, t;
    // edges：所有边的集合
    vector<Edge> edges;
    // G：点 x -> x 的所有边在 edges 中的下标
    vector<int> G[ maxn ];
    int d[ maxn ], cur[ maxn ];
    bool vis[ maxn ];

    Dinic( int _n, int _m, int _s, int _t )
        : n( _n )
        , m( _m )
        , s( _s )
        , t( _t ) {
        init( n );
    }

    void init( int n ) {
        for ( int i = 0; i < n; i++ )
            G[ i ].clear();
        edges.clear();
    }

    void AddEdge( int from, int to, int cap ) {
        edges.push_back( Edge( from, to, cap, 0 ) );
        edges.push_back( Edge( to, from, 0, 0 ) );
        m = edges.size();
        G[ from ].push_back( m - 2 );
        G[ to ].push_back( m - 1 );
    }

    bool BFS() {
        memset( vis, false, sizeof( vis ) );
        queue<int> Q;
        Q.push( s );
        d[ s ] = 0;
        vis[ s ] = true;
        while ( !Q.empty() ) {
            int x = Q.front();
            Q.pop();
            for ( int i = 0; i < G[ x ].size(); i++ ) {
                Edge &e = edges[ G[ x ][ i ] ];
                if ( !vis[ e.to ] && e.cap > e.flow ) {
                    vis[ e.to ] = true;
                    d[ e.to ] = d[ x ] + 1;
                    Q.push( e.to );
                }
            }
        }
        return vis[ t ];
    }

    int DFS( int x, int a ) {
        if ( x == t || a == 0 ) return a;
        int flow = 0, f;
        for ( int &i = cur[ x ]; i < G[ x ].size(); i++ ) {
            Edge &e = edges[ G[ x ][ i ] ];
            if ( d[ x ] + 1 == d[ e.to ] &&
                 ( f = DFS( e.to, min( a, e.cap - e.flow ) ) ) > 0 ) {
                e.flow += f;
                edges[ G[ x ][ i ] ^ 1 ].flow -= f;
                flow += f;
                a -= f;
                if ( a == 0 ) break;
            }
        }
        return flow;
    }

    // s：源，t：汇
    int Maxflow( int s, int t ) {
        this->s = s;
        this->t = t;
        int flow = 0;
        while ( BFS() ) {
            memset( cur, 0, sizeof( cur ) );
            flow += DFS( s, INF );
        }
        return flow;
    }

    int Maxflow() { return Maxflow( s, t ); }
};
} // namespace dicnic

int main() {
    using namespace dicnic;

    int N, M, S, T;
    cin >> N >> M >> S >> T;

    Dinic dc( N, M, S, T );
    for ( int i = 0; i < M; ++i ) {
        int u, v, w;
        cin >> u >> v >> w;
        dc.AddEdge( u, v, w );
    }
    cout << dc.Maxflow() << endl;
    return 0;
}

/*
input:
6 9 4 2
1 3 10
2 1 20
2 3 20
4 3 10
4 5 30
5 2 20
4 6 20
5 6 10
6 2 30

output:
50
*/
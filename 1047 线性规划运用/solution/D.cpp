/*
D - 餐巾计划问题

reference:
https://blog.51cto.com/u_15180869/2732667
 */
#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const LL maxn = 100005, inf = 0x3f3f3f3f3f3f3f3f;

struct edge {
    LL to, next, cost, capacity;

    edge( LL t, LL n, LL c, LL v )
        : to( t )
        , next( n )
        , cost( c )
        , capacity( v ) {}
    edge() {}
} e[ maxn << 1 ];

LL N, n, p, m, f, s, cnt, ans;
vector<LL> nexts( maxn, -1 ), dist;
vector<bool> visited;

inline void add( LL from, LL to, LL capacity, LL cost ) {
    e[ cnt ] = edge( to, nexts[ from ], cost, capacity );
    nexts[ from ] = cnt++;
    // 反向边
    e[ cnt ] = edge( from, nexts[ to ], -cost, 0 );
    nexts[ to ] = cnt++;
}

inline bool spfa() {
    deque<LL> q;
    dist = vector<LL>( maxn, -1 );
    visited = vector<bool>( maxn, false );
    // 汇点
    dist[ N * 2 + 1 ] = 0;
    q.push_back( N * 2 + 1 );

    while ( !q.empty() ) {
        LL u = q.front();
        q.pop_front();
        for ( LL i = nexts[ u ]; i != -1; i = e[ i ].next ) {
            LL v = e[ i ].to;
            if ( e[ i ^ 1 ].capacity > 0 ) {
                if ( dist[ v ] > dist[ u ] - e[ i ].cost || dist[ v ] == -1 ) {
                    dist[ v ] = dist[ u ] - e[ i ].cost;
                    if ( !visited[ v ] ) {
                        if ( !q.empty() && dist[ q.front() ] > dist[ v ] )
                            q.push_front( v );
                        else
                            q.push_back( v );
                    }
                    visited[ v ] = true;
                }
            }
        }
        visited[ u ] = false;
    }
    return dist[ 0 ] != -1;
}

inline LL getmin_cost( LL u, LL op ) {
    visited[ u ] = true;
    if ( u == N * 2 + 1 ) return op;
    LL used, flow = 0;
    for ( LL i = nexts[ u ]; i != -1; i = e[ i ].next ) {
        if ( op <= 0 ) break;
        LL v = e[ i ].to;
        if ( !visited[ v ] && e[ i ].capacity > 0 &&
             dist[ v ] + e[ i ].cost == dist[ u ] &&
             ( used = getmin_cost( v, min( op, e[ i ].capacity ) ) ) > 0 ) {
            e[ i ].capacity -= used;
            e[ i ^ 1 ].capacity += used;
            op -= used;
            ans += used * e[ i ].cost;
            flow += used;
        }
    }
    return flow;
}

int main() {
    cin >> N;

    for ( int i = 1; i <= N; i++ ) {
        LL cap;
        cin >> cap;
        add( i, N * 2 + 1, cap, 0 ), add( 0, i + N, cap, 0 );
    }

    cin >> p >> m >> f >> n >> s;
    for ( int i = 1; i <= N; i++ ) {
        add( 0, i, inf, p );
        if ( N >= i + m ) add( i + N, i + m, inf, f );
        if ( N >= i + n ) add( i + N, i + n, inf, s );
        if ( N >= i + 1 ) add( i, i + 1, inf, 0 );
    }

    while ( spfa() ) {
        visited = vector<bool>( maxn, false );
        getmin_cost( 0, inf );
    }
    cout << ans << endl;
    return 0;
}

/*
Sample Input
3
1 7 5
11 2 2 3 1

Sample Output
134
*/

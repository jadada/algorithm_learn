/*
C - RGB Coloring 2
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

vector<vector<bool>> nbrs( maxn, vector<bool>( maxn, false ) );
vector<int> colors( maxn, 0 );
vector<bool> visited( maxn, false );
vector<int> continuous( maxn, 0 );

int N, M;
int solution_cnt, continuous_cnt;

void get_continuous( int id ) {
    visited[ id ] = true;
    continuous[ continuous_cnt++ ] = id;

    for ( int i = 1; i <= N; ++i ) {
        if ( !visited[ i ] && nbrs[ i ][ id ] ) {
            get_continuous( i );
        }
    }
}

bool isvalid( int id, int color ) {
    for ( int i = 1; i <= M; ++i ) {
        if ( nbrs[ id ][ i ] && color == colors[ i ] ) {
            return false;
        }
    }
    return true;
}

void dfs( int id ) {
    if ( id == continuous_cnt ) {
        ++solution_cnt;
        return;
    }

    for ( int i = 1; i <= 3; ++i ) {
        if ( !isvalid( continuous[ id ], i ) ) continue;

        colors[ continuous[ id ] ] = i;
        dfs( id + 1 );
        colors[ continuous[ id ] ] = 0;
    }
}

int main() {
    cin >> N >> M;

    for ( int i = 0; i < M; ++i ) {
        int a, b;
        cin >> a >> b;
        nbrs[ a ][ b ] = nbrs[ b ][ a ] = true;
    }

    long long ans = 1;
    for ( int i = 1; i <= N; ++i ) {
        if ( visited[ i ] ) continue;

        solution_cnt = continuous_cnt = 0;
        get_continuous( i );
        dfs( 0 );
        ans *= solution_cnt;
    }
    cout << ans << endl;
    return 0;
}

/*
Sample Input
3 3
1 2
2 3
3 1

Sample Output
6
 */
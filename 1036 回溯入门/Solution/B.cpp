/*
B - 迷宫
 */
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

const int MAXN = 10;

using Pair = pair<int, int>;

vector<Pair> directions( { Pair( 0, 1 ), Pair( 1, 0 ), Pair( 0, -1 ),
                           Pair( -1, 0 ) } );

vector<vector<bool>> blocked( MAXN, vector<bool>( MAXN, false ) );

int N, M, T;
int ans = 0;

void traverse( int x, int y, const Pair &end ) {
    if ( x == end.first && y == end.second ) {
        ++ans;
        return;
    }

    for ( const auto &d : directions ) {
        int xx = x + d.first;
        int yy = y + d.second;

        if ( !blocked[ xx ][ yy ] ) {
            blocked[ x ][ y ] = true;
            traverse( xx, yy, end );
            blocked[ x ][ y ] = false;
        }
    }
}

int main() {
    // 行数，列数，障碍总数
    scanf( "%d%d%d", &N, &M, &T );
    // 起点，终点
    Pair start, end;
    scanf( "%d%d%d%d", &start.first, &start.second, &end.first, &end.second );
    // 障碍的位置
    for ( int i = 0; i < N + 2; i++ ) {
        for ( int j = 0; j < M + 2; j++ ) {
            if ( i == N + 1 || i == 0 || j == M + 1 || j == 0 ) {
                blocked[ i ][ j ] = true;
            }
        }
    }
    while ( T-- ) {
        int x, y;
        scanf( "%d%d", &x, &y );
        blocked[ x ][ y ] = true;
    }

    traverse( start.first, start.second, end );
    printf( "%d\n", ans );

    return 0;
}

/*
Sample Input
2 2 1
1 1 2 2
1 2

Sample Output
1
 */
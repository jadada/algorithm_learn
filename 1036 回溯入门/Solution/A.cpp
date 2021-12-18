/*
A - 马的遍历
 */
#include <bits/stdc++.h>
using namespace std;

using Pair = pair<int, int>;

const vector<Pair> directions = { Pair( 1, 2 ),  Pair( 2, 1 ),   Pair( 2, -1 ),
                                  Pair( 1, -2 ), Pair( -1, -2 ), Pair( -2, -1 ),
                                  Pair( -2, 1 ), Pair( -1, 2 ) };

const int N = 9;
// 该点是否被访问
vector<vector<bool>> visited( N, vector<bool>( N, false ) );
// 到该点要走几步
vector<vector<int>> steps( N, vector<int>( N, -1 ) );

void traverse( Pair &start, Pair &end ) {

    visited[ start.first ][ start.second ] = true;
    steps[ start.first ][ start.second ] = 0;

    queue<Pair> q;
    q.push( start );

    bool found = false;

    while ( !q.empty() ) {
        Pair next = q.front();
        q.pop();
        for ( const auto d : directions ) {
            int x = next.first + d.first;
            int y = next.second + d.second;

            if ( x <= 0 || x >= N || y <= 0 || y >= N ) continue;

            if ( !visited[ x ][ y ] ) {
                visited[ x ][ y ] = true;
                steps[ x ][ y ] = steps[ next.first ][ next.second ] + 1;

                if ( x == end.first && y == end.second ) {
                    found = true;
                    break;
                }

                Pair pre( x, y );
                q.push( pre );
            }
        }
        if ( found ) break;
    }
}

int main() {
    Pair start, end;
    scanf( "%d%d%d%d", &start.first, &start.second, &end.first, &end.second );

    traverse( start, end );
    printf( "%d\n", steps[ end.first ][ end.second ] );
    return 0;
}

/*
Sample Input
5 2 5 4

Sample Output
2
 */
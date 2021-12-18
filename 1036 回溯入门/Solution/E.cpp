/*
E - 好奇怪的游戏
 */
#include <bits/stdc++.h>
using namespace std;

using Pair = pair<int, int>;
using PairArray = vector<Pair>;
using IntArray = vector<int>;
using IntMatrix = vector<IntArray>;

const int SIZE = 20;

const PairArray directions( { Pair( 1, 2 ), Pair( 2, 1 ), Pair( 2, -1 ),
                              Pair( 1, -2 ), Pair( -1, -2 ), Pair( -2, -1 ),
                              Pair( -2, 1 ), Pair( -1, 2 ), Pair( 2, 2 ),
                              Pair( 2, -2 ), Pair( -2, -2 ), Pair( -2, 2 ) } );
IntMatrix steps;

void dfs( int x, int y, Pair &end, int step ) {
    steps[ x ][ y ] = step;

    for ( const auto &d : directions ) {
        int xx = x + d.first;
        int yy = y + d.second;

        if ( ( xx >= 1 && xx <= SIZE && yy >= 1 && yy <= SIZE ) &&
             ( steps[ xx ][ yy ] == -1 || steps[ xx ][ yy ] > step + 1 ) ) {
            dfs( xx, yy, end, step + 1 );

            if ( xx == end.first && yy == end.second ) break;
        }
    }
}

int main() {
    Pair start;
    Pair end( 1, 1 );

    int rounds = 2;
    while ( rounds-- ) {
        cin >> start.first >> start.second;
        steps = IntMatrix( SIZE + 10, IntArray( SIZE + 10, -1 ) );
        dfs( start.first, start.second, end, 0 );
        cout << steps[ end.first ][ end.second ] << endl;
    }

    return 0;
}

/*
Sample Input
12 16
18 10

Sample Output
8
9
 */
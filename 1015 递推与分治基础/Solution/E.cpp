/*
E - 绝对值最小的和
*/
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

int main() {
    int N;
    cin >> N;

    vector<int> nums( N + 1, 0 );

    for ( int i = 1; i <= N; ++i )
        cin >> nums[ i ];

    vector<vector<int>> min_results( N + 1 );
    min_results[ 0 ] = { 1, 2, abs( nums[ 1 ] + nums[ 2 ] ) };

    for ( int i = 1; i < N; ++i ) {
        min_results[ i ] = { i, i + 1, abs( nums[ i ] + nums[ i + 1 ] ) };

        for ( int j = i + 1; j <= N; ++j ) {
            if ( abs( nums[ i ] + nums[ j ] ) < min_results[ i ][ 2 ] )
                min_results[ i ] = { i, j, abs( nums[ i ] + nums[ j ] ) };
        }

        if ( min_results[ i ][ 2 ] < min_results[ 0 ][ 2 ] )
            min_results[ 0 ] = min_results[ i ];
    }

#ifdef DEBUG
    for ( int i = 1; i < N; ++i )
        cout << min_results[ i ][ 0 ] << " " << min_results[ i ][ 1 ] << " "
             << min_results[ i ][ 2 ] << endl;
    cout << endl;
#endif

    cout << min_results[ 0 ][ 0 ] << " " << min_results[ 0 ][ 1 ] << endl;
    return 0;
}

/*
input:
5
5 4 3 2 1

output:
4 5
*/
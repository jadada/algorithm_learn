/*
A - N皇后问题

reference:
https://leetcode-cn.com/problems/n-queens/solution/nhuang-hou-bu-yong-ha-xi-biao-shi-yong-b-d2vj/
 */
#include <bits/stdc++.h>
using namespace std;

int ans;

void dfs( int n, int row, vector<bool> &cols, vector<bool> &diags,
          vector<bool> &antidiags ) {
    if ( n == row ) {
        ++ans;
    } else {
        for ( int i = 0; i < n; ++i ) {
            if ( cols[ i ] | diags[ i + row ] | antidiags[ n - 1 - row + i ] )
                continue;

            cols[ i ] = diags[ i + row ] = antidiags[ n - 1 - row + i ] = true;
            dfs( n, row + 1, cols, diags, antidiags );
            cols[ i ] = diags[ i + row ] = antidiags[ n - 1 - row + i ] = false;
        }
    }
}

int main() {
    int N;
    while ( scanf( "%d", &N ) != EOF ) {
        ans = 0;

        vector<bool> cols( N, false );
        vector<bool> diags( 2 * N - 1, false );
        vector<bool> antidiags( 2 * N - 1, false );

        dfs( N, 0, cols, diags, antidiags );

        printf( "%d\n", ans );
    }

    return 0;
}

/*
Sample Input
8
6
13

Sample Output
92
4
73712
 */
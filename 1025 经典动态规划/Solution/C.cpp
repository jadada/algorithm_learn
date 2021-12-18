/*
C - 最长公共子序列
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;
using Matrix = vector<Array>;

int LCS( string &str1, string &str2 ) {
    if ( str1.empty() || str2.empty() ) return 0;

    int n1 = str1.size(), n2 = str2.size();
    Matrix C( n1 + 1, Array( n2 + 1 ) );

    for ( int i = 1; i <= n1; ++i ) {
        for ( int j = 1; j <= n2; ++j ) {
            if ( str1[ i - 1 ] == str2[ j - 1 ] )
                C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + 1;
            else if ( C[ i - 1 ][ j ] >= C[ i ][ j - 1 ] )
                C[ i ][ j ] = C[ i - 1 ][ j ];
            else
                C[ i ][ j ] = C[ i ][ j - 1 ];
        }
    }

    return C[ n1 ][ n2 ];
}

int main() {
    string str1, str2;
    while ( cin >> str1 >> str2 ) {
        cout << LCS( str1, str2 ) << endl;
    }
    return 0;
}

/*
Sample Input
abcfbc abfcab
programming contest
abcd mnp

Sample Output
4
2
0
 */
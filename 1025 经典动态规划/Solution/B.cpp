/*
B - 最长递增子序列 I

reference:
https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;

int max_sub_len( Array &nums ) {
    if ( nums.empty() ) return 0;

    int n = nums.size();
    Array dp( n );
    for ( int i = 0; i < n; ++i ) {
        dp[ i ] = 1;
        for ( int j = 0; j < i; ++j ) {
            if ( nums[ j ] < nums[ i ] )
                dp[ i ] = std::max( dp[ i ], dp[ j ] + 1 );
        }
    }
    return *std::max_element( dp.begin(), dp.end() );
}

int main() {
    int T, N;
    scanf( "%d", &T );
    while ( T-- && scanf( "%d", &N ) != EOF ) {
        Array nums( N );
        for ( int i = 0; i < N; ++i )
            scanf( "%d", &nums[ i ] );

        printf( "%d\n", max_sub_len( nums ) );
    }

    return 0;
}

/*
Sample Input
1
9
1 3 2 5 4 7 6 9 8

Sample Output
5
 */
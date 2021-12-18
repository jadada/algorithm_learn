/* 
C - 最少拦截系统

reference:
https://blog.csdn.net/hurmishine/article/details/52926957
 */
#include <bits/stdc++.h>
using namespace std;

using Array = vector<int>;

int main() {
    int n;
    while ( scanf( "%d", &n ) != EOF ) {
        Array items( n );

        int x;
        int cnt = 1;
        bool flag = false;
        scanf( "%d", &items[ 0 ] );

        for ( int i = 1; i < n; ++i ) {
            flag = false;
            scanf( "%d", &x );
            for ( int j = 0; j <= cnt; ++j ) {
                if ( items[ j ] >= x ) {
                    items[ j ] = x;
                    flag = true;
                    break;
                }
            }
            if ( !flag ) items[ ++cnt ] = x;
        }

        printf( "%d\n", cnt );
    }

    return 0;
}

/* 
Sample Input
8 389 207 155 300 299 170 158 65

Sample Output
2
 */
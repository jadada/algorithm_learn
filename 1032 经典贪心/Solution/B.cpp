/* 
B - 找零钱
 */
#include <bits/stdc++.h>
using namespace std;

const vector<int> moneys = { 100, 50, 20, 10, 5, 2, 1 };
const int SIZE = moneys.size();

int main() {
    int n;
    while ( scanf( "%d", &n ) != EOF ) {
        vector<int> nums( SIZE );

        int remain = n;
        int total_num = 0;
        for ( int i = 0; i < SIZE; ++i ) {
            nums[ i ] = remain / moneys[ i ];
            remain %= moneys[ i ];
            total_num += nums[ i ];
        }

        printf( "%d ", total_num );

        bool started = false;
        for ( int i = 0; i < SIZE; ++i ) {
            if ( nums[ i ] > 0 ) {
                if ( !started )
                    started = true;
                else
                    printf( "+" );

                printf( "%d", moneys[ i ] );

                if ( nums[ i ] > 1 ) printf( "*%d", nums[ i ] );
            }
        }
        printf( "=%d\n", n );
    }

    return 0;
}

/* 
Sample Input
6
1
1000

Sample Output
2 5+1=6
1 1=1
10 100*10=1000
 */
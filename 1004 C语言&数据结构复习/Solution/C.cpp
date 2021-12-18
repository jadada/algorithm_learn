/*
C - 200和整数对之间的情缘
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200;

int main() {
    long long N;
    while ( cin >> N ) {
        vector<int> array( MAX, 0 );
        int num;
        for ( int i = 0; i < N; i++ ) {
            cin >> num;
            ++array[ num % MAX ];
        }

        long long ans = 0;
        for ( int i = 0; i < MAX; i++ ) {
            ans += array[ i ] * ( array[ i ] - 1 );
        }
        cout << ( ans >>= 1 ) << endl;
    }
    return 0;
}

/*
input:
6
123 223 123 523 200 2000

output:
4
*/
/* 
B - 台阶问题

reference: 
https://www.geek-share.com/detail/2790040145.html
*/

#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;

const int MAXN = 100000 + 10;
const int num_to_mod = 100003;

int main() {
    int N, k;
    cin >> N >> k;

    vector<ULL> nums( MAXN );

    nums[ 0 ] = 1;

    for ( int i = 1; i <= N; ++i ) {
        for ( int j = 1; j <= k; ++j ) {
            if ( i >= j ) {
                nums[ i ] += nums[ i - j ];
                nums[ i ] %= num_to_mod;
            }
        }
    }
    cout << nums[ N ] << endl;
    return 0;
}

/*
input:
5 2

output:
8
*/
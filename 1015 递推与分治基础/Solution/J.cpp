/*
J - 切木棍
*/
#include <bits/stdc++.h>
using namespace std;

int find_min_of_maxlen( vector<int> &rods, int k ) {
    int l = 1, h = rods[ 0 ];
    int ret = -1;

    int len = h - l + 1;
    while ( len > 0 ) {
        if ( l == h ) {
            ret = l;
            break;
        }

        long long mid = l + ( h - l ) / 2;

        long long k_sum = 0;
        for ( int i = 0; i < rods.size(); ++i ) {
            if ( rods[ i ] % mid )
                k_sum += rods[ i ] / mid;
            else
                k_sum += rods[ i ] / mid - 1;
        }

        if ( k_sum <= k ) {
            h = mid;
        } else {
            l = mid + 1;
        }

        len = h - l + 1;
    }

    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> rods( n );
    for ( int i = 0; i < n; i++ )
        cin >> rods[ i ];

    sort( rods.rbegin(), rods.rend() );

    cout << find_min_of_maxlen( rods, k ) << endl;

    return 0;
}

/*
input:
2 3
7 9

output:
4
*/
/* 
C - 数的计算

reference: 
https://www.shuzhiduo.com/A/n2d9M7QQdD/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[ 1010 ];

    nums[ 0 ] = nums[ 1 ] = 1;
    for ( int i = 2; i <= n; ++i ) {
        nums[ i ] = ( i % 2 ) ? nums[ i - 1 ] : nums[ i - 1 ] + nums[ i / 2 ];
    }

    cout << nums[ n ] << endl;
    return 0;
}

/*
input:
6

output:
6
*/
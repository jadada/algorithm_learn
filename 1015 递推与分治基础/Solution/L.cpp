/*
L - 幂运算

reference:
https://leetcode-cn.com/problems/super-pow/solution/you-qian-ru-shen-kuai-su-mi-suan-fa-xiang-jie-by-l/
*/
#include <bits/stdc++.h>
using namespace std;

long long fastexp( long long a, long long b, long long p ) {
    if ( b == 0 ) return 1;
    a %= p;

    if ( b % 2 == 1 )
        return ( a * fastexp( a, b - 1, p ) ) % p;
    else {
        int res = fastexp( a, b >> 1, p ) % p;
        return ( res * res ) % p;
    }
}

int main() {
    int n;
    cin >> n;

    vector<long long> results( n );
    for ( int i = 0; i < n; ++i ) {
        long long a, b, p;
        cin >> a >> b >> p;
        long long ans = fastexp( a, b, p );
        results[ i ] = ans;
    }

    for ( const auto &result : results )
        cout << result << endl;

    return 0;
}

/*
input:
2
2 10 9
2 3 3

output:
7
2
*/
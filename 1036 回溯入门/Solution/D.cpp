/*
D - 选数

reference:
https://blog.nowcoder.net/n/c4decf47315d45968b47517a6665d909
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;          // n为元素个数，k是参与组合的元素个数
long long ans = 0; // 组合之和为素数的个数

vector<int> arr( 30 );
vector<bool> visited( 30, false );

bool isprime( int num ) {
    for ( int i = 2; i * i <= num; ++i ) {
        if ( num % i == 0 ) return false;
    }

    return true;
}

void dfs( int cnt, int sum, int start_index ) {
    if ( cnt == k ) {
        if ( isprime( sum ) ) ++ans;
        return;
    }

    for ( int i = start_index; i < n; ++i ) {
        if ( !visited[ i ] ) {
            visited[ i ] = true;
            dfs( cnt + 1, sum + arr[ i ], i + 1 );
            visited[ i ] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[ i ];
    }
    dfs( 0, 0, 0 );
    cout << ans << endl;
    return 0;
}

/*
Sample Input
4 3
3 7 12 19

Sample Output
1
 */
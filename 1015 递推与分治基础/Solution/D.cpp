/* 
D - 数的划分

reference:
https://www.nowcoder.com/questionTerminal/3773e51c48ec4727939cc85a8bc4c60d?answerType=1&f=discussion
*/

#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void recurse( int total, int num, int cnt ) {
    if ( cnt == 0 ) {
        if ( total == 0 ) ++ans;
        return;
    }

    for ( int i = num; i <= total; ++i )
        recurse( total - i, i, cnt - 1 );
}

int main() {
    int n, k;
    cin >> n >> k;

    recurse( n, 1, k );
    cout << ans << endl;
    return 0;
}

/*
input:
7 3

output:
4
*/
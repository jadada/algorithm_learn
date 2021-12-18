/*
A - 禽兽的传染病
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, n;
    cin >> x >> n;

    long long result = 1;
    for ( int i = 0; i < n; ++i )
        result *= ( 1 + x );
    cout << result << endl;
    return 0;
}

/*
input:
10 2

output:
121
*/
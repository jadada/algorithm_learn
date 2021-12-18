/*
A - log2(N)
*/
#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;

int main() {
    ULL n;
    cin >> n;
    int k = 0;
    for ( ULL x = 1; x <= n; x <<= 1, k++ )
        ;
    cout << k - 1 << endl;
    return 0;
}

/*
input:
6

output:
2
*/
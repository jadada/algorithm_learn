/*
B - 如何溜的最快
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, R;
    while ( cin >> x >> y >> R )
        cout << int( ceil( sqrt( x * x + y * y ) / R ) ) << endl;
    return 0;
}

/*
input:
3 4 4

output:
2
*/
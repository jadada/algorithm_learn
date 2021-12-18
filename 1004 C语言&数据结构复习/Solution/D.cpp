/*
D - 两面包夹芝士
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, num;
    int maxA = -1, minB = 1000000;

    cin >> N;

    for ( int i = 0; i < N; i++ ) {
        cin >> num;
        maxA = ( num > maxA ) ? num : maxA;
    }

    for ( int i = 0; i < N; i++ ) {
        cin >> num;
        minB = ( num < minB ) ? num : minB;
    }

    cout << ( ( minB >= maxA ) ? ( minB - maxA + 1 ) : 0 ) << endl;

    return 0;
}

/*
input:
3
3 2 5
6 9 8

output:
2
*/
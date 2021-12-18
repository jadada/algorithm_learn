/*
I - 汉诺塔
*/
#include <bits/stdc++.h>
using namespace std;

void move( int k, char A, char C ) {
    cout << "Move disk " << k << " from " << A << " to " << C << endl;
}

void hanoi( int k, char A, char B, char C ) {
    if ( k == 1 ) {
        move( k, A, C );
        return;
    }

    hanoi( k - 1, A, C, B );
    move( k, A, C );
    hanoi( k - 1, B, A, C );
}

int main() {
    int n;
    cin >> n;

    hanoi( n, 'A', 'B', 'C' );
    return 0;
}

/*
input:
3

output:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/
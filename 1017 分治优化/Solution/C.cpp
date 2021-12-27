/*
C - 数组第 k 大
*/
#include <bits/stdc++.h>
using namespace std;

int partition( vector<int> &nums, int low, int high ) {
    int temp = nums[ low ];
    while ( low < high ) {
        while ( low < high && nums[ high ] < temp )
            --high;
        if ( low < high ) {
            nums[ low ] = nums[ high ];
            ++low;
        }

        while ( low < high && nums[ low ] > temp )
            ++low;
        if ( low < high ) {
            nums[ high ] = nums[ low ];
            --high;
        }
    }
    nums[ low ] = temp;
    return low;
}

int find_maxk( vector<int> &nums, int low, int high, int k ) {
    int pivot = partition( nums, low, high );

    if ( pivot == k - 1 )
        return nums[ k - 1 ];
    else if ( pivot > k - 1 )
        return find_maxk( nums, low, pivot - 1, k );
    else
        return find_maxk( nums, pivot + 1, high, k );
}

int main() {
    int n, k;
    while ( scanf( "%d%d", &n, &k ) != EOF ) {
        vector<int> nums( n );
        for ( int i = 0; i < n; ++i )
            scanf( "%d", &nums[ i ] );

        printf( "%d\n", find_maxk( nums, 0, n - 1, k ) );
    }
    return 0;
}

/*
Sample Input
5 2
1 3 5 7 9

Sample Output
7
*/
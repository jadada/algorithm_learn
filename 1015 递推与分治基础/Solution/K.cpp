/* 
K - 逆序对

reference:
https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/shu-zu-zhong-de-ni-xu-dui-by-leetcode-solution/
*/

#include <bits/stdc++.h>
using namespace std;

int mergeSort( vector<int> &nums, vector<int> &tmp, int l, int r ) {
    if ( l >= r ) {
        return 0;
    }

    int mid = ( l + r ) / 2;
    int inv_count =
        mergeSort( nums, tmp, l, mid ) + mergeSort( nums, tmp, mid + 1, r );
    int i = l, j = mid + 1, pos = l;

    while ( i <= mid && j <= r ) {
        if ( nums[ i ] <= nums[ j ] ) {
            tmp[ pos ] = nums[ i ];
            ++i;
            inv_count += ( j - ( mid + 1 ) );
        } else {
            tmp[ pos ] = nums[ j ];
            ++j;
        }
        ++pos;
    }

    for ( int k = i; k <= mid; ++k ) {
        tmp[ pos++ ] = nums[ k ];
        inv_count += ( j - ( mid + 1 ) );
    }
    for ( int k = j; k <= r; ++k )
        tmp[ pos++ ] = nums[ k ];

    copy( tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l );
    return inv_count;
}

int reversePairs( vector<int> &nums ) {
    int n = nums.size();
    vector<int> tmp( n );
    return mergeSort( nums, tmp, 0, n - 1 );
}

int main() {
    int n;
    cin >> n;

    vector<int> nums( n );
    for ( int i = 0; i < n; ++i )
        cin >> nums[ i ];

    cout << reversePairs( nums ) << endl;

    return 0;
}

/*
input:
6
5 4 2 6 3 1

output:
11
*/
/*
H - 比k大的数
*/
#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums( n );
    for ( int i = 0; i < n; ++i )
        cin >> nums[ i ];

    sort( nums.begin(), nums.end() );

    vector<int> targets( m );
    for ( int i = 0; i < m; ++i )
        cin >> targets[ i ];

    for ( const auto &t : targets ) {
        auto upper = upper_bound( nums.begin(), nums.end(), t );
        int index =
            ( upper != nums.end() ) ? distance( nums.begin(), upper ) : -1;
        int larger = ( index != -1 ) ? nums.size() - index : 0;

#ifdef DEBUG
        cout << "index=" << index << ", larger=" << larger << endl;
#else
        cout << larger << endl;
#endif
    }

    return 0;
}

/*
input:
5 5
1 2 3 4 5
3 5 4 6 -1

output:
2
0
1
0
5
*/
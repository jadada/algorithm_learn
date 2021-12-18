/*
A - 多设备区间调度
 */
#include <bits/stdc++.h>
using namespace std;

using Pair = pair<int, int>;
using Item = vector<Pair>;

struct {
    bool operator()( const Pair &a, const Pair &b ) const {
        return a.first < b.first;
    }
} compare_first;

void schedule( const Item &items ) {
    int n = items.size();

    multiset<int> s;
    long long total = 0;
    for ( int i = 0; i < n; ++i ) {
        auto it = s.begin();
        if ( !s.empty() && items[ i ].first >= *it ) {
            it = --s.upper_bound( items[ i ].first );
            total += items[ i ].second - *it;
            s.erase( it );
            s.insert( items[ i ].second );
        } else {
            total += items[ i ].second - items[ i ].first;
            s.insert( items[ i ].second );
        }
    }
    printf( "%lu %lld\n", s.size(), total );
}

int main() {
    int t;
    scanf( "%d", &t );
    while ( t-- ) {
        int n;
        scanf( "%d", &n );

        Item devices( n );
        for ( int i = 0; i < n; i++ )
            scanf( "%d%d", &devices[ i ].first, &devices[ i ].second );

        sort( devices.begin(), devices.end(), compare_first );

        schedule( devices );
    }
    return 0;
}

/*
Sample Input
1
5
1 3
3 6
2 4
5 7
6 9

Sample Output
2 13
 */
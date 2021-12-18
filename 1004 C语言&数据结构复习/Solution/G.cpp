/*
G - 排队援救
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 5;

int main() {
    int n, cnt = 0;
    long long value;
    queue<long long> valueQ;
    queue<int> seqQ;

    cin >> n;

    for ( int i = 1; i <= n; ++i ) {
        cin >> value;

        if ( cnt > 0 && value <= valueQ.back() ) continue;

        if ( cnt < MAX ) {
            valueQ.push( value );
            seqQ.push( i );
            // cout << "push: " << i << "[value=" << value << "] " << endl;
            ++cnt;
        } else if ( cnt == MAX ) {
            // cout << "pop: " << seqQ.front() << "[value=" << value << "] ";
            valueQ.pop();
            seqQ.pop();

            valueQ.push( value );
            seqQ.push( i );
            // cout << ", push: " << i << "[value=" << value << "] " << endl;
        }
    }

    while ( seqQ.size() > 0 ) {
        cout << seqQ.front() << " ";
        seqQ.pop();
    }
    cout << endl;
    return 0;
}

/*
input:
6
1 3 5 7 9 11

output:
2 3 4 5 6
*/
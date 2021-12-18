/*
E - 构造回文串
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    // long long N = 1234210000;
    long long N;
    cin >> N;

    while ( N % 10 == 0 ) {
        N /= 10;
    }

    string numStr = to_string( N );

    bool break_flag = false;
    for ( int cursor1 = 0, cursor2 = numStr.size() - 1;
          cursor1 <= cursor2 && cursor1 != cursor2; ++cursor1, --cursor2 ) {
        // cout << "num[cursor1]" << numStr.at(cursor1) << ", "
        //      << "num[cursor2] = " << numStr.at(cursor2) << endl;
        if ( numStr.at( cursor1 ) != numStr.at( cursor2 ) ) {
            break_flag = true;
            break;
        }
    }

    cout << ( !break_flag ? "Yes" : "No" ) << endl;
    return 0;
}

/*
input:
1210

output:
Yes
*/
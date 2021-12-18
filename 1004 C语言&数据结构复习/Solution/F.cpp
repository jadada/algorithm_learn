/*
F - 模拟计算器
*/
#include <bits/stdc++.h>
using namespace std;

long long calculator( queue<long long> numq, long long N ) {
    stack<long long> nums;
    string op;

    nums.push( numq.front() );
    numq.pop();
    for ( int i = 1; i < N; i++ ) {
        long long num = numq.front();
        numq.pop();

        cin >> op;
        if ( op.at( 0 ) == '+' ) {
            nums.push( num );
        } else if ( op.at( 0 ) == '-' ) {
            nums.push( -num );
        } else if ( op.at( 0 ) == '*' ) {
            long long top = nums.top();
            nums.pop();
            nums.push( num * top );
        }
    }

    long long result = 0, size = nums.size();
    for ( int i = 0; i < size; i++ ) {
        result += nums.top();
        nums.pop();
    }
    return result;
}

int main() {
    long long N, num;
    cin >> N;

    queue<long long> numq;

    for ( int i = 0; i < N; i++ ) {
        cin >> num;
        numq.push( num );
    }

    long long result = calculator( numq, N );
    cout << result << endl;
    return 0;
}

/*
input:
4
1 2 3 4
+ * -

output:
3
*/

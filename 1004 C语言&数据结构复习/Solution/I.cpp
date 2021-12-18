/* 
I - 异或最大值升级版

reference:
https://dwz.date/ffRD
*/

#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

const int HIGH_BIT = 30;
const int MAXNUM = 100000;

struct Digit {
    int pathcnt = 0;
    int next[ 2 ] = { -1, -1 };

    void Init() {
        next[ 0 ] = next[ 1 ] = -1;
        pathcnt = 0;
    }
};

class BinaryDigits {
  private:
    vector<Digit> binums = vector<Digit>( MAXNUM );
    int nextpos = 1;

  public:
    void reset() {
        binums[ 0 ].Init();
        nextpos = 1;
    }

    void insert( int num ) {
        int cursor = 0;
        for ( int k = HIGH_BIT; k >= 0; --k ) {
            int bit = num >> k & 1;
            if ( binums[ cursor ].next[ bit ] == -1 ) {
                binums[ nextpos ].Init();
                binums[ cursor ].next[ bit ] = nextpos++;
            }
            ++( binums[ cursor ].pathcnt );
            cursor = binums[ cursor ].next[ bit ];
        }
        ++( binums[ cursor ].pathcnt );
    }

    void remove( int num ) {
        int cursor = 0;
        for ( int k = HIGH_BIT; k >= 0; --k ) {
            int bit = num >> k & 1;
            --( binums[ cursor ].pathcnt );
            cursor = binums[ cursor ].next[ bit ];
        }
        --( binums[ cursor ].pathcnt );
    }

    int findMaxXor( int num ) {
        int cursor = 0, x = 0;
        for ( int k = HIGH_BIT; k >= 0; --k ) {
            int bit = ( num >> k & 1 ) ^ 1;
            bool isone = true;

            int pos_to_check = binums[ cursor ].next[ bit ];
            if ( pos_to_check == -1 || !binums[ pos_to_check ].pathcnt )
                bit ^= 1, isone = false;

            if ( binums[ cursor ].pathcnt == 0 ||
                 binums[ cursor ].next[ bit ] == -1 )
                return 0;

            cursor = binums[ cursor ].next[ bit ];
            x = isone ? 2 * x + 1 : 2 * x;
        }
        return binums[ cursor ].pathcnt > 0 ? x : 0;
    }

#ifdef DEBUG
    void display_binums() {
        for ( int k = HIGH_BIT * 2; k >= 0; --k ) {
            cout << "[k = " << k << "]: ";
            cout << "cnt=" << binums[ k ].pathcnt << " ";
            cout << "[0]:" << binums[ k ].next[ 0 ] << ", ";
            cout << "[1]:" << binums[ k ].next[ 1 ] << endl;
        }
        cout << endl;
    }
#endif
};

int main() {
    BinaryDigits bidigits;

    int n;
    while ( cin >> n ) {
        bidigits.reset();

        vector<int> nums( n );
        for ( int i = 0; i < n; ++i ) {
            cin >> nums[ i ];
            bidigits.insert( nums[ i ] );
        }

#ifdef DEBUG
        cout << ">> after insert:" << endl;
        bidigits.display_binums();
#endif

        int ans = 0;
        for ( int i = 0; i < n; ++i ) {
            bidigits.remove( nums[ i ] );
            for ( int j = i + 1; j < n; ++j ) {
                bidigits.remove( nums[ j ] );
                ans = std::max( ans,
                                bidigits.findMaxXor( nums[ i ] + nums[ j ] ) );
                bidigits.insert( nums[ j ] );
            }
            bidigits.insert( nums[ i ] );
        }
        cout << ans << endl;
    }
    return 0;
}

/*
input:
3
3 1 2
5
1 7 6 8 9

output:
6
24
*/
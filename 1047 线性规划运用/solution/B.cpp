/* 
B - 选数
 */
#include <bits/stdc++.h>
using namespace std;

namespace simplex {

using Array = vector<double>;
using Matrix = vector<Array>;

const double eps = 1e-8, inf = (double) ( 1ll << 60 );
// 系数矩阵，第一行为c，第一列为b
Matrix A;

class Solver {
  private:
    int m;
    int n;

  public:
    Solver( int _m, int _n )
        : m( _m )
        , n( _n ) {}

    void input_matrix( const Matrix &a, const Array &b, const Array &c ) {
        for ( int i = 1; i <= n; ++i ) {
            A[ 0 ][ i ] = c[ i - 1 ];
        }
        for ( int i = 1; i <= m; ++i ) {
            for ( int j = 1; j <= n; ++j ) {
                A[ i ][ j ] = a[ i - 1 ][ j - 1 ];
            }
            A[ i ][ 0 ] = b[ i - 1 ]; // input b
        }
    }

    void display() const {
        cout << "m=" << m << ", n=" << n << endl;

        for ( int i = 0; i <= m; ++i ) {
            for ( int j = 0; j <= n; ++j ) {
                cout << "\t" << A[ i ][ j ];
            }
            cout << endl;
        }
    }

    void pivot( int l, int e ) {
        double tmp = A[ l ][ e ];
        A[ l ][ e ] = 1.0;
        vector<int> tmp_arr;
        for ( int j = 0; j <= n; ++j ) {
            if ( std::fabs( A[ l ][ j ] ) > 0 ) {
                A[ l ][ j ] /= tmp;
                tmp_arr.push_back( j );
            }
        }
        int cnt = tmp_arr.size();
        for ( int i = 0; i <= m; i++ ) {
            if ( i != l && std::fabs( A[ i ][ e ] ) > eps ) {
                tmp = A[ i ][ e ], A[ i ][ e ] = 0;
                for ( int j = 0; j < cnt; ++j ) {
                    A[ i ][ tmp_arr[ j ] ] -= A[ l ][ tmp_arr[ j ] ] * tmp;
                }
            }
        }
    }

    bool simplex( bool verbose = false ) {
        while ( true ) {
            int l = 0, e = 0;
            double minv = inf;
            for ( int j = 1; j <= n; ++j ) {
                if ( A[ 0 ][ j ] > eps ) {
                    e = j;
                    break;
                }
            }
            if ( !e ) break;
            for ( int i = 1; i <= m; ++i ) {
                if ( A[ i ][ e ] > eps && A[ i ][ 0 ] / A[ i ][ e ] < minv ) {
                    minv = A[ i ][ 0 ] / A[ i ][ e ];
                    l = i;
                }
            }
            if ( !l ) {
                // printf( "Unbounded\n" );
                return false;
            }
            pivot( l, e );

            if ( verbose ) display();
        }
        return true;
    }

    double get_result() const { return -A[ 0 ][ 0 ]; }

    void standardize() {
        for ( int i = 0; i < n; ++i )
            A[ 0 ].push_back( 0 );
        for ( int i = 1; i <= m; ++i ) {
            for ( int j = 1; j <= m; ++j ) {
                if ( i == j ) {
                    A[ i ].push_back( 1 );
                } else {
                    A[ i ].push_back( 0 );
                }
            }
        }
        n += m;
    }
};

} // namespace simplex

int main() {
    using namespace simplex;

    int N, K;
    cin >> N >> K;

    int row = 2 * N + 1;
    int bn = 5 * N + 1, cn = 3 * N;
    A = Matrix( bn + 1, Array( cn + 1 ) );

    for ( int i = 1; i <= cn; ++i )
        cin >> A[ 0 ][ i ];
    for ( int i = 1; i <= row; ++i ) {
        A[ i ][ 0 ] = K;
        for ( int j = i; j < i + N; ++j ) {
            A[ i ][ j ] = 1;
        }
    }
    for ( int i = row + 1; i <= row + cn; ++i ) {
        A[ i ][ 0 ] = 1;
        A[ i ][ i - row ] = 1;
    }

    Solver s( bn, cn );
    // s.display();

    s.simplex();
    // s.display();

    cout << int( s.get_result() + 0.5 ) << endl;

    return 0;
}

/*
Sample Input
5 3
14 21 9 30 11 8 1 20 29 23 17 27 7 8 35

Sample Output
195
*/
/*
E - 节约粮食
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

    int n, m;
    cin >> n >> m;

    A = Matrix( m + 1, Array( n + 1 ) );
    for ( int i = 1; i <= n; ++i ) {
        cin >> A[ 0 ][ i ];
    }
    for ( int i = 1; i <= m; ++i ) {
        for ( int j = 1; j <= n; ++j )
            cin >> A[ i ][ j ];
        cin >> A[ i ][ 0 ];
    }

    Solver s( m, n );
    // s.display();

    s.simplex();
    // s.display();

    auto result = (long long) ( floor( s.get_result() * m + 1 - 0.0001 ) );
    cout << "Nasa can spend " << result << " taka." << endl;
    return 0;
}

/*
Sample Input
3 3
1 0.67 1.67
1 2 1 430
3 0 2 460
1 4 0 420

Sample Output
Nasa can spend 1354 taka.
*/
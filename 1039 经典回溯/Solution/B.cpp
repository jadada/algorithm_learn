/*
B - 吃奶酪

reference:
https://blog.51cto.com/u_3044148/3349412

状态压缩：
一维：代表已经走过的节点有哪些，是一个二进制转为十进制的数字，最终表现为十进制.
    每一位代表一个奶酪，比如一共有3个奶酪，f[(101)二进制]
=f[5]，表示1号和3号奶酪吃完了，2号没有吃 二维：代表当前的出发点
值：f[i][j]表示如果以前计算过在以第j个位置出发，在前面已经完成i这种二进制表示法的节点完成情况下，最短的距离是多少
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;

int InputNum;
double ans = 0x3f3f3f3f;
double min_dist = 0x3f3f3f3f;

vector<double> X( MAXN );
vector<double> Y( MAXN );
vector<bool> visited( MAXN );
double dp[ 1 << MAXN ][ MAXN ];
vector<vector<double>> Distance( MAXN, vector<double>( MAXN ) );

double get_distance( double x1, double y1, double x2, double y2 ) {
    return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}

void dfs( int pos, int step, int state, double len ) {

    // 代价函数
    double mayBestAns = len + min_dist * ( InputNum - step );
    // 用代价函数做一次剪枝
    if ( mayBestAns > ans ) return;

    if ( step == InputNum ) {
        ans = std::min( ans, len );
        return;
    }

    for ( int i = 1; i <= InputNum; ++i ) {
        if ( visited[ i ] ) continue;

        // 下一状态
        int next_state = state + ( 1 << ( i - 1 ) );
        // 用压缩状态剪枝
        // 如果尝试过且更好就不必再去了
        if ( dp[ next_state ][ i ] &&
             dp[ next_state ][ i ] <= len + Distance[ pos ][ i ] )
            continue;

        visited[ i ] = true;

        dp[ next_state ][ i ] = len + Distance[ pos ][ i ];
        dfs( i, step + 1, next_state, dp[ next_state ][ i ] );

        visited[ i ] = false;
    }
}

int main() {
    scanf( "%d", &InputNum );

    for ( int i = 1; i <= InputNum; ++i ) {
        scanf( "%lf%lf", &X[ i ], &Y[ i ] );

        for ( int j = 0; j < i; ++j ) {
            Distance[ i ][ j ] = Distance[ j ][ i ] =
                get_distance( X[ i ], Y[ i ], X[ j ], Y[ j ] );
            min_dist = std::min( min_dist, Distance[ i ][ j ] );
        }
    }

    dfs( 0, 0, 0, 0 );

    printf( "%.2f\n", ans );

    return 0;
}

/*
Sample Input
4
1 1
1 -1
-1 1
-1 -1

Sample Output
7.41
 */
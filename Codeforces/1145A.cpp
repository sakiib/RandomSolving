#include <bits/stdc++.h>
using namespace std;
 
int n , a[ 20 ];
 
int solve( int l , int r ) {
        vector <int> V;
        if( l == r ) return 1;
        while( V.size() < l ) V.push_back( -1 );
        for( int i = l; i <= r; i++ ) V.push_back( a[i] );
        sort( V.begin() , V.end() );
        bool f = true;
        for( int i = l; i <= r; i++ ) {
                if( V[i] != a[i] ) {
                        f = false; break;
                }
        }
        if( f ) return r - l + 1;
        int m = ( l + r ) >> 1;
        return max( solve( l , m ) ,  solve( m + 1 , r ) );
}
int main() {
        ios_base::sync_with_stdio(false); cin.tie(0);
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        cout << solve( 1 , n ) << endl;
        return 0;
}

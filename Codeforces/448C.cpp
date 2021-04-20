#include <bits/stdc++.h>
using namespace std;
 
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;
 
const int k = 30;
int n , a[ N ];
int lg[ N ];
int MN[ N ][ k ];
int MNID[ N ][ k ];
 
void buildST( ) {
        for( int i = 1; i <= n; i++ ) MN[ i ][ 0 ] = a[ i ] , MNID[ i ][ 0 ] = i;
        for( int i = 2; i <= n; i++ ) lg[i] = lg[ i/2 ] + 1;
  
        for( int j = 1; ( 1 << j ) <= n; j++ ) {
                for( int i = 1; i + ( 1 << j ) - 1 <= n; i++ ) {
                        if( MN[ i ][ j-1 ] <= MN[ i + ( 1 << (j-1) ) ][ j-1 ] ) {
                                MN[ i ][ j ] = MN[ i ][ j-1 ];
                                MNID[ i ][ j ] = MNID[ i ][ j-1 ];
                        }
                        else {
                                MN[ i ][ j ] = MN[ i + ( 1 << (j-1) ) ][ j-1 ];
                                MNID[ i ][ j ] = MNID[ i + ( 1 << (j-1) ) ][ j-1 ];
                        }
                }
        }
}

pair <int,int> query( int l , int r ) {
        if( l > r ) swap( l , r );
  
        int k = lg[ r-l+1 ];
        int mn = min( MN[ l ][ k ] , MN[ r - ( 1 << k ) + 1 ][ k ] );
        int mnid;
        if( MN[ l ][ k ] <= MN[ r - ( 1 << k ) + 1 ][ k ] ) mnid = MNID[ l ][ k ];
        else mnid = MNID[ r - ( 1 << k ) + 1 ][ k ];
  
        return make_pair( mn , mnid );
}

LL DC( int l , int r , LL base ) {
        if( l > r ) return 0;
  
        pair <int,int> q = query( l , r );
  
        LL x = ( r - l + 1 ); 
        LL y = DC( l , q.second - 1 , q.first ) + DC( q.second + 1 , r , q.first ) + ( q.first - base );
  
        return min( x , y );
}

int main( ) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
  
        buildST( );
  
        cout << DC( 1 , n , 0 ) << endl;
        return 0;
}

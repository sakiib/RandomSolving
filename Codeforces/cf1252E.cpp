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
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;
 
int n , l , r , k;
int a[ N ];
int lo[ N ] , hi[ N ];
int ans[ N ];
 
int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n >> l >> r >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = n; i >= 1; i-- ) {
                if( i == n ) lo[i] = l , hi[i] = r;
                else {
                        if( a[i] < a[i + 1] ) {
                                lo[i] = max( lo[i + 1] - k , l );
                                hi[i] = hi[i + 1] - 1;
                                if( lo[i] > r || hi[i] < l ) return cout << -1 << endl,0;
                        }
                        else if( a[i] > a[i + 1]) {
                                lo[i] = lo[i + 1] + 1;
                                hi[i] = min( hi[i + 1] + k , r );
                                if( lo[i] > r || hi[i] < l ) return cout << -1 << endl,0;
                        }
                        else lo[i] = lo[i + 1] , hi[i] = hi[i + 1];
                }
        }
        for( int i = 1; i <= n; i++ ) {
                if( i == 1 ) ans[i] = lo[i];
                else {
                        if( a[i - 1] < a[i] ) {
                                int l1 = ans[i - 1] + 1 , r1 = ans[i - 1] + k;
                                int l2 = lo[i] , r2 = hi[i];
                                if( l1 > l2 ) swap( l1 , l2 ) , swap( r1 , r2 );
                                ans[i] = l2;
                        }
                        else if( a[i - 1] > a[i] ) {
                                int r1 = ans[i - 1] - 1 , l1 = ans[i - 1] - k;
                                int l2 = lo[i] , r2 = hi[i];
                                if( l1 > l2 ) swap( l1 , l2 ) , swap( r1 , r2 );
                                ans[i] = l2;
                        }
                        else ans[i] = ans[i - 1];
                }
        }
        for( int i = 1; i <= n; i++ ) cout << ans[i] << " ";
        return 0;
}

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
const long long INF = 1e15;
const int N = 1e5 + 5;
 
int n;
LL a[ N ];
pair <LL,LL> p[ N ];
LL dp[ N ][ 10 ];
 
LL solve( int idx , int mul ) {
        if( idx > n ) return mul == 1 ? 0 : INF;
        if( dp[idx][mul+5] != -1 ) return dp[idx][mul+5];
        LL ret = INF;
        ret = min( ret , solve( idx + 1 , mul * ( -1 ) ) + p[idx].first );
        ret = min( ret , solve( idx + 1 , mul * 1 ) + p[idx].second );
        return dp[idx][mul+5] = ret;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) {
                p[i].first = abs( a[i] - ( -1 ) );
                p[i].second = abs( a[i] - 1 );
        }
        memset( dp , -1 , sizeof( dp ) );
        cout << min( p[1].first + solve( 2 , -1 ) , p[1].second + solve( 2 , 1 ) ) << endl;
        return 0;
}

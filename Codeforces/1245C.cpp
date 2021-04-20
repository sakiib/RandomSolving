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
 
string s;
LL dp[ N ];
 
LL solve( int idx ) {
        if( idx >= s.size() ) return 1;
        if( dp[idx] != -1 ) return dp[idx];
  
        LL ret = 0;
        if( idx + 1 < (int)s.size() ) {
                if( s[idx] == 'u' && s[idx + 1] == 'u' ) {
                        ret += solve( idx + 1 ), ret %= MOD;
                        ret += solve( idx + 2 ), ret %= MOD;
                } else if( s[idx] == 'n' && s[idx + 1] == 'n' ) {
                        ret += solve( idx + 1 ), ret %= MOD;
                        ret += solve( idx + 2 ), ret %= MOD;
                } else {
                        ret += solve( idx + 1 ), ret %= MOD;
                }
        } else {
                ret += solve( idx + 1 ) , ret %= MOD;
        }
  
        return dp[idx] = ret;
}

int main( ) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> s;
        for( int i = 0; i < s.size(); i++ ) {
                if( s[i] == 'w' || s[i] == 'm' ) {
                        return cout << 0 << endl,0;
                }
        }
  
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 0 ) << endl;
        return 0;
}

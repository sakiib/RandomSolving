
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
 
int dig[ 20 ];
LL dp[ 20 ][ 2 ][ 2 ][ 20 ];
 
LL go( int idx , bool lead , bool tight , int d ) {
        if( idx == -1 ) return d;
        if( !tight && !lead && dp[idx][lead][tight][d] != -1 ) return dp[idx][lead][tight][d];
        
        LL ret = 0;
        int up = tight ? dig[idx] : 9;
        for( int i = 0; i <= up; i++ ) {
                ret += go( idx - 1 , lead&&(i==0) , tight&&(dig[idx]==i) , lead && i == 0 ? 0 : d + 1 );
        }
        
        if( !tight ) dp[idx][lead][tight][d] = ret;
        return ret;
}

LL calc( LL x ) {
        int len = 0;
        while( x ) dig[len++] = x%10 , x/= 10;
        return go( len - 1 , 1 , 1 , 0 );
}

int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        LL k;
        cin >> k;
        
        memset( dp , -1 , sizeof( dp ) );
        LL lo = 1 , hi = 1e12 , ret = 0;
        while( lo <= hi ) {
                LL mid = ( lo + hi ) >> 1;
                if( calc( mid ) < k ) ret = mid , lo = mid + 1;
                else hi = mid - 1;
        }
        
        LL cur = calc( ret );
        
        LL num = ret + 1;
        vector <int> V;
        while( num ) V.push_back( num%10 ) , num /= 10;
        reverse( all( V ) );
        for( auto x : V ) {
                cur++;
                if( cur == k ) return cout << x << endl,0;
        }
        return 0;
}

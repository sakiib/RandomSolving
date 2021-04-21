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
const int N = 2e3 + 5;
 
int n , degree[ N ];
bool used[ N ];
vector <int> prime;
vector <bool> isprime( N , true );
 
void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
        int sq = sqrt( N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= N; j += 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
        for( int i = 3; i <= N; i += 2 ) {
                if( isprime[i] ) prime.push_back( i );
        }
}
void print( vector <pii> &ans ) {
        cout << ans.size() << endl;
        for( auto x : ans ) cout << x.first << " " << x.second << endl;
        exit(0);
}
bool ok( ) {
        for( int i = 1; i <= n; i++ ) {
                if( !isprime[degree[i]] ) return false;
        }
        return true;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        sieve( );
        cin >> n;
        vector <pii> edge;
        for( int i = 1; i < n; i++ ) {
                edge.push_back( { i , i + 1 } );
                degree[i]++ , degree[i+1]++;
        }
        edge.push_back( { 1 , n } );
        degree[1]++ , degree[n]++;
        if( isprime[ edge.size() ] && ok( ) ) print( edge );
        for( int i = 1; i < n; i ++ ) {
                if( used[i] ) continue;
                used[i+2] = true;
                edge.push_back( { i , i + 2 } );
                degree[i]++ , degree[i+2]++;
                if( isprime[ edge.size() ] && ok( ) ) print( edge );
        }
        return 0;
}

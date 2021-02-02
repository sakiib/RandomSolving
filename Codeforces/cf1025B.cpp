#include <bits/stdc++.h>
using namespace std;
 
typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 2e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
 
int n , a[ N ] , b[ N ];
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
void PrimeFact( set <int> &p , int n ) {
        int sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( n%prime[i] == 0 ) {
                        p.insert( prime[i] );
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                n /= prime[i];
                        }
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) p.insert( n );
}
vector < pair<int,int> > PrimeFactor( int n ) {
        vector < pair<int,int> > ret;
        int sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                int cnt = 0;
                if( n%prime[i] == 0 ) {
                        while( n%prime[i] == 0 ) {
                                cnt++;
                                n /= prime[i];
                        }
                        if( cnt > 0 ) ret.push_back( {prime[i],cnt} );
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) ret.push_back( {n,1} );
        return ret;
}
int main() {
        scanf("%d",&n);
        int cnt = 0;
        for( int i = 1; i <= n; i++ ) scanf("%d %d",&a[i],&b[i]);
        sieve();
        set <int> p;
        PrimeFact( p , a[1] );
        PrimeFact( p , b[1] );
        for( auto x : p ) {
                bool f = true;
                for( int i = 2; i <= n; i++ ) {
                        if( a[i]%x != 0 && b[i]%x != 0 ) {
                                f = false;
                                break;
                        }
                }
                if( f ) return printf("%d\n",x),0;
        }
        printf("-1");
        return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
#define SZ(v) (int)v.size()
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 1e9;
const LL INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
 
struct linear_recurrence_berlekamp_massey {
        typedef long long LL;
        static const int SZ = 2e5 + 5;
        static const int MOD = 998244353 ; /// mod must be a prime
        LL m , a[SZ] , h[SZ] , t_[SZ] , s[SZ] , t[SZ];
 
        inline LL bigmod( LL b , LL p , LL MOD ) {
            LL res = 1%MOD , x = b%MOD;
            while( p ) {
                if ( p&1 ) res = (res * x)%MOD; x = (x * x)%MOD; p >>= 1;
            }
            return (res%MOD);
        }
        inline vector <LL> BM( vector <LL> &x ) {
            LL lf , ld;
            vector <LL> ls , cur;
            for( int i = 0; i < int(x.size()); ++i ) {
                LL t = 0;
                for( int j = 0; j < int(cur.size()); ++j ) t=(t + x[i-j-1] * cur[j])%MOD;
                if( (t - x[i])%MOD == 0 ) continue;
                if( !cur.size() ) {
                    cur.resize( i + 1 );
                    lf = i; ld = (t - x[i])%MOD;
                    continue;
                }
                LL k = -(x[i] - t) * bigmod( ld , MOD - 2 , MOD )%MOD;
                vector <LL> c(i - lf - 1);
                c.push_back( k );
                for( int j = 0; j < int(ls.size()); ++j ) c.push_back(-ls[j] * k%MOD);
                if( c.size() < cur.size() ) c.resize( cur.size() );
                for( int j = 0; j < int(cur.size()); ++j ) c[j] = (c[j] + cur[j])%MOD;
                if(i - lf + (int)ls.size() >= (int)cur.size() ) ls = cur, lf = i, ld = (t-x[i])%MOD;
                cur = c;
            }
            for( int i = 0; i < int(cur.size()); ++i ) cur[i] = (cur[i]%MOD + MOD)%MOD;
            return cur;
        }
        inline void mull( LL *p , LL *q ) {
            for( int i = 0;i < m + m; ++i ) t_[i] = 0;
            for( int i = 0; i < m; ++i ) if( p[i] )
                    for( int j = 0; j < m; ++j ) t_[i+j] = (t_[i+j] + p[i] * q[j])%MOD;
            for( int i = m + m - 1; i >= m; --i ) if( t_[i] )
                    for( int j = m - 1; ~j; --j ) t_[i-j-1] = (t_[i-j-1] + t_[i] * h[j])%MOD;
            for( int i = 0; i < m; ++i ) p[i] = t_[i];
        }
        inline LL calc( LL K ){
            for( int i = m; ~i; --i ) s[i] = t[i] = 0;
            s[0] = 1; if( m != 1 ) t[1] = 1; else t[0] = h[0];
            while( K ) {
                if( K&1 ) mull( s , t );
                mull( t , t ); K >>= 1;
            }
            LL su = 0;
            for( int i = 0; i < m; ++i ) su = (su + s[i] * a[i])%MOD;
            return (su%MOD + MOD)%MOD;
        }
        /// already calculated upto k , now calculate upto n.
        inline vector <LL> process( vector <LL> &x , int n , int k ) {
            auto re = BM( x );
            x.resize( n+1 );
            for( int i = k + 1; i <= n; i++ ){
                for( int j = 0; j < re.size(); j++ ){
                    x[i] += 1LL * x[i - j - 1]%MOD * re[j] % MOD; x[i] %= MOD;
                }
            }
            return x;
        }
        inline LL work( vector <LL> &x , LL n ) {
            if( n < int(x.size()) ) return x[n]%MOD;
            vector <LL> v = BM( x ); m = v.size(); if( !m ) return 0;
            for( int i = 0; i < m; ++i ) h[i] = v[i], a[i] = x[i];
            return calc( n )%MOD;
        }
} rec;
 
void brute() {
    int n;
    cin >> n;
 
    string s = "";
    int lim = 9999999;
 
    vector <int> len (n + 1, 0);
 
    for (int l = 0; l <= lim; l++) {
        vector <int> v;
        int cur = l;
 
        while (cur) v.push_back(cur%10), cur /= 10;
        while (v.size() < n) v.push_back(0);
 
        reverse(ALL(v));
 
        for (int i = 0; i < v.size(); i += 0) {
            int j = i;
            while (j < v.size() && v[j] == v[i]) j++;
            len[j - i]++;
            i = j;
        }
    }
 
    for (int i = 1; i <= n; i++) cout << i << " " << len[i] << endl;
}
 
void solve() {
    int n;
    cin >> n;
    vector <LL> v = {10, 180, 2610, 34200, 423000, 5040000};
    v = rec.process(v, n - 1, 5);
    reverse(ALL(v));
    for (auto x: v) cout << x << " "; cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    //brute();
    int t = 1;
 
    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}

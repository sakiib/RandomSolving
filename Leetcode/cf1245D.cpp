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
 
struct edge {
        int u , v;
        LL w;
        edge(){}
        edge( int u , int v , LL w ) : u(u), v(v), w(w){}
        bool operator <( const edge &q ) const {
                return w < q.w;
        }
};
 
int p[ N ];
vector <edge> V;
int n;
 
int ID[ N ] , X[ N ] , Y[ N ];
LL c[ N ] , k[ N ];
 
void makeset( ) {
        for( int i = 1; i <= 1e5; i++ ) p[i] = i;
}
int root( int x ) {
        return p[x] == x ? x : p[x] = root( p[x] );
}
void unite( int x , int y ) {
        int u = root( x ) , v = root( y );
        if( u != v ) p[u] = v;
}
 
vector <int> self;
vector <pii> other;
 
LL kruskal( ) {
        makeset( );
        sort( V.begin() , V.end() );
        LL cost = 0;
        for( auto x : V ) {
                int u = x.u , v = x.v , w = x.w;
                if( root( u ) != root( v ) ) {
                        if( v > n ) self.push_back( u );
                        else other.push_back( { u , v } );
                        cost += w , unite( u , v );
                }
        }
        return cost;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> X[i] >> Y[i];
        for( int i = 1; i <= n; i++ ) cin >> c[i];
        for( int i = 1; i <= n; i++ ) cin >> k[i];
        for( int i = 1; i <= n; i++ ) {
                V.push_back( edge( i , n + 1 , c[i] ) );
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = i + 1; j <= n; j++ ) {
                        LL cost = abs( X[i] - X[j] ) + abs( Y[i] - Y[j] );
                        V.push_back( edge( i , j , 1LL * cost * ( k[i] + k[j] ) ) );
                }
        }
        cout << kruskal() << endl;
        cout << self.size() << endl;
        for( auto x : self ) cout << x << " "; cout << endl;
        cout << other.size() << endl;
        for( auto x : other ) cout << x.first << " " << x.second << endl;
        return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
struct data {
        int typ , idx;
        char c;
        data(){}
        data( int typ , int idx , char c ) :
              typ( typ ) , idx( idx ) , c( c ) {}
};
 
int p[ N ];
int sz[ N ];
string s;
int q;
 
int root( int x ) {
        return p[x] == x ? x : p[x] = root( p[x] );
}
void unite( int x , int y ) {
        int u = root(x) , v = root(y);
        if( u != v ) p[u] = v , sz[v] += sz[u];
}
bool same( int x , int y ) {
        return root(x) == root(y);
}
bool valid( int x , int y ) {
        return x >= 0 && y >= 0 && x < s.size() && y < s.size() &&
                                        s[x] == s[y] && s[x] != '#';
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        //freopen( "input.txt" , "r" , stdin );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> s >> q;
                vector <data> query;
                while( q-- ) {
                        int typ , pos;
                        cin >> typ >> pos;
                        if( typ == 2 ) {
                                query.push_back( {2,pos,s[pos]} );
                                s[pos] = '#';
                        }
                        else query.push_back( {1,pos,'*'} );
                }
                for( int i = 0; i < s.size(); i++ ) p[i] = i , sz[i] = 1;
                for( int i = 0; i < s.size(); i++ ) {
                        if( valid( i , i + 1 ) ) unite( i , i + 1 );
                        if( valid( i , i - 1 ) ) unite( i , i - 1 );
                }
                cout << "Case " << tc << ":" << "\n";
                vector <int> ans;
                for( int i = query.size() - 1; i >= 0; i-- ) {
                        if( query[i].typ == 1 ) {
                                ans.push_back( sz[ root(query[i].idx) ] );
                        }
                        else {
                                s[ query[i].idx ] = query[i].c;
                                int l = query[i].idx;
                                if( valid( l , l + 1 ) ) unite( l , l + 1 );
                                if( valid( l , l - 1 ) ) unite( l , l - 1 );
                        }
                }
                for( int i = ans.size() - 1; i >= 0; i-- ) cout << ans[i] << "\n";
        }
        return 0;
}

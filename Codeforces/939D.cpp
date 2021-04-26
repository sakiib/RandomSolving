#include <bits/stdc++.h>
using namespace std;
 
typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
 
int len , parent[ N ] , ans;
string a , b;
vector < pair<char,char> > res;
 
int Find( int x ) {
        return ( parent[x] == x ? x : parent[x] = Find( parent[x] ) );
}
void makeset( ) {
        for( int i = 1; i <= 26; i++ ) parent[i] = i;
}
void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if( u != v ) parent[u] = v;
}
int main() {
        ios_base :: sync_with_stdio(false); cin.tie(0);
        cin >> len >> a >> b;
        makeset( );
        for( int i = 0; i < a.size(); i++ ) {
                if( Find( a[i]-'a'+1 ) != Find( b[i]-'a'+1 ) ) {
                        Union( a[i]-'a'+1 , b[i]-'a'+1 );
                        res.push_back( {a[i],b[i]} );
                }
        }
        cout << (int)res.size() << endl;
        for( auto x : res ) cout << x.first << " " << x.second << endl;
        return 0;
}

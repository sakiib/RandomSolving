#include <bits/stdc++.h>
using namespace std;
 
typedef long long int LL;
typedef unsigned long long uLL;
typedef pair <int,int> ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos(-1.0);
 
LL b[ 10*N ] , c[ 10*N ];
vector <LL> a;
int blen , clen;
 
void go( int id ) {
        int bb = id;
        int aa = 0;
        LL tot = 0;
        while( bb > 0 ) {
                tot += ( a[ aa++ ] * b[ bb-- ] );
        }
        a.push_back( (c[id]-tot)/b[0] );
}

int main() {
        ios_base :: sync_with_stdio(false); cin.tie(0);
        int t;
        cin >> t;
        while( t-- ) {
                cin >> blen;
                for( int i = 0; i < blen; i++ ) cin >> b[i];
                cin >> clen;
                for( int i = 0; i < clen; i++ ) cin >> c[i];
                for( int i = blen; i < clen; i++ ) b[i] = 0;
                a.clear();
                for( int i = 0; i < clen; i++ ) {
                        if( i == 0 ) a.push_back( c[0]/b[0] );
                        else go( i );
                }
                vector <LL> V;
                for( int i = 0; i < a.size(); i++ ) {
                        if( a[i] == 0 ) continue;
                        V.push_back( a[i] );
                }
                cout << V.size() << endl;
                for( int i = 0; i < V.size(); i++ ) {
                        if( i == 0 ) cout << V[i];
                        else cout << " " << V[i];
                }
                cout << endl;
        }
        return 0;
}

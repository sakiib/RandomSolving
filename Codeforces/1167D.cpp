#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define all(V) V.begin(),V.end()
#define see(x) cerr << #x << " = " << x << "\n";
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 2e5 + 5;
 
int ans[ N ];
 
int main( ) {
        IO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        int len;
        cin >> len;
        string s;
        cin >> s;
        int c = 1;
        set <int> S;
        for( int i = 0; i < len; i++ ) {
                if( s[i] == ')' ) S.insert( i );
        }
        for( int i = 0; i < len; i++ ) {
                if( s[i] == '(' ) {
                        auto it = S.lower_bound( i );
                        if( it == S.end() ) --it;
                        ans[i] = ans[(*it)] = c;
                        S.erase( it );
                        c ^= 1;
                }
        }
        for( int i = 0; i < len; i++ ) cout << ans[i];
        return 0;
}

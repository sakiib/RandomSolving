#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
 
const int N = 2e5 + 5;
 
int n , k;
int a[ N ];
int ans[ N ];
int id[ 4*N ] , mx[ 4*N ];
int nxt[ N ] , bck[ N ];
 
inline void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                mx[node] = a[b];
                id[node] = b;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        if( mx[l] > mx[r] ) mx[node] = mx[l] , id[node] = id[l];
        else mx[node] = mx[r] , id[node] = id[r];
}

inline void update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                mx[node] = val;
                id[node] = b;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        if( mx[l] > mx[r] ) mx[node] = mx[l] , id[node] = id[l];
        else mx[node] = mx[r] , id[node] = id[r];
}

int main() {
        ios_base::sync_with_stdio(false); cin.tie(0);
        
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) nxt[i] = i + 1 , bck[i] = i - 1;
        build( 1 , 1 , n );
        int T = 0;
        while( mx[1] > 0 ) {
                int pos = id[1] , r = nxt[pos] , l = bck[pos];;
                int cnt = 1;
                ans[pos] = T;
                update( 1 , 1 , n , pos , -1 );
                while( cnt <= k && r <= n ) {
                         update( 1 , 1 , n , r , -1 ) , ans[r] = T , cnt++ , r = nxt[r];
                }
                cnt = 1;
                while( cnt <= k && l >= 1 ) {
                        update( 1 , 1 , n , l , -1 ) , ans[l] = T , cnt++ , l = bck[l];
                }
                nxt[l] = r , bck[r] = l;
                T++ , T %= 2;
        }
        for( int i = 1; i <= n; i++ ) cout << (ans[i]+1);
        return 0;
}

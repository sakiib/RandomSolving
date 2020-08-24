class Solution {
public:
    static const int N = 105;
    static const int MOD = 1e9 + 7;

    bool ok( int x ){
        if( x < 2 ) return false;
        if( x == 2 ) return true;
        for( int i = 2; i * i <= x; i++ ) {
            if( x%i == 0 ) return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int p = 0;
        long long f[ 105 ];
        memset( f , 0 , sizeof( f ) );
        for( int i = 2; i <= n; i++ ) {
            if( ok( i ) ) p++;
        }
        int q = n - p;
        f[0] = 1;
        for( int i = 1; i <= n; i++ ) {
            f[i] = ( f[i-1]%MOD * i%MOD )%MOD;
        }
        int ans = ( f[p]%MOD * f[q]%MOD )%MOD;
        return ans;
    }
};

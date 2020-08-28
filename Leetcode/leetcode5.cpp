class Solution {
public:
    static const int N = 1005;
    typedef long long LL;
    int MOD[2] = { 1000000007, 1000000009 };
    int base[2] = { 43 , 37 }, invbase[2] = { 395348840 , 297297300 };
    int tlen, p[ N ][ 2 ], fh[ N ][ 2 ], bh[ N ][ 2 ], invmod[ N ][ 2 ];

    inline int mul( int x, int y, int M ) { return ( 1LL * x * y ) % M; }
    inline int add( int x, int y, int M ) { x += y; return x >= M ? x - M : x; }
    inline int sub( int x, int y, int M ) { x -= y; return x < 0 ? x + M : x; }
    inline void gen_pow( ) {
                p[0][0] = p[0][1] = invmod[0][0] = invmod[0][1] = 1;
                for( int i = 1; i < N; i++ ) {
                        for( int id = 0; id < 2; id++ ) {
                                p[i][id] = mul( p[i-1][id] , base[id] , MOD[id] );
                                invmod[i][id] = mul( invmod[i-1][id] , invbase[id] , MOD[id] );
                        }
                }
    }
    inline void build_hash( string txt ) {
                tlen = txt.size();
                for( int i = 0 , j = tlen - 1; i < tlen; i++ , j-- ) {
                        for( int id = 0; id < 2; id++ ) {
                                fh[i][id] = mul( p[i][id] , txt[i] , MOD[id] );
                                if( i ) fh[i][id] = add( fh[i][id] , fh[i-1][id] , MOD[id] );
                                bh[i][id] = mul( p[j][id] , txt[i] , MOD[id] );
                                if( i ) bh[i][id] = add( bh[i][id] , bh[i-1][id] , MOD[id] );
                        }
                }
    }
    inline LL get_fhash( int l , int r ) {
                if( l == 0 ) return (1LL*fh[r][0] << 31)|(1LL*fh[r][1]);
                int x = sub( fh[r][0], fh[l-1][0], MOD[0] );
                x = mul( x, invmod[l][0], MOD[0] );
                int y = sub( fh[r][1], fh[l-1][1], MOD[1] );
                y = mul( y, invmod[l][1], MOD[1] ); return ( 1LL*x << 31LL )|(1LL*y);
    }
    inline LL get_bhash( int l , int r ) {
                if( l == 0 ) {
                        int x = bh[r][0]; x = mul( x, invmod[tlen-r-1][0], MOD[0] );
                        int y = bh[r][1]; y = mul( y, invmod[tlen-r-1][1], MOD[1] );
                        return (1LL*x << 31LL)|(1LL*y);
                }
                int x = sub( bh[r][0], bh[l-1][0], MOD[0] ); x = mul( x, invmod[tlen-r-1][0], MOD[0] );
                int y = sub( bh[r][1], bh[l-1][1], MOD[1] ); y = mul( y, invmod[tlen-r-1][1], MOD[1] );
                return (1LL*x << 31LL)|(1LL*y);
    }
    string longestPalindrome(string s) {
        gen_pow();
        build_hash( s );
        string ret = "";
        int mx = 0;
        for( int i = 0; i < s.size(); i++ ) {
            for( int j = i; j < s.size(); j++ ) {
                if( get_fhash( i , j ) == get_bhash( i , j ) ) {
                    if( j - i + 1 > mx ) {
                        mx = j - i + 1;
                        ret = s.substr( i , mx );
                    }
                }
            }
        }
        return ret;
    }
};

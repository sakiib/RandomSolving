class Solution {
public:
    int dp[ 505 ][ 505 ];
    int a[ 505 ];

    int solve( int l , int r ) {
        if( l > r ) return 0;
        if( dp[l][r] != -1 ) return dp[l][r];
        int ret = false;
        if( solve( l + 1 , r ) + a[l] ) ret = true;
        if( solve( l , r - 1 ) + a[r] ) ret = true;
        return dp[l][r] = ret;
    }
    bool stoneGame(vector<int>& piles) {
        for( int i = 0; i < piles.size(); i++ ) a[i+1] = piles[i];
        memset( dp , -1 , sizeof( dp ) );
        if( solve( 1 , piles.size() ) ) return true;
        else return false;
    }
};

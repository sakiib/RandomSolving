class Solution {
public:
    int n , a[ 100005 ] , dp[ 100005 ];

    int solve( int idx ) {
        if( idx > n ) return 0;
        if( dp[idx] != -1 ) return dp[idx];
        int ret = 1000000000;
        ret = min( ret , solve( idx + 1 ) + a[idx] );
        ret = min( ret , solve( idx + 2 ) + a[idx] );
        return dp[idx] = ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        for( int i = 0; i < cost.size(); i++ ) {
            a[i + 1] = cost[i];
        }
        memset( dp, -1, sizeof(dp) );
        return min( solve( 1 ) , solve( 2 ) );
    }
};

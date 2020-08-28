class Solution {
public:
    int dp[ 100005 ];
    vector <int> V;
    int solve( int idx ) {
        if( idx >= V.size() ) return 0;
        if( dp[idx] != -1 ) return dp[idx];
        int ret = 0;
        ret = solve( idx + 1 );
        ret = max( ret , solve( idx + 2 ) + V[idx] );
        return dp[idx] = ret;
    }
    int rob(vector<int>& nums) {
        V = nums;
        memset( dp , -1 , sizeof( dp ) );
        return solve( 0 );
    }
};

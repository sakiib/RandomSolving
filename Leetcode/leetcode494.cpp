class Solution {
public:
    typedef long long LL;
    LL dp[ 25 ][ 2005 ];
    vector <int> V;
    int sum;

    LL solve( int idx , int s ) {
        if( idx >= V.size() ) return sum == s;
        if( dp[idx][s+1000] != -1 ) return dp[idx][s+1000];
        LL ret = 0;
        ret += solve( idx + 1 , s + V[idx] );
        ret += solve( idx + 1 , s - V[idx] );
        return dp[idx][s+1000] = ret;
    }
    LL findTargetSumWays(vector<int>& nums, int S) {
        memset( dp , -1 , sizeof( dp ) );
        for( int i = 0; i < nums.size(); i++ ) V.push_back( nums[i] );
        sum = S;
        return solve( 1 , +V[0] ) + solve( 1 , -V[0] );
    }
};

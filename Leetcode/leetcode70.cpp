class Solution {
    const int N = 1e5 + 5;
public:
    int top;
    int dp[ 100005 ];
    int solve( int idx ) {
        if( idx > top ) return 0;
        if( idx == top ) return 1;
        if( dp[idx] != -1 ) return dp[idx];
        int ret = 0;
        ret += solve( idx + 1 );
        ret += solve( idx + 2 );
        return dp[idx] = ret;
    }
    int climbStairs(int n) {
        memset( dp , -1 , sizeof( dp ) );
        top = n;
        return solve( 0 );
    }
};

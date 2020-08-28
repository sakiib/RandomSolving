class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[ 100005 ];
        for( int i = 1; i <= 100000; i++ ) dp[i] = 1e8;
        dp[0] = 0;
        for( int i = 1; i <= amount; i++ ) {
            for( int j = 0; j < coins.size(); j++ ) {
                if( coins[j] <= i ) dp[i] = min( dp[i] , dp[i - coins[j]] + 1 );
            }
        }
        return dp[amount] == 1e8 ? -1 : dp[amount];
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;
    
    int dp[31][901];
    
    int solve(int idx, int currentSum, int d, int f, int target) {
        if (idx > d) {
            return currentSum == target;
        }
        
        if (dp[idx][currentSum] != -1) return dp[idx][currentSum];
        
        int ways = 0;
        for (int i = 1; i <= f; i++) {
            ways += solve(idx + 1, currentSum + i, d, f, target); ways %= mod;
        }
        
        return dp[idx][currentSum] = ways;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, d, f, target);
    }
};

class Solution {
public:
    int dp[60][5];
    
    int solve(int rem, int taken) {
        if (rem == 0) return taken == 2? 1 : 0;
        int ret = 0;
        if (dp[rem][taken] != -1) return dp[rem][taken];
        for (int i = 1; i <= rem; i++) {
            ret = max(ret, solve(rem - i, min(2, taken + 1)) * i);
        }
        return dp[rem][taken] = ret;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);
    }
};

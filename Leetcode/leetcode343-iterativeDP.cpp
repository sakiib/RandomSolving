class Solution {
public:
    int integerBreak(int n) {
        vector <int> dp(60, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    static const int N = 1e3 + 5;
    int dp[N][N];
    
    int solve(int idx, int k, vector <int>& prices) {
        if (k == 0) return 0;
        if (idx >= prices.size()) return 0;
        
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int mx = 0;
        mx = max(mx, solve(idx + 1, k, prices));
        for (int id = idx + 1; id < prices.size(); id++) {
            if (prices[id] <= prices[idx]) continue;
            mx = max(mx, solve(id + 1, k - 1, prices) + (prices[id] - prices[idx]));
        }
        
        return dp[idx][k] = mx;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, prices);
    }
};

class Solution {
public:
    static const int N = 1e3 + 5;
    vector <int> graph[N];
    int dp[N][N];
    
    int solve(int idx, int k, vector <int>& prices) {
        if (k == 0) return 0;
        if (idx >= prices.size()) return 0;
        
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int mx = 0;
        mx = max(mx, solve(idx + 1, k, prices));
        for (auto id: graph[idx]) {
            mx = max(mx, solve(id + 1, k - 1, prices) + (prices[id] - prices[idx]));
        }
        
        return dp[idx][k] = mx;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] > prices[i]) {
                    graph[i].push_back(j);
                }
            }
        }
        
        memset(dp, -1, sizeof(dp));
        return solve(0, k, prices);
    }
};

class Solution {
public:
    int dp[605][105][105];
    
    int solve(int idx, int mm, int nn, int m, int n, vector<string>& strs) {
        assert(mm <= m && nn <= n);
        
        if (idx >= strs.size()) return 0;
        if (dp[idx][mm][nn] != -1) return dp[idx][mm][nn];
        
        int ans = 0;
        ans = max(ans, solve(idx + 1, mm, nn, m, n, strs));
        
        int ones = 0, zeros = 0;
        for (int i = 0; i < strs[idx].size(); i++) {
            if (strs[idx][i] == '1') ones++;
            else zeros++;
        }
        
        if (mm + zeros <=  m && nn + ones <= n) {
            ans = max(ans, 1 + solve(idx + 1, mm + zeros, nn + ones, m, n, strs));
        }
        
        return dp[idx][mm][nn] = ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, m, n, strs);
    }
};

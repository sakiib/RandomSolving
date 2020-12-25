class Solution {
public:
    const int inf = 1e9;
    
    int dp[505][505];
    
    int solve(int l, int r, string &s) {
        if (l >= r)  return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int ans = inf;
        if (s[l] == s[r]) {
            ans = min(ans, solve(l + 1, r - 1, s));
        }
        ans = min(ans, solve(l + 1, r, s) + 1);
        ans = min(ans, solve(l, r - 1, s) + 1);
        return dp[l][r] = ans;
    }
    
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, (int)s.size() - 1, s);
    }
};

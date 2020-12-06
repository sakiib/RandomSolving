class Solution {
public:
    int ls, lt;
    int dp[1005][1005];
    string ss, tt;
    
    int solve(int i, int j) {
        if (j == lt) return 1;
        if (i >= ls) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int tot = 0;
        tot += solve(i + 1, j);
        if (ss[i] == tt[j]) tot += solve(i + 1, j + 1);
        return dp[i][j] = tot;
    }
    int numDistinct(string s, string t) {
        ss = s, tt = t;
        ls = s.size(), lt = t.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};

class Solution {
public:
    const int inf = 1e9;
    
    string str;
    int len;
    int dp[2005];
    int pal[2005][2005];
    
    int palindrome(int l, int r) {
        if (l >= r) return 1;
        if (pal[l][r] != -1) return pal[l][r];
        int ret = 0;
        if (str[l] == str[r]) ret |= palindrome(l + 1, r - 1);
        return pal[l][r] = ret;
    }
    
    int solve(int idx) {
        if (idx >= len) return 0;
        if (dp[idx] != -1) return dp[idx];
        int ret = inf;
        for (int i = idx; i < len; i++) {
            if (palindrome(idx, i)) ret = min(ret, solve(i + 1) + 1);
        }
        return dp[idx] = ret;
    }
    
    int minCut(string s) {
        str = s;
        len = s.size();
        memset(dp, -1, sizeof(dp));
        memset(pal, -1, sizeof(pal));
        return solve(0) - 1;
    }
};

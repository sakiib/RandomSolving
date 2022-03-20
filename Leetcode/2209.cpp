class Solution {
public:
    const int INF = 1e5;
    int dp[1001][1001];
    
    int solve(int idx, string &s, int rem, int len) {
        if (idx >= s.size()) {
            return 0;
        }
        if (dp[idx][rem] != -1) {
            return dp[idx][rem];
        }
        
        int mn = INF;
        if (s[idx] == '0') {
            mn = min(mn, solve(idx + 1, s, rem, len));
        } else {
            mn = min(mn, solve(idx + 1, s, rem, len) + 1);
            if (rem > 0) {
                mn = min(mn, solve(idx + len, s, rem - 1, len));
            }
        }
        
        return dp[idx][rem] = mn;
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp, -1, sizeof(dp));
        return solve(0, floor, numCarpets, carpetLen);
    }
};

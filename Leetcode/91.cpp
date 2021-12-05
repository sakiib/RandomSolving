class Solution {
public:
    static const int N = 105;
    
    int dp[N];
    
    map <string, bool> init() {
        map <string, bool> valid;
        for (int i = 1; i <= 26; i++) {
            valid[to_string(i)] = true;
        }
        return valid;
    }
    
    int solve(int idx, int len, string &s, map <string, bool> &valid) {
        if (idx >= len) {
            return 1;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int ways = 0;
        for (int l = 1; l <= 2; l++) {
            if (idx + l - 1 < len && valid[s.substr(idx, l)]) {
                ways += solve(idx + l, len, s, valid);
            }
        }
        
        return dp[idx] = ways;
    }
    int numDecodings(string s) {
        map <string, bool> valid = init();
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size(), s, valid);
        return 0;
    }
};

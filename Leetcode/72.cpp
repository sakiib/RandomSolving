class Solution {
public:
    static const int N = 505;
    static const int INF = 1e6;
    
    int dp[N][N];
    
    int solve(int i, int j, string &word1, string &word2, int l1, int l2) {
        if (i >= l1 && j >= l2) {
            return 0;
        }
        if (i >= l1) {
            return l2 - j;
        }
        if (j >= l2) {
            return l1 - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = INF;
        
        if (word1[i] == word2[j]) {
            ans = min(ans, solve(i + 1, j + 1, word1, word2, l1, l2));
        } else {
            // insert at word1 or delete at word1
            ans = min(ans, 1 + solve(i, j + 1, word1, word2, l1, l2));
            // insert at word2 or delete at word2
            ans = min(ans, 1 + solve(i + 1, j, word1, word2, l1, l2));
            // replace a character at word1 or word2 & match them
            ans = min(ans, 1 + solve(i + 1, j + 1, word1, word2, l1, l2));
        }
        
        return dp[i][j] = ans;
    }
    
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2, word1.size(), word2.size());
    }
};

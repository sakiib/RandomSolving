class Solution {
public:
    const int inf = 1e9;
    
    int len, cost[105][105], dp[105][105];
    
    int solve(string s, int k, int idx, int partition) {
        if (idx == len) return partition == k? 0 : inf;
        if (dp[idx][partition] != -1) return dp[idx][partition];
        
        int mn = inf;
        for (int i = idx; i < len; i++) {
            mn = min(mn, solve(s, k, i + 1, partition + 1) + cost[idx][i]);
        }
        
        return dp[idx][partition] = mn;
    }
    
    int palindromePartition(string s, int k) {
        len = s.size();
        
        auto costOfConvertingToPalindrome = [&](int l, int r) {
            int sz = (r - l + 1);
            sz /= 2;
            int cnt = 0;
            while (sz --) {
                if (s[l] != s[r]) cnt++;
                l++, r--;
            }
            return cnt;
        };
        
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                cost[i][j] = costOfConvertingToPalindrome(i, j);
            }
        }
        
        memset(dp, -1, sizeof(dp));
        return solve(s, k, 0, 0);
    }
};

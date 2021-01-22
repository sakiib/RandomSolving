class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector <int> dp (4e4 + 1, 0);
        int ans = 1;
        
        for (auto val: arr) {
            dp[val + 2e4] = dp[val - difference + 2e4] + 1;
            ans = max(ans, dp[val + 2e4]);
        }
        
        return ans;
    }
};

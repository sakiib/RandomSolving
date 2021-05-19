class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto num: nums) {
            total += num;
        }
        
        vector <bool> dp (total + 1, 0);
        dp[0] = 1;
        for (auto num: nums) {
            for (int tot = total; tot >= 1; tot--) {
                if (num <= tot) {
                    if (dp[tot - num]) dp[tot] = 1;
                }
            }
        }
        
        return total % 2 == 0 && dp[total / 2];
    }
};

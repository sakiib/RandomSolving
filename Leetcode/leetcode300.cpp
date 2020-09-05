class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if ((int)nums.size() == 0) return 0;
        int n = nums.size();
        vector <int> dp (n, 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int mx = 1;
        for (int i = 0; i < n; i++) mx = max(mx, dp[i]);
        return mx;
    }
};

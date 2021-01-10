class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int,int> dp;
        long long sum = 0;
        int ans = 0;
        dp[0] = 1;
        for (auto val: nums) {
            sum += val;
            ans += dp[sum - k];
            dp[sum]++;
        }
        return ans;
    }
};

// sum[r] - sum[l - 1] = k
// sum[r] - k = sum[l - 1]

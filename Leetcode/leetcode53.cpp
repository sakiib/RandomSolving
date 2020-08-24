class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int mx = nums[0];
      for (auto x: nums) mx = max(mx, x);
      int sum = 0;
      for (auto x: nums) {
        sum += x;
        mx = max(mx, sum);
        if (sum < 0) sum = 0;
      }
      return mx;
    }
};

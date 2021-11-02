class Solution {
  public:
    vector <int> largestDivisibleSubset(vector <int> &nums) {
      int sz = nums.size();
      
      vector <int> dp(sz + 1, 1);
      vector <int> path(sz + 1, -1);

      sort(nums.begin(), nums.end());
      
      int mx = 0, idx = -1;
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
          if (nums[i] % nums[j] == 0) {
            if (1 + dp[j] > dp[i]) {
              dp[i] = dp[j] + 1;
              path[i] = j;
            }
          }
        }
        if (dp[i] > mx) {
          mx = dp[i];
          idx = i;
        }
      }

      vector <int> ans;
      while (idx != -1) {
        ans.push_back(nums[idx]);
        idx = path[idx];
      }

      return ans;
    }
};

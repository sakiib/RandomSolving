class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int sz = prices.size();
      vector <vector <int> > dp(sz + 5, vector <int>(5, 0));
      //dp[i][j] = max profit at i'th item with j item in hands so far.
      for (int i = 0; i < sz; i++) {
        if (i == 0) {
          dp[i][0] = 0;
          dp[i][1] = -prices[i];
        }
        else {
          dp[i][0] = dp[i - 1][0];
          dp[i][1] = dp[i - 1][1];
          dp[i][0] = max(dp[i][0], dp[i - 1][1] + prices[i]);
          dp[i][1] = max(dp[i][1], dp[i - 1][0] - prices[i]);
        }
      }
      if (sz == 0) return 0;
      return dp[sz - 1][0];
    }
};

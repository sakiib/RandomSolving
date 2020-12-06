class Solution {
public:
    int dp[105][2];
    int n, val[105];
    
    int solve(int idx, int firstTaken) {
        if (idx > n) return 0;
        if (dp[idx][firstTaken] != -1) return dp[idx][firstTaken];
        int ret = 0;
        if (idx == n) {
            if (!firstTaken) {
                ret = max(ret, solve(idx + 2, firstTaken) + val[idx]);
            } else {
                ret = max(ret, solve(idx + 1, firstTaken));
            }
        } else {
            ret = max(ret, solve(idx + 2, idx == 1? 1 : firstTaken) + val[idx]);
            ret = max(ret, solve(idx + 1, firstTaken));
        }
        return dp[idx][firstTaken] = ret;
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            val[i + 1] = nums[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(1, 0);
    }
};

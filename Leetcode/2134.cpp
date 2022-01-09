// Link: https://leetcode.com/contest/weekly-contest-275/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 3) {
            return 0;
        }
        
        int len = 2 * sz - 1;
        int ones = 0;
        vector <int>  v (len, 0);
        for (int i = 0; i < len; i++) {
            if (i < sz) {
                ones += nums[i];
                v[i] = nums[i];
            } else {
                v[i] = nums[i - sz];
            }
        }
        
        vector <int> sum (len, 0);
        for (int i = 0; i < len; i++) {
            sum[i] = v[i];
            if (i > 0) {
                sum[i] += sum[i - 1];
            }
        }
        
        auto get_sum = [&](int l, int r) {
            return l? sum[r] - sum[l - 1]: sum[l];
        };
        
        int ans = 2e5;
        for (int i = 0; i + ones - 1 < len; i++) {
            ans = min(ans, ones - get_sum(i, i + ones - 1));
        }
        
        return ans;
    }
};

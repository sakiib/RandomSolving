// Link: https://leetcode.com/contest/weekly-contest-275/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int get_sum(int l, int r, vector <int> &sum) {
        if (l > r) {
            return 0;
        }
        int sz =  sum.size();
        if (r < sz) {
            return l? sum[r] - sum[l - 1]: sum[r];
        } 
        return get_sum(l, sz - 1, sum) + get_sum(0, r - sz, sum);
    }
    
    int minSwaps(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 3) {
            return 0;
        }
        
        int ones = 0;
        vector <int> sum (sz, 0);
        for (int i = 0; i < sz; i++) {
            ones += nums[i];
            sum[i] = nums[i];
            if (i) {
                sum[i] += sum[i - 1];
            }
        }
        
        int ans = 2e5;
        for (int i = 0; i < sz; i++) {
            ans = min(ans, ones - get_sum(i, i + ones - 1, sum));
        }
        
        return ans;
    }
};


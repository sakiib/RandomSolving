class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> ans ((int)nums.size(), 0);
        int l = 0, r = (int)nums.size() - 1, idx = (int)nums.size() - 1;
        while (l <= r) {
            if (nums[l] * nums[l] >= nums[r] * nums[r]) {
                ans[idx] = nums[l] * nums[l];
                idx--;
                l++;
            } else {
                ans[idx] = nums[r] * nums[r];
                idx--;
                r--;
            }
        }
        
        return ans;
    }
};

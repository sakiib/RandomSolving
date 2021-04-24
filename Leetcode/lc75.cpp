class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = 0;
        while (r < (int)nums.size()) {
            if (nums[r] == 0) swap(nums[l], nums[r]), r++, l++;
            else r++;
        }
        r = l;
        while (r < (int)nums.size()) {
            if (nums[r] == 1) swap(nums[l], nums[r]), r++, l++;
            else r++;
        }
    }
};

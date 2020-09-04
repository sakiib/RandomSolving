class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];
        int lo = 1, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > nums[0]) lo = mid + 1;
            else mn = nums[mid], hi = mid - 1;
        }
        return mn;
    }
};

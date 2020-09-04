class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l1 = 0, r1 = 0, l2 = nums.size() - 1, r2 = nums.size() - 1, ans = -1;
        int lo = 1, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > nums[0]) r1 = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        l2 = r1 + 1;
        lo = l1, hi = r1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > target) hi = mid - 1;
            else if (nums[mid] < target) lo = mid + 1;
            else {
                ans = mid;
                break;
            }
        }
        lo = l2, hi = r2;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > target) hi = mid - 1;
            else if (nums[mid] < target) lo = mid + 1;
            else {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};

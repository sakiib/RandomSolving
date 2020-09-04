class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = -1, en = -1;
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > target) hi = mid - 1;
            else if (nums[mid] < target) lo = mid + 1;
            else st = mid, hi = mid - 1;
        }
        lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > target) hi = mid - 1;
            else if (nums[mid] < target) lo = mid + 1;
            else en = mid, lo = mid + 1;
        }
        vector <int> ans = {st, en};
        return ans;
    }
};

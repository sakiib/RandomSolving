class Solution {
public:
    // returns the leftmost index in range [l, r] 
    int lessThanLeftmost(int l, int r, int val, vector <int>& nums) {
        int lo = l, hi = r, ret = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < val) {
                ret = mid;
                hi = mid - 1;
            } else {
                hi = mid - 1;
            }
        }
        return ret;
    }

    // returns the rightmost index in range [l, r]
    int lessThanRightmost(int l, int r, int val, vector <int>& nums) {
        int lo = l, hi = r, ret = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < val) {
                ret = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ret;
    }

    // returns the number of elements in range [l, r] less than val
    int lessThan(int l, int r, int val, vector <int>& nums) {
        int x = lessThanLeftmost(l, r, val, nums);
        int y = lessThanRightmost(l, r, val, nums);
        if (x == -1 || y == -1)  return 0;
        return (y - x + 1);
    }
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ans += lessThan(j + 1, nums.size() - 1, nums[i] + nums[j], nums);
            }
        }
        
        return ans;
    }
};

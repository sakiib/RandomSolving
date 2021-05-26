class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1e6, ans = 1;
        
        auto ok = [&](int d) {
            int sum = 0;
            for (auto num: nums) {
                sum += (num + d - 1) / d;
                if (sum > threshold) return false;
            }
            return true;
        };
        
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (ok(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

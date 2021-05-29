class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = 1e5, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (1LL * mid * mid <= x) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

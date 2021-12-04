// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, bad = 1;
        while (lo <= hi) {
            // (lo + hi) / 2 will overflow
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) {
                bad = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return bad;
    }
};

// Complexity: O(lg^2(m + n))
class Solution {
public:
    const double eps = 1e-8;

    int getSmallerEqual(int k, vector <int> &v) {
        int lo = 0, hi = v.size() - 1, ret = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (v[mid] <= k) ret = mid + 1, lo = mid + 1;
            else hi = mid - 1;
        }
        return ret;
    }
    int findKth(int k, vector <int> &nums1, vector <int> &nums2) {
        int lo = -1e9, hi = 1e9, ret = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = getSmallerEqual(mid, nums1) + getSmallerEqual(mid, nums2);
            if (cnt > k) ret = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return ret;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz = nums1.size() + nums2.size();
        if (sz % 2 == 0) {
            int x = findKth(sz / 2, nums1, nums2), y = findKth(sz / 2 - 1, nums1, nums2);
            return 1.0 * (x + y) / 2.0;
        }
        else {
            int x = findKth(sz / 2, nums1, nums2);
            return x;
        }
    }
};

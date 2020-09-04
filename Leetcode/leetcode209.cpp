class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        vector <int> sum (len, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum[i] = nums[i];
            if (i > 0) sum[i] += sum[i - 1];
        }
        auto getsum = [&](int l, int r) {
            return l == 0? sum[r]: sum[r] - sum[l - 1];
        };

        int ans = 1000000000;
        for (int i = 0; i < len; i++) {
            int lo = i, hi = len - 1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (getsum(i, mid) >= s) ans = min(ans, mid - i + 1), hi = mid - 1;
                else lo = mid + 1;
            }
        }
        if (ans == 1000000000) return 0;
        else return ans;
    }
};

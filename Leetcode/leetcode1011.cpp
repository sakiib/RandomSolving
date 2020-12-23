class Solution {
public:
    const int inf = 1e9;
    
    int shipWithinDays(vector<int>& weights, int D) {
        int mx = 0;
        for (auto &x: weights) {
            mx = max(mx, x);
        }
        
        auto ok = [&](int cap) -> bool {
            int day = 1, idx = 0, cur = 0;
            while (idx < (int)weights.size()) {
                if (cur + weights[idx] <= cap) {
                    cur += weights[idx];
                    idx++;
                } else {
                    cur = 0;
                    day++;
                }
            }
            return day <= D;
        };
        
        int lo = mx, hi = inf, ans = -1;
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

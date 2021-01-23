class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector <int> sum (nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            sum[i] = nums[i];
            if (i) sum[i] += sum[i - 1];
        }
        
        auto getSum = [&](int l, int r) -> double {
            return l == 0? sum[r]: sum[r] - sum[l - 1];
        };
        
        double mx = -1e9;
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            mx = max(mx, getSum(i, i + k - 1) / k);
        }
        
        return mx;
    }
};

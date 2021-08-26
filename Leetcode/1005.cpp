class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue <int, vector <int>, greater <int> > q;
        for (auto val: nums) {
            q.push(val);
        }
        while (k--) {
            int t = q.top();
            q.pop();
            q.push(-t);
        }
        int ans = 0;
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};

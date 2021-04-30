class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue <int> q;
        int mx = 0;
        for (auto val: prices) {
            if (!q.empty()) {
                int t = - q.top();
                mx = max(mx, val - t);
            }
            q.push(-val);
        }
        return mx;
    }
};

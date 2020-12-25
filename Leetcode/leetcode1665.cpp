class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [&](vector <int> &a, vector <int> &b) -> bool {
            return a[0] - a[1] < b[0] - b[1];
        };
        
        sort(tasks.begin(), tasks.end(), cmp);
        
        int ans = 0, cur = 0;
        for (auto x: tasks) {
            if (x[1] > cur) {
                ans += x[1] - cur;
                cur = x[1];
            }
            if (x[0] > cur) {
                ans += x[0] - cur;
                cur = 0;
            } else {
                cur -= x[0];
            }
        }
        
        return ans;
    }
};

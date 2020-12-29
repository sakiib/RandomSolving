class Solution {
public:
    const int inf = 1e9;
    static const int N = 3e4 + 5;
    int dp[N];
    int tree[4 * N];
    
    void update(int node, int b, int e, int pos, int val) {
        if (b > e || pos > e || pos < b) return;
        if (b == e && b == pos) {
            tree[node] = val;
            return;
        }
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        update(l, b, m, pos, val);
        update(r, m + 1, e, pos, val);
        tree[node] = min(tree[l], tree[r]);
    }
    
    int query(int node, int b, int e, int i, int j) {
        if (i > e || j < b || b > e) return inf;
        if (i <= b && j >= e) return tree[node];
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        return min(query(l, b, m, i, j), query(r, m + 1, e, i, j));
    }
    
    int jump(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) dp[i] = inf;
        int len = (int)nums.size();
        dp[len - 1] = 0;
        update(1, 0, len - 1, len - 1, dp[len - 1]);
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            int mn = query(1, 0, len - 1, i + 1, min(len - 1, i + nums[i]));
            // cout << "mn: " << i << " " << mn << endl;
            dp[i] = mn + 1;
            update(1, 0, len - 1, i, dp[i]);
        }
        // for (int i = nums.size() - 1; i >= 0; i--) cout << i << " " << dp[i] << endl;
        return dp[0];
    }
};

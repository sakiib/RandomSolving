class Solution {
public:
    template <typename T>
    class segment_tree {
        public:
          vector <T> tree;
          segment_tree(int sz) {
              tree.resize(4 * sz + 5, 0);
          }

          void update(int node, int b, int e, int p, T v) {
              if (p > e || p < b || b > e) return;
              if (b == e && b == p) {
                  tree[node] = v;
                  return;
              }
              int l = node << 1, r = l | 1, m = (b + e) >> 1;
              update(l, b, m, p, v);
              update(r, m + 1, e, p, v);
              tree[node] = max(tree[l], tree[r]);
          }

          T query(int node, int b, int e, int i, int j) {
              if (i > e || j < b || b > e) return 0;
              if (i <= b && j >= e) return tree[node];
              int l = node << 1, r = l | 1, m = (b + e) >> 1;
              return max(query(l, b, m, i, j), query(r, m + 1, e, i, j));
          }
    };

    int lengthOfLIS(vector<int>& nums) {
        if ((int)nums.size() == 0) return 0;
        map <int,int> have;
        for (auto num: nums) have[num]++;
        int id = 0;
        map <int,int> ID;
        for (auto [key, value]: have) ID[key] = ++id;
        for (auto &num: nums) num = ID[num];

        segment_tree <int> tree(id + 1);
        vector <int> dp ((int)nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            int mx = tree.query(1, 1, id, 1, nums[i] - 1);
            dp[i] = max(dp[i], mx + 1);
            tree.update(1, 1, id, nums[i], dp[i]);
        }

        int mx = 1;
        for (int i = 0; i < nums.size(); i++) mx = max(mx, dp[i]);
        return mx;
    }
};

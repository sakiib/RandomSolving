class Solution {
public:
    static const int N = 1e5 + 5;
    int n, val[N];
    int tree[4 * N];
    
    void build(int node, int b, int e) {
        if (b > e) return;
        if (b == e) {
            tree[node] = b;
            return;
        }
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        build(l, b, m);
        build(r, m + 1, e);
        if (val[tree[l]] < val[tree[r]]) tree[node] = tree[l];
        else tree[node] = tree[r];
    }

    int query(int node, int b, int e, int i, int j) {
        if (i > e || j < b) return -1;
        if (i <= b && j >= e) return tree[node];
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        int p1 = query(l, b, m, i, j), p2 = query(r, m + 1, e, i, j);
        if (p1 == -1) return p2; 
        if (p2 == -1) return p1;
        if (val[p1] < val[p2]) return p1; 
        else return p2;
    }
    
    int solve(int b, int e) {
        if (b > e) return 0;
        if (b == e) return val[b];
        int idx = query(1, 1, n, b, e);
        int ans = max(solve(b, idx - 1), max(solve(idx + 1, e), (e - b + 1) * val[idx]));
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        for (int i = 0; i < heights.size(); i++) {
            val[i + 1] = heights[i];
        }
        
        build(1, 1, n);
        
        return solve(1, n);
    }
};

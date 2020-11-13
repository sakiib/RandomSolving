#include <bits/stdc++.h>
using namespace std;

/**
segment tree template
    segment tree is built on the given array val[]
operations:
    i. range update (add a given value in a given range)
    ii. range query (sum of all the values in a given range)
    iii. lazy propagate the updates
complexity:
    i. build O(N)
    ii. update O(lgN)
    iii. query O(lgN)
*/

const int N = 1e5 + 5;
int val[N];

template <typename T> class segment_tree {
public:
    const T def_value = 0;
    vector <T> tree;
    vector <T> lazy;
    segment_tree(int sz) {
        tree.resize(sz + 5, 0);
        lazy.resize(sz + 5, 0);
    }
    void build(int node, int b, int e) {
        if (b > e) return;
        if (b == e) { tree[node] = val[b]; return; }
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        build(l, b, m);
        build(r, m + 1, e);
        tree[node] = (tree[l] + tree[r]);
    }
    void pushdown(int node, int b, int e) {
        if (lazy[node] == 0) return;
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        tree[l] += (lazy[node] * (m - b + 1));
        tree[r] += (lazy[node] * (e - m));
        lazy[l] += lazy[node]; lazy[r] += lazy[node]; lazy[node] = 0;
    }
    void update(int node, int b, int e, int i, int j, T add) {
        if (i > e || j < b || b > e) return;
        if (i <= b && j >= e) {
            tree[node] += (add * (e - b + 1));
            lazy[node] += add; return;
        }
        pushdown(node, b, e);
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        update(l, b, m, i, j, add);
        update(r, m + 1, e, i, j, add);
        tree[node] = (tree[l] + tree[r]);
    }
    T query(int node, int b, int e, int i, int j) {
        if (i > e || j < b || b > e) return def_value;
        if (i <= b && j >= e) return tree[node];
        pushdown(node, b, e);
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        return query(l, b, m, i, j) + query(r, m + 1, e, i, j);
    }
};

int main() {
    segment_tree < int > tree(100000);
    return 0;
}

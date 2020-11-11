#include <bits/stdc++.h>
using namespace std;

/**
segment tree template
    segment tree is built on the given array val[]
operations:
    i. point update (add a value at an index)
    ii. range query (sum of all the values in a given range)
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
    segment_tree(int sz) {
        tree.resize(sz + 5, 0);
    }
    void build(int node, int b, int e) {
        if (b > e) return;
        if (b == e) { tree[node] = val[b]; return; }
        int l = node << 1, r = l | 1, m = (l + r) >> 1;
        build(l, b, m);
        build(r, m + 1, e);
        tree[node] = (tree[l] + tree[r]);
    }
    void update(int node, int b, int e, int pos, T add) {
        if (b > e || pos > e || pos < b) return;
        if (b == e && b == pos) { tree[node] += add; return; }
        int l = node << 1, r = l | 1, m = (l + r) >> 1;
        update(l, b, m, pos, add);
        update(r, m + 1, e, pos, add);
        tree[node] = (tree[l] + tree[r]);
    }
    T query(int node, int b, int e, int i, int j) {
        if (b > e || i > e || j < b) return def_value;
        if (i <= b && j >= e) return tree[node];
        int l = node << 1, r = l | 1, m = (l + r) >> 1;
        return query(l, b, m, i, j) + query(r, m + 1, e, i, j);
    }
};

int main() {
    segment_tree <int> tree (100000);
    return 0;
}


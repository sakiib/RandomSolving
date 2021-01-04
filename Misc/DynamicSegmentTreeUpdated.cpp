#include <bits/stdc++.h>

using namespace std;

/**
Updated: Dynamic Segment Tree Implementation
Operations: Range Sum Update + Range Sum Query by Lazy Propagation
Update : Add or Subtract a value in L - R
Query : Sum of elements in L - R
Assume initially for each i , a[i] = i
*/

long long calc(long long x) {
    return 1LL * x * (x + 1) / 2;
}

struct Node {
    Node * l, * r;
    long long sum;
    long long lazy;
    Node() {
        l = nullptr, r = nullptr, sum = 0, lazy = 0;
    }
    Node(long long b, long long e) {
        l = nullptr, r = nullptr, sum = calc(e) - calc(b - 1), lazy = 0;
    }
}* root;

typedef Node * pNode;
long long n, q;

void Propagate(pNode & cur, long long b, long long e) {
    if (cur -> lazy == 0) return;
    long long mid = (b + e) >> 1;
    if (!(cur -> l)) cur -> l = new Node(b, mid);
    if (!(cur -> r)) cur -> r = new Node(mid + 1, e);
    cur -> l -> sum -= (cur -> lazy * (mid - b + 1));
    cur -> r -> sum -= (cur -> lazy * (e - mid));
    cur -> l -> lazy += cur -> lazy;
    cur -> r -> lazy += cur -> lazy;
    cur -> lazy = 0;
}
void Update(pNode & cur, long long b, long long e, long long i, long long j, long long val) {
    if (i > e || j < b || b > e) return;
    if (!cur) cur = new Node(b, e);
    if (i <= b && j >= e) {
        cur -> sum -= (1LL * val * (e - b + 1));
        cur -> lazy += val;
        return;
    }
    Propagate(cur, b, e);
    long long mid = (b + e) >> 1;
    Update(cur -> l, b, mid, i, j, val);
    Update(cur -> r, mid + 1, e, i, j, val);
    cur -> sum = 0;
    if (cur -> l) cur -> sum += cur -> l -> sum;
    else cur -> sum += (calc(mid) - calc(b - 1));
    if (cur -> r) cur -> sum += cur -> r -> sum;
    else cur -> sum += (calc(e) - calc(mid));
}
long long Query(pNode & cur, long long b, long long e, long long i, long long j) {
    if (i > e || j < b || b > e) return 0;
    if (!cur) cur = new Node(b, e);
    if (i <= b && j >= e) return cur -> sum;
    Propagate(cur, b, e);
    long long mid = (b + e) >> 1;
    long long x = Query(cur -> l, b, mid, i, j);
    long long y = Query(cur -> r, mid + 1, e, i, j);
    return (x + y);
}
int main() {
    root = nullptr;
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            long long l, r, val;
            cin >> l >> r >> val;
            Update(root, 1, n, l, r, val);
        } else {
            long long l, r;
            cin >> l >> r;
            cout << Query(root, 1, n, l, r) << "\n";
        }
    }
    return 0;
}

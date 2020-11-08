#include <bits/stdc++.h>
using namespace std;

template <typename T> class fenwick_tree {
public:
  int N;
  vector <T> bit;
  fenwick_tree(int sz) {
    N = sz;
    bit.resize(sz + 5, 0);
  }
  T r_query(int l, int r) {
    return p_query(r) - p_query(l - 1);
  }
  void p_update(int i, T v) {
    if (i <= 0) return;
    for (; i <= N; i += (i & -i)) bit[i] += v;
  }
  T p_query(int i) {
    T ret = 0;
    for (; i > 0; i -= (i & -i)) ret += bit[i];
    return ret;
  }
  void r_update(int i, int j, T v) {
    for (; i <= N; i += (i & -i)) bit[i] += v;
    j++, v *= -1;
    for (; j <= N; j += (j & -j)) bit[j] += v;
  }
};

int main() {
    fenwick_tree <int> bit(100000);
    return 0;
}









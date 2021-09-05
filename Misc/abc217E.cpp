#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const LL N = 2e9;

void solve() {
  multiset <pair <LL, LL>> s;
  int q;
  cin >> q;
  LL val;
  for (int i = N; i < N + q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      s.insert(make_pair(i, x));
    } else if (t == 2) {
      cout << s.begin() -> second << "\n";
      s.erase(s.begin());
    } else {
      while (s.size() && s.rbegin() -> first >= N) {
        val = s.rbegin() -> second;
        s.erase(--s.end());
        s.insert(make_pair(val, val));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc = 1;
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif
  while (tc--) {
    solve();
    cout << "\n";
  }
}

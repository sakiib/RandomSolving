#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Case "Case #" << tc << ": "

bool ok(string a, string b) {
  int idx = 0;
  for (int i = 0; i < (int)b.size(); i++) {
    if (b[i] == a[idx]) {
      idx++;
    }
    if (idx >= (int)a.size()) {
      return true;
    }
  }

  return false;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    string a, b;
    cin >> a >> b;
    cout << Case;

    if (ok(a, b)) {
      cout << (int)b.size() - (int)a.size() << endl;
    } else {
      cout  << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}

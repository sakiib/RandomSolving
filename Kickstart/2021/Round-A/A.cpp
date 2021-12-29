#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int len, k;
    cin >> len >> k;
    string s;
    cin >> s;
    int cur = 0;
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - i - 1]) {
        cur++;
      }
    }
    cout << "Case #" << tc << ": " << abs(cur - k) << "\n";
  }
  return 0;
}

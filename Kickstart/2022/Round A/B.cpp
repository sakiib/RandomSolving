#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Case "Case #" << tc << ": "

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < (int)s.size( ); i++) {
      sum += (s[i] - '0') % 9;
    }

    int need = (9 - sum % 9) % 9;
    int idx = -1;

    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] - '0' > need) {
        idx = i;
        break;
      }
    }

    string ans = "";
    if (idx == -1) {
      ans = s + (char)(need + '0');
    } else {
      ans = s.substr(0, idx) + (char)(need + '0') + s.substr(idx);
    }

    if (ans[0] == '0') {
      swap(ans[0], ans[1]);
    }

    cout << Case << ans << endl;
  }
  return 0;
}


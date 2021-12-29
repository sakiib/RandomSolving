#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int len;
    string s;
    cin >> len >> s;

    vector <int> dp (len, 1);
    for (int i = 0; i < len; i++) {
      if (i - 1 >= 0 && s[i] > s[i - 1]) {
        dp[i] = dp[i - 1] + 1;
      }
    }

    cout << "Case #" << tc << ": ";
    for (int i = 0; i < len; i++) {
      if (i == 0) {
        cout << dp[i];
      } else {
        cout << " " << dp[i];
      }
    }
    cout << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a882

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long ans = 0;
    vector <int> left_bin(n, - 3 * N);

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        left_bin[i] = i;
      } else {
        if (i > 0) {
          left_bin[i] = left_bin[i - 1];
        }
      }
    }

    int right_bin = 3 * N;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1') {
        right_bin = i;
      }
      ans += min(i - left_bin[i], right_bin - i);
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000887c32

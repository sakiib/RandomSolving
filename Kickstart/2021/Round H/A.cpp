#include <bits/stdc++.h>
using namespace std;

int cost[26][26];

void process() {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j) {
        cost[i][j] = 0;
        continue;
      }
      int x = i, y = j;
      if (x > y) {
        swap(x, y);
      }
      cost[i][j] = min(y - x, x + 1 + 25 - y);
    }
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  process();
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    string txt;
    cin >> txt;
    string fav;
    cin >> fav;

    int ans = 0;
    for (auto from: txt) {
      int mn = 100;
      for (auto to: fav) {
        mn = min(mn, cost[from - 'a'][to - 'a']);
      }
      ans += mn;
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008da461

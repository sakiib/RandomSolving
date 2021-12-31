#include <bits/stdc++.h>
using namespace std;

bool need(char x, char y) {
  if (x == y) {
    return true;
  }
  if (x == 'O' && (y == 'R' || y == 'Y')) {
    return true;
  }
  if (x == 'P' && (y == 'R' || y == 'B')) {
    return true;
  }
  if (x == 'G' && (y == 'B' || y == 'Y')) {
    return true;
  }
  if (x == 'A' && (y == 'R' || y == 'Y' || y == 'B')) {
    return true;
  }
  return false;
}

int solve(char c, int len, string &s) {
  int ans = 0;
  for (int i = 0; i < len; i+=0) {
    if (s[i] == 'U' || !need(s[i], c)) {
      i++;
      continue;
    }

    ans++;
    int j = i + 1;
    while (j < len && need(s[j], c)) {
      j++;
    }
    i = j;
  }

  return ans;
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int len;
    string s;
    cin >> len;
    cin >> s;

    string primary = "RYB";
    int ans = 0;
    for (int i = 0; i < primary.size(); i++) {
      ans += solve(primary[i], len, s);
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d9a88

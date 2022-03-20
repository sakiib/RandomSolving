#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Case "Case #" << tc << ": "

const int N = 5e4 + 5;

int len;
string s;
int dp[N][3][3][3][3][3][3];

bool palindrome(int l, int b1, int b2, int b3, int b4, int b5, int b6) {
  if (l == 5) {
    return b1 == b5 && b2 == b4;
  }
  if (l == 6) {
    return b1 == b6 && b2 == b5 && b3 == b4;
  }
  assert(false);
}

int solve(int idx, int b1, int b2, int b3, int b4, int b5, int b6) {
  if (idx >= 5) {
    if (palindrome(5, b1, b2, b3, b4, b5, b6)) {
      return 0;
    }
  }

  if (idx >= 6) {
    if (palindrome(6, b1, b2, b3, b4, b5, b6)) {
      return 0;
    }
  }

  if (idx >= len) {
    return 1;
  }

  if (dp[idx][b1][b2][b3][b4][b5][b6] != -1) {
    return dp[idx][b1][b2][b3][b4][b5][b6];
  }

  int ok = 0;
  if (s[idx] != '?') {
    ok |= solve(idx + 1,  s[idx] - '0', b1, b2, b3, b4, b5);
  } else {
    for (int i = 0; i <= 1; i++) {
      ok |= solve(idx + 1, i, b1, b2, b3, b4, b5);
    }
  }

  return dp[idx][b1][b2][b3][b4][b5][b6] = ok;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> len >> s;

    memset(dp, -1, sizeof(dp));
    if (solve(0, 0, 0, 0, 0, 0, 0)) {
      cout << Case << "POSSIBLE" << endl;
    } else {
      cout << Case << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}



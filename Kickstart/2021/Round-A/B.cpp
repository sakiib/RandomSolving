#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int a[N][N];
int dp[N][N][4]; // 0 - top, 1 - left, 2 - bottom, 3 - right

void process(int r, int c) {
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (!a[i][j]) {
        continue;
      }
      dp[i][j][0] = ((i - 1) >= 1)? dp[i - 1][j][0] + 1: 1;
      dp[i][j][1] = ((j - 1) >= 1)? dp[i][j - 1][1] + 1: 1;
    }
  }

  for (int i = r; i >= 1; i--) {
    for (int j = c; j >= 1; j--) {
      if (!a[i][j]) {
        continue;
      }
      dp[i][j][2] = ((i + 1) <= r)? dp[i + 1][j][2] + 1: 1;
      dp[i][j][3] = ((j + 1) <= c)? dp[i][j + 1][3] + 1: 1;
    }
  }
}

int solve(int r, int c) {
  int ans = 0;

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (!a[i][j]) {
        continue;
      }

      // contribution: ans(x, y) = min(x / 2, y) + min(y / 2, x) − 2

      // top - left
      if (dp[i][j][0] >= 2 && dp[i][j][1] >= 2) {
        ans += min(dp[i][j][0] / 2, dp[i][j][1]) + min(dp[i][j][1] / 2, dp[i][j][0]) - 2;
      }

      // bottom - left
      if (dp[i][j][1] >= 2 && dp[i][j][2] >= 2) {
        ans += min(dp[i][j][1] / 2, dp[i][j][2]) + min(dp[i][j][2] / 2, dp[i][j][1]) - 2;
      }

      // top - right
      if (dp[i][j][0] >= 2 && dp[i][j][3] >= 2) {
        ans += min(dp[i][j][0] / 2, dp[i][j][3]) + min(dp[i][j][3] / 2, dp[i][j][0]) - 2;
      }

      // bottom - right
      if (dp[i][j][3] >= 2 && dp[i][j][2] >= 2) {
        ans += min(dp[i][j][3] / 2, dp[i][j][2]) + min(dp[i][j][2] / 2, dp[i][j][3]) - 2;
      }
    }
  }

  return ans;
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        cin >> a[i][j];
      }
    }

    process(r, c);

    int ans = solve(r, c);
    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}

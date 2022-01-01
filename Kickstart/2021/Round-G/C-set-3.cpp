#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int a[N], sum[N];

int getSum(int l, int r) {
  return sum[r] - sum[l - 1];
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, tot;
    cin >> n >> tot;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }

    int ans = 1e5;

    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        int cur = getSum(i, j);
        if (cur > tot) {
          break;
        }
        if (cur == tot) {
          ans = min(ans, j - i + 1);
        }
      }
    }

    vector <int> dp (1000010, 1e5);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= 1; j--) {
        int cur = getSum(j, i);
        if (cur > tot) {
          break;
        }
        dp[cur] = min(dp[cur], i - j + 1);
      }

      for (int j = i + 1; j <= n; j++) {
        int cur = getSum(i + 1, j);
        if (cur >= tot) {
          break;
        }
        ans = min(ans, j - i + dp[tot - cur]);
      }
    }

    if (ans == (int)1e5) {
      ans = -1;
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}
// Link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b44ef

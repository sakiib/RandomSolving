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
        if (getSum(i, j) == tot) {
          ans = min(ans, j - i + 1);
        }
        for (int k = j + 1; k <= n; k++) {
          int lo = k, hi = n, idx = -1;
          while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (getSum(i, j) + getSum(k, mid) == tot) {
              idx = mid;
              hi = mid - 1;
            } else if (getSum(i, j) + getSum(k, mid) > tot) {
              hi = mid - 1;
            } else {
              lo = mid + 1;
            }
          }
          if (idx != -1) {
            ans = min(ans, j - i + 1 + idx - k + 1);
          }
        }
      }
    }

    if (ans == (int)1e5) {
      ans = -1;
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}
// O(N^3 lgN)

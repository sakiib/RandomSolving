#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* na, Arg1&& arg1, Args&&... args) {
  const char* c = strchr(na + 1, ',');
  cerr.write(na, c - na) << " : " << arg1 << " , ";
  __f(c + 1, args...);
}
#define endl "\n"
#define all(v) v.begin(), v.end()
#define UNIQUE(v) sort(all(v)),v.erase(unique(all(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;

int n, k, p;
int a[55][35];
int sum[55][35];
int dp[55][1505];

int solve(int idx, int rem) {
  if (idx > n) return rem == 0 ? 0 : -inf;
  if (rem < 0) return -inf;
  if (rem == 0) return 0;
  if (dp[idx][rem] != -1) return dp[idx][rem];
  int ret = 0;
  for (int j = 0; j <= k; j++) {
    if (j <= rem) {
      ret = max(ret, solve(idx + 1, rem - j) + sum[idx][j]);
    }
  }
  return dp[idx][rem] = ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        cin >> a[i][j];
      }
    }
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        sum[i][j] += sum[i][j - 1] + a[i][j];
      }
    }
    memset(dp, -1, sizeof(dp));
    cout << "Case #" << tc << ": " << solve(1, p) << endl;
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb

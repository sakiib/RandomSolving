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
typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e2 + 5;
 
int n, a[ N ];
int gap[ N ];
bool have[ N ];
int dp[ N ][ N ][ 2 ];
 
int solve(int idx, int e, int p) {
  if (idx > n) return 0;
  if (dp[idx][e][p] != -1) return dp[idx][e][p];
  int ret = inf;
  if (idx == 1) {
    if (a[idx] == 0) {
      int o = gap[n] - gap[idx - 1] - e;
      if (e) ret = min(ret, solve(idx + 1, e - 1, 0));
      if (o) ret = min(ret, solve(idx + 1, e, 1));
    }
    else {
      ret = min(ret, solve(idx + 1, e, a[idx]%2));
    }
  }
  else {
    if (a[idx] == 0) {
      int o = gap[n] - gap[idx - 1] - e;
      if (e) ret = min(ret, solve(idx + 1, e - 1, 0) + (p%2 != 0));
      if (o) ret = min(ret, solve(idx + 1, e, 1) + (p%2 == 0));
    }
    else {
      ret = min(ret, solve(idx + 1, e, a[idx]%2) + (a[idx]%2 != p%2));
    }
  }
  return dp[idx][e][p] = ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    have[a[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    gap[i] += gap[i - 1] + (a[i] == 0);
  }
  int even = 0, odd = 0;
  for (int i = 1; i <= n; i++) {
    if (!have[i]) {
      if (i%2 == 0) even++;
      else odd++;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(1, even, 0) << endl;
  return 0;
}

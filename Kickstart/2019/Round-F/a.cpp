#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
  void __f(const char * name, Arg1 && arg1) {
    cerr << name << " : " << arg1 << "\n";
  }
template < typename Arg1, typename...Args >
  void __f(const char * na, Arg1 && arg1, Args && ...args) {
    const char * c = strchr(na + 1, ',');
    cerr.write(na, c - na) << " : " << arg1 << " , ";
    __f(c + 1, args...);
  }
#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
typedef long long int LL;
typedef pair < int, int > pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e2 + 5;

int n, k, a[N], flag;
int dp[105][1005][105];
int vis[105][1005][105];
vector <int> V;

int solve(int idx, int prev, int change) {
  if (idx > n) return change <= k ? 0 : inf;
  if (vis[idx][prev][change] == flag) return dp[idx][prev][change];
  vis[idx][prev][change] = flag;
  int ret = inf;
  for (auto x: V) {
    ret = min(ret, solve(idx + 1, x, change + (x != prev)) + (x != a[idx]));
  }
  return dp[idx][prev][change] = ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  flag = 0;
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n >> k;
    V.clear();
    for (int i = 1; i <= n; i++) cin >> a[i], V.push_back(a[i]);
    int mn = inf;
    ++flag;
    for (auto x: V) {
      mn = min(mn, solve(2, x, 0) + (x != a[1]));
    }
    cout << "Case #" << tc << ": " << mn << endl;
  }
  return 0;
}

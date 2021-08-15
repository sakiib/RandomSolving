#include <bits/stdc++.h>
using namespace std;
 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
  void __f(const char * name, Arg1 && arg1) {
    cerr << name << " : " << arg1 << "\n";
  }
template <typename Arg1, typename...Args>
  void __f(const char * na, Arg1 && arg1, Args && ...args) {
    const char * c = strchr(na + 1, ',');
    cerr.write(na, c - na) << " : " << arg1 << " , ";
    __f(c + 1, args...);
  }
#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
typedef long long int LL;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e2 + 5;
 
int len;
string str;
int dp[N][2];
 
inline int id(char ch) {
  return ch == 'R'? 0: 1;
}
 
int solve(int idx, int prev) {
  if (idx >= len) {
    return 0;
  }
 
  if (dp[idx][prev] != -1) {
    return dp[idx][prev];
  }
 
  int ans = inf;
  if (str[idx] == '?') {
    ans = min(ans, solve(idx + 1, 1) + (idx > 0? (1 == prev): 0));
    ans = min(ans, solve(idx + 1, 0) + (idx > 0? (0 == prev): 0));
  } else {
    ans = min(ans, solve(idx + 1, id(str[idx])) + (idx > 0? (id(str[idx]) == prev): 0));
  }
 
  return dp[idx][prev] = ans;
}
 
void build_string(int idx, int prev, int mn_cost) {
  if (idx >= len) {
    return;
  }
 
  if (str[idx] == '?') {
    int x = solve(idx + 1, 1) + (idx > 0? (1 == prev): 0);
    int y = solve(idx + 1, 0) + (idx > 0? (0 == prev): 0);
    if (x <= y) {
      cout << "B";
      build_string(idx + 1, 1, mn_cost - (idx > 0? (1 == prev): 0));
      return;
    } else {
      cout << "R";
      build_string(idx + 1, 0, mn_cost - (idx > 0? (0 == prev): 0));
      return;
    }
  } else {
    cout << str[idx];
    build_string(idx + 1, id(str[idx]), (idx > 0? (id(str[idx]) == prev): 0));
    return;
  }
}
 
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> len >> str;
    memset(dp, -1, sizeof(dp));
    int mn_cost = solve(0, 0);
    build_string(0, 0, mn_cost);
    cout << "\n";
  }
  return 0;
}

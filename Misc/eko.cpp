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
const int N = 1e6 + 5;

int n;
LL need, height[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> need;
  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }

  LL lo = 0, hi = 1e9, ans = 0;
  while (lo <= hi) {
    LL mid = (lo + hi) / 2;
    LL got = 0;
    for (int i = 1; i <= n; i++) {
      if (mid <= height[i]) {
        got += height[i] - mid;
      }
    }
    if (got >= need) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans << "\n";
  return 0;
}

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

int n, k, a[N];

bool ok(int d) {
  int need = 0;
  for (int i = 2; i <= n; i++) {
    int diff = a[i] - a[i - 1];
    if (diff <= 1) continue;
    need += (diff - 1)/d;
    if (need > k) return false;
  }
  return need <= k;
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
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int lo = 1, hi = inf, ret = -1;
    while(lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (ok(mid)) ret = mid, hi = mid - 1;
      else lo = mid + 1;
    }
    cout << "Case #" << tc << ": " << ret << endl;
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b

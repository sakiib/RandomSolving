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
#define SZ(v) (int)v.size()
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 1e9;
const LL INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
 
const int k = 30;
 
int n, s, l, a[ N ];
int MX[ N ][ k ], MN[ N ][ k ];
int lg[ N ];
 
void Build_Table() {
  for(int i = 1; i <= n; i++) MN[i][0] = MX[i][0] = a[i];
  for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
  for (int j = 1; ( 1 << j ) <= n; j++) {
    for (int i = 1; i + ( 1 << j ) - 1 <= n; i++) {
      MN[i][j] = min(MN[i][j-1], MN[ i + ( 1 << (j-1) ) ][j-1]);
      MX[i][j] = max(MX[i][j-1], MX[ i + ( 1 << (j-1) ) ][j-1]);
    }
  }
}
 
pair <int,int> Query(int l, int r) {
  if( l > r ) swap(l, r);
  int k = lg[r-l+1];
  int mn = min( MN[l][k] , MN[ r - ( 1 << k ) + 1 ][k] );
  int mx = max( MX[l][k] , MX[ r - ( 1 << k ) + 1 ][k] );
  return { mn , mx };
}
 
template <typename T> class segment_tree {
public:
  vector <T> tree;
  static const T def = 1e9;
  segment_tree(int sz) {
    tree.resize(4 * sz + 5, 0);
  }
  inline void update(int node, int b, int e, int p, T v) {
    if (p > e || p < b || b > e) return;
    if (b == e && b == p) {
      tree[node] = v; return;
    }
    int l = node << 1, r = l | 1, m = (b + e) >> 1;
    update(l, b, m, p, v), update(r, m + 1, e, p, v);
    tree[node] = min(tree[l], tree[r]);
  }
  inline T query(int node, int b, int e, int i, int j) {
    if (i > e || j < b || b > e) return def;
    if (i <= b && j >= e) return tree[node];
    int l = node << 1, r = l | 1, m = (b + e) >> 1;
    return min(query(l, b, m, i, j), query(r, m + 1, e, i, j));
  }
};
 
void solve() {
    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    Build_Table();
 
    vector <int> prev (n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int lo = 1, hi = i, idx = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            pair <int,int> p = Query(mid, i);
            if (p.second - p.first <= s) idx = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        prev[i] = idx;
    }
 
    vector <int> dp(n + 1, inf);
    segment_tree <int> tree(n + 1);
 
    for (int i = 1; i <= n; i++) {
        int mn = tree.query(1, 0, n, prev[i] - 1, i - l);
        dp[i] = min(dp[i], mn + 1);
        tree.update(1, 0, n, i, dp[i]);
    }
 
    if (dp[n] == inf) cout << -1 << endl;
    else cout << dp[n] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1;
    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}

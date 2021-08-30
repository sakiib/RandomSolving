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
const int inf = 1e5;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 50 + 5;

int gold[N];
vector <int> graph[N];

void init() {
  for (int i = 1; i < N; i++) {
    graph[i].clear();
  }
}

void addEdge(int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}

int dfs(int s, int p) {
  int mx = 0;
  for (auto nxt: graph[s]) {
    if (nxt != p) {
      mx = max(mx, dfs(nxt, s) + gold[nxt]);
    }
  }
  return mx;
}

int solve() {
  vector <int> path_gold;
  for (auto node: graph[1]) {
    path_gold.push_back(dfs(node, 1) + gold[node]);
  }

  sort(path_gold.begin(), path_gold.end(), greater <int>());

  int ans = gold[1];
  if (path_gold.size() > 0) {
    ans += path_gold[0];
  }
  if (path_gold.size() > 1) {
    ans += path_gold[1];
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    init();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> gold[i];
    }

    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      cin >> u >> v;
      addEdge(u, v);
    }

    cout << "Case #" << tc << ": " << solve() << "\n";
  }
  return 0;
}



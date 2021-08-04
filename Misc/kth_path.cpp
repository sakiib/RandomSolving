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
const int N = 2e5 + 5;

int n, m, k;

struct data {
  int u, v, w;
  data(): u(-1), v(-1), w(0) {}
  data(int u, int v, int w): u(u), v(v), w(w) {}
  bool operator < (const data & q) const {
    return w < q.w;
  }
};

vector <data> edge;
int ID[N];
LL dp[1000][1000];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back(data(u, v, w));
  }
  sort(edge.begin(), edge.end());
  m = min(k, m);
  int id = 0;
  memset(dp, 63, sizeof(dp));
  for (int i = 0; i < m; i++) {
    if (ID[edge[i].u] == 0) ID[edge[i].u] = ++id;
    if (ID[edge[i].v] == 0) ID[edge[i].v] = ++id;
    dp[ID[edge[i].u]][ID[edge[i].v]] = edge[i].w;
    dp[ID[edge[i].v]][ID[edge[i].u]] = edge[i].w;
  }
  for (int k = 1; k <= id; k++) {
    for (int i = 1; i <= id; i++) {
      for (int j = 1; j <= id; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  vector < LL > cost;
  for (int i = 1; i <= id; i++) {
    for (int j = i + 1; j <= id; j++) {
      cost.push_back(dp[i][j]);
    }
  }
  sort(cost.begin(), cost.end());
  assert(cost.size() >= k);
  cout << cost[k - 1] << endl;
  return 0;
}

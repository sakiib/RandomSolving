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

int n;
string grid[N];

vector <int> transformToIntList(vector <pair <int, int>> &cells) {
  vector <int> ret;
  for (auto p: cells) {
    ret.push_back(p.first * N + p.second);
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int findWays(int mn_cost) {
  set <vector <int> > unq;
  for (int i = 0; i < n; i++) {
    // i'th row
    int cur_cost = 0;
    vector <pair <int, int> > cells;
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'O') {
        cur_cost = inf;
        break;
      } else if (grid[i][j] == '.') {
        cur_cost++;
        cells.push_back(make_pair(i, j));
      }
    }
    if (cur_cost >= inf) {
      continue;
    }
    if (cur_cost == mn_cost) {
      unq.insert(transformToIntList(cells));
    }
  }

  for (int i = 0; i < n; i++) {
    // i'th col
    int cur_cost = 0;
    vector <pair <int, int> > cells;
    for (int j = 0; j < n; j++) {
      if (grid[j][i] == 'O') {
        cur_cost = inf;
        break;
      } else if (grid[j][i] == '.') {
        cur_cost++;
        cells.push_back(make_pair(j, i));
      }
    }
    if (cur_cost >= inf) {
      continue;
    }
    if (cur_cost == mn_cost) {
      unq.insert(transformToIntList(cells));
    }
  }

  return (int)unq.size();
}

int findMinCost() {
  int cost = inf;
  for (int i = 0; i < n; i++) {
    // i'th row
    int cur_cost = 0;
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'O') {
        cur_cost = inf;
        break;
      } else if (grid[i][j] == '.') {
        cur_cost++;
      }
    }
    if (cur_cost >= inf) {
      continue;
    }
    cost = min(cost, cur_cost);
  }

  for (int i = 0; i < n; i++) {
    // i'th col
    int cur_cost = 0;
    for (int j = 0; j < n; j++) {
      if (grid[j][i] == 'O') {
        cur_cost = inf;
        break;
      } else if (grid[j][i] == '.') {
        cur_cost++;
      }
    }
    if (cur_cost >= inf) {
      continue;
    }
    cost = min(cost, cur_cost);
  }

  return cost;
}

pair <int, int> solve() {
  int mn_cost = findMinCost();
  if (mn_cost >= inf) {
    return {-1, -1};
  }

  int ways = findWays(mn_cost);

  return {mn_cost, ways};
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
    cin >> n;
    for (int i = 0; i < n; i++) cin >> grid[i];
    pair <int, int> ans = solve();
    if (ans == make_pair(-1, -1)) {
      cout << "Case #" << tc << ": " << "Impossible" << "\n";
    } else {
      cout << "Case #" << tc << ": " << ans.first << " " << ans.second << "\n";
    }
  }
  return 0;
}


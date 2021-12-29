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
const int N = 26 + 5;

int cost[N][N];

int id(char ch) {
    return (ch - 'A' + 1);
}

int solve(string &text) {
  int ans = inf;
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    int res = 0;
    for (int j = 0; j < text.size(); j++) {
      res += cost[id(text[j])][id(ch)];
    }
    ans = min(ans, res);
  }
  return ans >= inf? -1: ans;
}

void calculate() {
  for (int k = 1; k <= 26; k++) {
    for (int i = 1; i <= 26; i++) {
      for (int j = 1; j <= 26; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
}

void init() {
  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= 26; j++) {
      if (i == j) {
        cost[i][j] = 0;
      } else {
        cost[i][j] = inf;
      }
    }
  }
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
    string text;
    cin >> text;
    int replacements;
    cin >> replacements;
    for (int i = 1; i <= replacements; i++) {
      string x;
      cin >> x;
      cost[id(x[0])][id(x[1])] = 1;
    }
    calculate();
    cout << "Case #" << tc << ": " << solve(text) << "\n";
  }
  return 0;
}

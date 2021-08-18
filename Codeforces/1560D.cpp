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
const int N = 1e5 + 5;

vector <LL> p;

int min_moves(string a, string b) {
  int match = 0;
  for (int i = 0, j = 0; i < a.size() && j < b.size(); i++) {
    if (a[i] == b[j]) {
      match++;
      j++;
    }
  }
  return (a.size() - match + b.size() - match);
}

int solve(string s) {
  int ans = (int)s.size() + 1;
  for (auto val: p) {
    ans = min(ans, min_moves(s, to_string(val)));
  }
  return ans;
}

void gen_pow() {
  for (int i = 0; i <= 63; i++) {
    p.push_back(1LL << i);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);

  gen_pow();

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }
  return 0;
}


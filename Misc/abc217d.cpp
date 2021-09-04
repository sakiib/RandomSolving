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
const int N = 1e5 + 5;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;

  set <pair <int, int> > seg;
  seg.insert({0, n});

  while (q--) {
    int type, pos;
    cin >> type >> pos;

    if (type == 1) {
      auto it = seg.lower_bound({pos, 0});
      if (it == seg.end()) {
        --it;
      }
      int l = (*it).first, r = (*it).second;
      if (l > pos) {
        --it;
      }
      l = (*it).first, r = (*it).second;

      seg.erase(it);
      seg.insert({l, pos});
      seg.insert({pos, r});
    } else {
      auto it = seg.lower_bound({pos, 0});
      if (it == seg.end()) {
        --it;
      }
      int l = (*it).first, r = (*it).second;
       if (l > pos) {
        --it;
      }
      l = (*it).first, r = (*it).second;

      cout << r - l << endl;
    }
  }
  return 0;
}



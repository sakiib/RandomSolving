#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
  void __f(const char * name, Arg1 && arg1) {
    cerr << name << " : " << arg1 << "\n";
  }
template < typename Arg1, typename...Args >
  void __f(const char * na, Arg1 && arg1, Args && ...args) {
    const char * c = strchr(na + 1, ',');
    cerr.write(na, c - na) << " : " << arg1 << " , ";
    __f(c + 1, args...);
  }
#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())

typedef long long int LL;
typedef pair < int, int > pii;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

map <LL, int> cnt;
vector <int> V[N];
int n, s, parbena[N];

const int MOD[] = {
  1000000007,
  1000000009
};
const int base[] = {
  43,
  37
};

int p[N][2];

int mul(int x, int y, int MOD) {
  return (1 LL * x * y) % MOD;
}

int add(int x, int y, int MOD) {
  return x + y >= MOD ? x + y - MOD : x + y;
}

LL get_hash(vector <int> &cur) {
  vector <LL> h(2, 0);
  for (int i = 0; i < cur.size(); i++) {
    for (int j = 0; j < 2; j++) {
      h[j] = add(h[j], mul(p[i][j], cur[i], MOD[j]), MOD[j]);
    }
  }
  return (h[0] << 32) | h[1];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  p[0][0] = p[0][1] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      p[i][j] = mul(p[i - 1][j], base[j], MOD[j]);
    }
  }
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n >> s;
    cnt.clear();
    for (int i = 1; i <= n; i++) V[i].clear();
    memset(parbena, 0, sizeof(parbena));
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        V[i].push_back(x);
      }
      sort(V[i].begin(), V[i].end());
      cnt[get_hash(V[i])]++;
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
      vector < int > temp = V[i];
      int sz = temp.size();
      for (int j = 0; j < (1 << sz); j++) {
        vector < int > sub;
        for (int k = 0; k < sz; k++) {
          if (j & (1 << k)) sub.push_back(temp[k]);
        }
        sort(sub.begin(), sub.end());
        parbena[i] += cnt[get_hash(sub)];
      }
    }
    for (int i = 1; i <= n; i++) ans += (n - parbena[i]);
    cout << "Case #" << tc << ": " << ans << endl;
  }
  return 0;
}

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
const int inf = 2e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
 
vector <int> get_divisors(int n) {
    vector <int> ret;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (n / i != i) ret.push_back(n / i);
        }
    }
    return ret;
}
 
map <int,int> dp;
 
int solve(int n) {
    if (n == 1) return 0;
    if (dp.count(n)) return dp[n];
    int ret = inf;
    vector <int> d = get_divisors(n);
    ret = min(ret, solve(n - 1) + 1);
    for (auto x: d) {
        ret = min(ret, solve(n / x) + 1);
    }
    return dp[n] = ret;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif // LOCAL
    dp.clear();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << n - 1 << endl;
        } else {
            int cur = n - 3;
            cout << ((cur % 2) ? 2 : 3) << endl;
        }
    }
    return 0;
}

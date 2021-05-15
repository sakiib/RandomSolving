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
const int N = 2e5 + 5;
 
int n;
LL height[N];
 
LL calculateCost(LL x) {
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(height[i] - x);
    }
    return ans;
}
 
LL solve() {
    LL lo = 0, hi = 1e9, ans = 0;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (calculateCost(mid) < calculateCost(mid + 1)) {
            ans = calculateCost(mid);
            hi = mid - 1;
        }
        else {
            ans = calculateCost(mid + 1);
            lo = mid + 1;
        }
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif // LOCAL
 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> height[i];
 
    cout << solve() << "\n";
    return 0;
}

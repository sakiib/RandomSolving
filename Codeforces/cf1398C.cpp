#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    string s;
    int len;
    cin >> len;
    cin >> s;

    vector <int> a ((int)s.size() + 5, 0);
    for (int i = 0; i < s.size(); i++) {
        a[i + 1] = (s[i] - '0');
    }

    map <LL,LL> dp;

    LL ans = 0, pref = 0, prev = 0;
    for (int i = 1; i <= len; i++) {
        pref += a[i];
        dp[prev - i]++;
        ans += dp[pref - i - 1];
        prev = pref;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}

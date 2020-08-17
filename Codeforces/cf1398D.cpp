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
const int N = 2e2 + 5;

int la, lb, lc;
int a[ N ], b[ N ], c[ N ];
LL dp[ N ][ N ][ N ];

LL solve(int ca, int cb, int cc) {
    if ((ca > la && cb > lb) || (ca > la && cc > lc) || (cb > lb && cc > lc)) return 0;

    if (dp[ca][cb][cc] != -1) return dp[ca][cb][cc];
    LL ret = 0;
    if (ca <= la) ret = max(ret, solve(ca + 1, cb, cc));
    if (cb <= lb) ret = max(ret, solve(ca, cb + 1, cc));
    if (cc <= lc) ret = max(ret, solve(ca, cb, cc + 1));
    if (ca <= la && cb <= lb) {
        ret = max(ret, solve(ca + 1, cb + 1, cc) + (a[ca] * b[cb]));
    }
    if (ca <= la && cc <= lc) {
        ret = max(ret, solve(ca + 1, cb, cc + 1) + (a[ca] * c[cc]));
    }
    if (cb <= lb && cc <= lc) {
        ret = max(ret, solve(ca, cb + 1, cc + 1) + (b[cb] * c[cc]));
    }
    return dp[ca][cb][cc] = ret;
}

void solve() {
    cin >> la >> lb >> lc;
    for (int i = 1; i <= la; i++) cin >> a[i];
    for (int i = 1; i <= lb; i++) cin >> b[i];
    for (int i = 1; i <= lc; i++) cin >> c[i];
    sort(a + 1, a + la + 1);
    sort(b + 1, b + lb + 1);
    sort(c + 1, c + lc + 1);
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 1, 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1;
    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}

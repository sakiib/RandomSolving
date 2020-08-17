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
const int N = 2e5 + 5;

int n;
LL a[ N ], k;

void brute() {
    for (LL i = 1; i <= k; i++) {
        LL mx = -inf;
        for (int j = 1; j <= n; j++) mx = max(mx, a[j]);
        for (int j = 1; j <= n; j++) a[j] = mx - a[j];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (k%2 == 1) k = 1;
    else k = 2;
    brute();
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

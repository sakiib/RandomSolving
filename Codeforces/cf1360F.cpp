#include <bits/stdc++.h>
using namespace std;

#define SZ(v)(int) v.size()
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)), v.erase(unique(ALL(v)), v.end())
typedef long long LL;
typedef pair <int, int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 1e9;
const LL INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int Set(int N, int pos) {
    return N |= (1 << pos);
}
int Reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}
int Toggle(int N, int pos) {
    return (N ^= (1 << pos));
}

string s[20];
int n, m, dp[11][(1 << 11) + 1];

int ok(int idx, int mask) {
    if (idx >= m) return 1;
    if (dp[idx][mask] != -1) return dp[idx][mask];
    int ret = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (s[i][idx] != ch) {
                if (Check(mask, i)) good = false;
            }
        }
        int cur = mask;
        if (good) {
            for (int i = 0; i < n; i++) {
                if (s[i][idx] != ch) cur = Set(cur, i);
            }
            ret |= ok(idx + 1, cur);
        }
    }
    return dp[idx][mask] = ret;
}

void print(int idx, int mask) {
    if (idx >= m) return;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (s[i][idx] != ch) {
                if (Check(mask, i)) good = false;
            }
        }
        int cur = mask;
        if (good) {
            for (int i = 0; i < n; i++) {
                if (s[i][idx] != ch) cur = Set(cur, i);
            }
            if (ok(idx + 1, cur)) {
                cout << ch;
                print(idx + 1, cur);
                return;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    memset(dp, -1, sizeof(dp));
    if (ok(0, 0)) {
        print(0, 0);
        cout << endl;
    } else {
        cout << -1 << endl;
    }
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

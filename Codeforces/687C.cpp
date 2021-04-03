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
    int n, sum;
    cin >> n >> sum;
 
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    vector <vector <int> > dp (sum + 1, vector <int> (sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 0; j--) {
            for (int k = j; k >= 0; k--) {
                if (a[i] <= j) dp[j][k] |= dp[j - a[i]][k];
                if (a[i] <= j && a[i] <= k) dp[j][k] |= dp[j - a[i]][k - a[i]];
            }
        }
    }
 
    vector <int> v;
    for (int i = 0; i <= sum; i++) if (dp[sum][i]) v.push_back(i);
 
    cout << v.size() << endl;
    for (auto x: v) cout << x << " "; cout << endl;
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

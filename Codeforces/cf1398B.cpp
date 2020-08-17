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
    cin >> s;
    vector <int> v;
    for (int i = 0; i < s.size(); ) {
        if (s[i] == '1') {
            int j = i;
            while (j < s.size() && s[j] == '1') j++;
            v.push_back(j - i);
            i = j;
        }
        else {
            i++;
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i += 2) ans += v[i];
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

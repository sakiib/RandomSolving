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
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif // LOCAL
    int t;
    cin >> t;
    while (t--) {
        int len, q;
        cin >> len >> q;
        string s;
        cin >> s;
        s = "#" + s;
 
        vector <vector <int> > cnt ((int)s.size() + 2, vector <int> (2, 0));
        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; j <= 1; j++) {
                cnt[i][j] += cnt[i - 1][j] + ((s[i] - '0') == j);
            }
        }
 
        auto ok = [&] (int l, int r, int id) {
            if (l > r || l < 1 || r >= (int)s.size()) return false;
            return (cnt[r][id] - cnt[l - 1][id]) > 0;
        };
 
        while (q--) {
            int l, r;
            cin >> l >> r;
 
            if (ok(1, l - 1, s[l] - '0') || ok(r + 1, (int)s.size() - 1, s[r] - '0')) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

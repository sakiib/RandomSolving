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
#define SZ(v) (int)v.size()
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 1e9;
const LL INF = 8e18;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;
 
int n, m;
vector <int> graph[ N ];
int topic[ N ];
 
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    vector <pair <int,int> > v;
    for (int i = 1; i <= n; i++) {
        cin >> topic[i];
        v.push_back({topic[i], i});
    }
 
    sort(ALL(v));
    vector <int> order;
    vector <int> taken(n + 1, 0);
 
    for (auto x: v) {
        int choice = x.first, id = x.second;
        set <int> done;
        order.push_back(id);
        for (auto val: graph[id]) if (taken[val]) done.insert(taken[val]);
        int small = 0;
        for (auto x: done) if (x < choice) small++;
        if (small + 1 == choice && done.find(small + 1) == done.end()) taken[id] = small + 1;
        else {cout << -1 << endl; return;}
    }
 
    for (auto x: order) cout << x << " "; cout << endl;
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

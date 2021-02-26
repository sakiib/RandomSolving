#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 2e5 + 5;

struct data {
    int u, v, w;
    data() {}
    data(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator < (const data & q) const {
        return w > q.w;
    }
};

int n, q;
vector < pair < int, int > > query;
priority_queue < data > edge;
LL ans[N];

struct DISJOINT_SET_UNION {
    static
    const int MAXN = 2e5 + 5;
    int par[MAXN], sz[MAXN], compo;
    inline void makeset(int k) {
        compo = k;
        for (int i = 0; i <= k; i++) par[i] = i, sz[i] = 1;
    }
    inline int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }
    inline bool same_set(int x, int y) {
        return root(x) == root(y);
    }
    inline void unite(int x, int y) {
        int u = root(x), v = root(y);
        if (u == v) return;
        compo--;
        if (sz[v] <= sz[u]) par[v] = u, sz[u] += sz[v];
        else if (sz[v] > sz[u]) par[u] = v, sz[v] += sz[u];
    }
} dsu;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push(data(u, v, w));
    }
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        query.push_back(make_pair(x, i));
    }
    sort(query.begin(), query.end());
    dsu.makeset(n);
    
    auto nC2 = [&](LL x) {
	    return x * (x - 1) / 2;
	};
	
    LL res = 0;
    for (int i = 0; i < query.size(); i++) {
        int cur = query[i].first, id = query[i].second;
        while (!edge.empty()) {
            data tp = edge.top();
            if (tp.w > cur) break;
            edge.pop();
            int u = tp.u, v = tp.v;
            if (dsu.same_set(u, v)) {
                res -= nC2(dsu.sz[dsu.root(u)]);
            } else {
                res -= nC2(dsu.sz[dsu.root(u)]);
                res -= nC2(dsu.sz[dsu.root(v)]);
            }
            dsu.unite(u, v);
            res += nC2(dsu.sz[dsu.root(u)]);
        }
        ans[id] = res;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << " ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)), v.erase(unique(ALL(v)), v.end())

typedef long long int LL;
const int inf = 1e9;
const int N = 1e5 + 5;

const int MOD[] = {1000000007, 1000000009};

const int base[] = {43, 37};

const int invbase[] = {395348840, 297297300};

int tlen;
string txt;

int p[N][2];
int fh[N][2], bh[N][2];
int invmod[N][2];

inline int add(int x, int y, int MOD) {
    x += y;
    return x >= MOD ? x - MOD : x;
}

inline int sub(int x, int y, int MOD) {
    x -= y;
    return x < 0 ? x + MOD : x;
}

inline int mul(int x, int y, int MOD) {
    return (1LL * x * y) % MOD;
}

inline void gen_pow() {
    p[0][0] = p[0][1] = invmod[0][0] = invmod[0][1] = 1;
    for (int i = 1; i < N; i++) {
        for (int id = 0; id < 2; id++) {
            p[i][id] = mul(p[i - 1][id], base[id], MOD[id]);
            invmod[i][id] = mul(invmod[i - 1][id], invbase[id], MOD[id]);
        }
    }
}

inline LL fhash(string & s) {
    int l = s.size(), x = 0, y = 0;
    for (int i = 0; i < l; i++) {
        x = add(x, mul(p[i][0], s[i], MOD[0]), MOD[0]);
        y = add(y, mul(p[i][1], s[i], MOD[1]), MOD[1]);
    }
    return (1LL * x << 31LL) | (1LL * y);
}

inline void build_hash(string & txt) {
    tlen = txt.size();
    for (int i = 0, j = tlen - 1; i < tlen; i++, j--) {
        for (int id = 0; id < 2; id++) {
            fh[i][id] = mul(p[i][id], txt[i], MOD[id]);
            if (i) fh[i][id] = add(fh[i][id], fh[i - 1][id], MOD[id]);
            bh[i][id] = mul(p[j][id], txt[i], MOD[id]);
            if (i) bh[i][id] = add(bh[i][id], bh[i - 1][id], MOD[id]);
        }
    }
}
inline LL get_fhash(int l, int r) {
    if (l == 0) return (1LL * fh[r][0] << 31) | (1LL * fh[r][1]);
    int x = sub(fh[r][0], fh[l - 1][0], MOD[0]);
    x = mul(x, invmod[l][0], MOD[0]);
    int y = sub(fh[r][1], fh[l - 1][1], MOD[1]);
    y = mul(y, invmod[l][1], MOD[1]); return (1LL * x << 31LL) | (1LL * y);
}

set <LL> Hash[N];
vector <int> Len;
int dp[N];

int solve(int idx) {
    if (idx >= tlen) {
        return 0;
    }

    if (dp[idx] != -1) return dp[idx];

    int ret = inf;
    int remLen = tlen - idx;
    for (auto l: Len) {
        if (l > remLen) break;

        LL curHash = get_fhash(idx, idx + l - 1);
        if (Hash[l].find(curHash) != Hash[l].end()) {
            ret = min(ret, 1 + solve(idx + l));
        }
    }

    return dp[idx] = ret;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    gen_pow();

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        for (int i = 1; i < N; i++) Hash[i].clear();
        Len.clear();

        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            Hash[(int) s.size()].insert(fhash(s));
            Len.push_back((int) s.size());
        }

        UNIQUE(Len);

        cin >> txt;
        build_hash(txt);

        memset(dp, -1, sizeof(dp));
        int ans = solve(0);

        if (ans >= inf) {
            cout << "Case " << tc << ": " << "impossible" << "\n";
        } else {
            cout << "Case " << tc << ": " << ans << "\n";
        }
    }
    return 0;
}

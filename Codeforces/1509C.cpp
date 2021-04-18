#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e3 + 5;
const LL INF = 1e16;

int a[N];
LL dp[N][N];

LL solve(int l, int r) {
    if (l >= r) return 0;

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    LL ret = INF;
    ret = min(ret, a[r] - a[l] + min(solve(l + 1, r), solve(l, r - 1)));

    return dp[l][r] = ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = solve(i, j);
        }
    }

    cout << max(0LL, dp[1][n]) << "\n";
    return 0;
}

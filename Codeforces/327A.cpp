#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int INF = 1e5;
const int flipped = 1;

int n, a[N], dp[N][3];

int solve(int idx, int status) {
    if (idx > n) return status == !flipped? -INF: 0;
    if (dp[idx][status] != -1) return dp[idx][status];

    int ans = 0;
    if (status == !flipped) {
        ans = max(ans, solve(idx + 1, status) + a[idx]);
        ans = max(ans, solve(idx + 1, 1) + !(a[idx]));
    } else if (status == flipped) {
        ans = max(ans, solve(idx + 1, status) + !(a[idx]));
        ans = max(ans, solve(idx + 1, 2) + a[idx]);
    } else {
        ans = max(ans, solve(idx + 1, status) + a[idx]);
    }

    return dp[idx][status] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(1, 0) << "\n";
    return 0;
}

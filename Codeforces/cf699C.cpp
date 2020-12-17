#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <vector <int> > dp(n + 5, vector <int> (5, inf));
    for (int i = 0; i <= 3; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i][0], min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]))) + 1;
        if (a[i] == 1 || a[i] == 3) {
            dp[i][1] = min(dp[i][1], min(dp[i - 1][0], dp[i - 1][2]));
        }
        if (a[i] == 2 || a[i] == 3) {
            dp[i][2] = min(dp[i][2], min(dp[i - 1][0], dp[i - 1][1]));
        }
    }
    
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << "\n";
    return 0;
}

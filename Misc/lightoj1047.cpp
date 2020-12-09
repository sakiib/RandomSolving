#include <bits/stdc++.h>
using namespace std;
 
// loj - 1047
 
const int inf = 2e9;
 
int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int n;
        scanf("%d", &n);
        vector <vector <int> > col (n + 5, vector <int> (5, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                scanf("%d",&col[i][j]);
            }
        }
       
        vector <vector <int> > dp (n + 5, vector <int> (5, inf));
        for (int i = 1; i <= 3; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], col[i][j] + dp[i - 1][k]);
                    }
                }
            }
        }
       
        int ans = inf;
        for (int i = 1; i <= 3; i++) ans = min(ans, dp[n][i]);
        printf("Case %d: %d\n", tc, ans);
    }
    return 0;
}

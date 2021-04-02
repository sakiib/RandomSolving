#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
 
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    vector <int> sum (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
 
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (sum[i] == sum[n] - sum[i]) ans++;
    }
 
    cout << ans << "\n";
    return 0;
}

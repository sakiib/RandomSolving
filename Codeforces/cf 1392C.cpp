#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a (n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += max(0, a[i] - a[i + 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}

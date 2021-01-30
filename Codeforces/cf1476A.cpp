#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int sz = 1e5 + 5;
 
void solve() {
    LL n, k;
    cin >> n >> k;
    if (n == 1) cout << k << "\n";
    else if (n % k == 0) cout << 1 << "\n";
    else if (n > k) cout << 2 << "\n";
    else cout << (k + n - 1) / n << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

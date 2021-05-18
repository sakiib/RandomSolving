#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 5;
 
int n, tot;
pair <int, int> a[N];
 
int solve(int l, int r, int val) {
    if (l > r) return -1;
    int lo = l, hi = r, idx = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid].first == val) {
            return a[mid].second;
        } else if (a[mid].first > val) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> tot;
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
 
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = solve(1, i - 1, tot - a[i].first - a[j].first);
            int y = solve(i + 1, j - 1, tot - a[i].first - a[j].first);
            int z = solve(j + 1, n, tot - a[i].first - a[j].first);
            if (x != -1) return cout << a[i].second << " " << a[j].second << " " << x << "\n", 0;
            if (y != -1) return cout << a[i].second << " " << a[j].second << " " << y << "\n", 0;
            if (z != -1) return cout << a[i].second << " " << a[j].second << " " << z << "\n", 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}

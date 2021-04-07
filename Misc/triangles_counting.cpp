#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, points[N];

int lessOrEqual(int val) {
    int lo = 1, hi = n, ret = 0;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (points[mid] <= val) {
            ret = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> points[i];

        sort(points + 1, points + n + 1);

        cout << "Case " << tc << ":\n";
        while (q--) {
            int l, r;
            cin >> l >> r;

            // remeber how we calculate sum [l, r] = sum[r] - sum[l - 1]?
            // number of elements in range [l, r] 
            // = number of elemenst in range: [1, r] - [1, l - 1]

            int x = lessOrEqual(r);
            int y = lessOrEqual(l - 1);

            cout << (x - y) << "\n";
        }
    }
    return 0;
}

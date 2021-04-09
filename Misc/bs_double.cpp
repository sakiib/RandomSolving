#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const double eps = 1e-9;

int a[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, l;
    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto possible = [&](double rad) {
        double mxDist = 0.0;
        for (int i = 2; i <= n; i++) {
            mxDist = max(mxDist, (a[i] - a[i - 1]) * 0.5);
        }
        mxDist = max(mxDist, 1.0 * max(a[1] - 0, l - a[n]));
        return mxDist <= rad;
    };

    sort(a + 1, a + n + 1);

    int counter = 100;
    double lo = 0.0, hi = 1e10, ans = 0.0;
    while (hi - lo >= eps && counter--) {
        double mid = (lo + hi) * 0.5;
        if (possible(mid)) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << setprecision(10) << fixed << ans << "\n";
    return 0;
}

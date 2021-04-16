#include <bits/stdc++.h>
using namespace std;
 
const double EPS = 1e-9;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    double h, l;
    cin >> h >> l;
 
    double lo = 0.0, hi = 1e12;
    int iteration = 500;
 
    while (fabs(hi - lo) > EPS && iteration--) {
        double mid = (lo + hi) * 0.5;
 
        double x = mid * mid + l * l;
        double y = (h + mid) * (h + mid);
 
        if (x + EPS < y) hi = mid;
        else lo = mid;
    }
 
    cout << setprecision(13) << fixed << hi << "\n";
    return 0;
}

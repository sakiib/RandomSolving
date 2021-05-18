#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (ans < a[i]) {
            break;
        } else {
            ans += a[i];
        }
    }

    cout << ans << "\n";
    return 0;
}

// https://www.youtube.com/watch?v=lC4umMAajZo

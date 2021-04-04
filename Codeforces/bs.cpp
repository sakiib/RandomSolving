#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];

int binSearch(int idx, int n, int largest) {
    int lo = idx, hi = n, position = idx;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] <= largest) {
            position = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return position;
}

long long nC2(long long k) {
    return k * (k - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int smallest = a[i], largest = a[i] + d;

        int position = binSearch(i, n, largest);
        if (position == -1) continue;

        ans += nC2(position - i);
    }

    cout << ans << "\n";
    return 0;
}

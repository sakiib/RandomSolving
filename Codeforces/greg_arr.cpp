#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector <long long> a (N + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <int> l (N + 1);
    vector <int> r (N + 1);
    vector <long long> val (N + 1); 
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> val[i];
    }

    vector <long long> cnt (N + 1, 0);
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y + 1]--;
    }

    for (int i = 1; i <= 1e5; i++) {
        cnt[i] += cnt[i - 1];
    }

    vector <long long> ans (N + 1, 0);
    for (int i = 1; i <= m; i++) {
        ans[l[i]] += val[i] * cnt[i];
        ans[r[i] + 1] -= val[i] * cnt[i];
    }

    for (int i = 1; i <= 1e5; i++) {
        ans[i] += ans[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] + ans[i] << " ";
    }
    return 0;
}

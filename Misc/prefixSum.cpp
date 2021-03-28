#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];
long long prefixSum[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		prefixSum[i] = a[i] + (i > 0? prefixSum[i - 1]: 0);
	}

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;

		if (l > r) {
			swap(l, r);
		}

		cout << prefixSum[r] - (l > 0? prefixSum[l - 1]: 0) << "\n";
	}
	return 0;
}

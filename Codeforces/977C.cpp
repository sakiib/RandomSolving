#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n, k, a[N];
 
int countLessOrEqual(int ans) {
	int smallEq = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= ans) smallEq++;
	}
	return smallEq;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int lo = 1, hi = 1e9, ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int res = countLessOrEqual(mid);
		if (res == k) {
			ans = mid;
			hi = mid - 1; // or lo = mid + 1, doesn't matter really!
		} else if (res > k) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	
	cout << ans << "\n";
	return 0;
}

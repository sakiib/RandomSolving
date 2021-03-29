#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int N = 1e5 + 5;
 
LL a[N];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
 
	while (t--) {
		int n;
		cin >> n;
 
		LL w;
		cin >> w;
 
		map <LL,int> cnt;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
 
		LL rem = w;
		int ans = 1;
		while ((int)cnt.size() > 0) {
			LL mx = 0;
			for (auto x: cnt) if (x.first <= rem) mx = max(mx, x.first);
 
			if (mx == 0) ans++, rem = w;
			else {
				rem -= mx;
				cnt[mx]--;
				if (cnt[mx] == 0) cnt.erase(mx);
			}
		}
 
		cout << ans << "\n";
	}
	return 0;
}

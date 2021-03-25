#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
typedef long long LL;
 
string s;
int len, k;
int dp[55][55];
 
int solve(int idx, int diff, int lidx) {
	if (diff >= k) return N;
	if (idx >= lidx) return 0;
	if (dp[idx][diff] != -1) return dp[idx][diff];
 
	int ret = N;
	if (s[idx] == '.') {
		ret = min(ret, solve(idx + 1, diff + 1, lidx));
	} else {
		ret = min(ret, solve(idx + 1, diff + 1, lidx));
		ret = min(ret, solve(idx + 1, 0, lidx) + 1);
	}
 
	return dp[idx][diff] = ret;
}
 
int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> len >> k;
		cin >> s;
 
		int ans = 0;
		int fidx = -1, lidx = -1;
		for (int i = 0; i < len; i++) {
			if (s[i] == '*') {
				s[i] = 'x';
				ans ++;
				fidx = i;
				break;
			}
		}
 
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] == '*') {
				s[i] = 'x';
				ans ++;
				lidx = i;
				break;
			}
		}
 
		if (fidx == -1) {
			cout << 0 << "\n";
			continue;
		}
		if (lidx == -1) {
			cout << 1 << "\n";
			continue;
		}
 
		assert (ans == 2);
 
		memset(dp, -1, sizeof(dp));
		cout << 2 + solve(fidx + 1, 0, lidx) << "\n";
	}
	return 0;
}

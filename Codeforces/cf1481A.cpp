#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		string s;
		cin >> x >> y >> s;
		
		int lx = 0, ly = 0, rx = 0, ry = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			 if (s[i] == 'R') rx++;
	         else if (s[i] == 'L') lx--;
	         else if (s[i] == 'U') ry++;
	         else if (s[i] == 'D') ly--;
		}
		
		if (x <= rx && x >= lx && y <= ry && y >= ly) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}

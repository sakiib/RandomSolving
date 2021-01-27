#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
	set <long long> st;
	for (int i = 0; i <= 63; i++) {
		st.insert((1LL << i));
	}
	
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		if (st.find(n) != st.end()) {
			cout << "NO" << "\n";
		} else {
			cout << "YES" << "\n";
		}
	}
	return 0;
}

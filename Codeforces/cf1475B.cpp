#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector <int> dp (1e6 + 5, 0);
    dp[0] = 1;
    for (int i = 0; i <= 1000; i++) {
    	for (int j = 0; j <= 1000; j++) {
    		if (2020 * i + 2021 * j <= 1e6) {
    			dp[2020 * i + 2021 * j] = 1;
    		}
    	}
    }
    
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	cout << (dp[n]? "YES": "NO") << "\n";
    }
	return 0;
}

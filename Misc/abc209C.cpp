#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n; 
    cin >> n;
    vector <int> C(n);
    for (int i = 0; i < n; i++) cin >> C[i];
    
    sort (C.begin(), C.end());
    
    long long ans = 1;
    for (int i = 0; i < n; i++) {
    	ans = ans * max(0, C[i] - i) % mod;
    }
    
    cout << ans << "\n";
    return 0;
}

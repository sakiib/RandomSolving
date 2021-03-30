#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
 
        n %= 4;
 
        if (n == 0) {
            cout << "Even" << "\n";
        } else if (n == 1 || n == 3) {
            cout << "Odd" << "\n";
        } else {
            cout << "Same" << "\n";
        }
    }
    return 0;
}

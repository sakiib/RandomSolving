#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        long long n, d, c, ex;
        cin >> n >> d >> c >> ex;
        string s;
        cin >> s;
        long long dog = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                dog++;
            }
        }
        long long fed = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                if (d > 0) {
                    d--;
                    c += ex;
                    fed++;
                } else {
                    break;
                }
            } else {
                if (c > 0) {
                    c--;
                } else {
                    break;
                }
            }
        }
        if (fed == dog) {
            cout << "Case #" << tc << ": " << "YES" << "\n";
        } else {
            cout << "Case #" << tc << ": " << "NO" << "\n";
        }
    }
    return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3771

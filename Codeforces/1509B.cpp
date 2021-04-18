#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        int len;
        string s;
        cin >> len >> s;

        int T = 0, M = 0;
        bool possible = true;

        for (int i = 0; i < len; i++) {
            if (s[i] == 'T') T++;
            else M++;
            if (M > T) {
                possible = false;
                break;
            }
        }

        if (2 * M != T) possible = false;

        T = 0, M = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == 'T') T++;
            else M++;
            if (M > T) {
                possible = false;
                break;
            }
        }

        cout << (possible? "YES": "NO") << "\n";
    }  
    return 0;
}

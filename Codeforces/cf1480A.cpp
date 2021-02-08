#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool alice = true;
        for (int i = 0; i < s.size(); i++) {
            if (alice) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (s[i] != ch) {
                        s[i] = ch;
                        break;
                    }
                }
            } else {
                for (char ch = 'z'; ch >= 'a'; ch--) {
                    if (s[i] != ch) {
                        s[i] = ch;
                        break;
                    }
                }
            }
            alice = !alice;
        }
 
        cout << s << "\n";
    }
    return 0;
}

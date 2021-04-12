#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // freopen("input.txt", "r", stdin);
 
    int t;
    cin >> t;
 
    while (t--) {
        int zeros, ones;
        string s;
        cin >> zeros >> ones >> s;
 
        int len = s.size();
        bool possible = true;
 
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') zeros--;
            if (s[i] == '1') ones--;
        }
 
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != '?' && s[len - i - 1] != '?') {
                continue;
            }
            if (s[i] == '?' && s[len - i - 1] == '?') {
                continue;
            }
            if (s[i] == '?') {
                if (s[len - i - 1] == '1') {
                    if (ones > 0) ones--, s[i] = '1';
                    else possible = false;
                }
                if (s[len - i - 1] == '0') {
                    if (zeros > 0) zeros--, s[i] = '0';
                    else possible = false;
                }
            } else {
                if (s[i] == '1') {
                    if (ones > 0) ones--, s[len - 1 - i] = '1';
                    else possible = false;
                }
                if (s[i] == '0') {
                    if (zeros > 0) zeros--, s[len - 1 - i] = '0';
                    else possible = false;
                }
 
            }
        }
 
        // cout << ones << " " << zeros << " " << s << " " << possible << endl;
 
        if (!possible) {
            cout << -1 << "\n";
            continue;
        }
 
        for (int i = 0; i < len / 2; i++) {
            if (s[i] == '?' && s[len - 1 - i] == '?') {
                if (ones >= zeros) {
                    if (ones >= 2) ones -= 2, s[i] = '1', s[len - 1 - i] = '1';
                    else possible = false;
                } else {
                    if (zeros >= 2) zeros -= 2, s[i] = '0', s[len - 1 - i] = '0';
                    else possible = false;
                }
            }
        }
 
        // cout << ones << " " << zeros << " " << s << " " << possible << endl;
 
 
        if (len % 2) {
            if (s[(len / 2) ] == '?') {
                if (ones) ones--, s[(len / 2)] = '1';
                else if (zeros) zeros--, s[(len / 2)] = '0';
                else possible = false;
            }
        }
 
        if (ones || zeros) possible = false;
 
        for (int i = 0; i < len; i++) if (s[i] == '?') possible = false;
        for (int i = 0; i < len / 2; i++) if (s[i] != s[len - 1 - i]) possible = false;
            
        if (!possible) {
            cout << -1 << "\n";
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}

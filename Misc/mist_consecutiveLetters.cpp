#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string s;
        cin >> s;
        int len = s.size();

        set <pair<int,int> > segments;
        for (int i = 0; i < len; i += 0) {
            int j = i;
            while (j < len && s[i] == s[j]) j++;
            segments.insert(make_pair(i, j - 1));
            i = j;
        }

        cout << "Case " << tc << ":\n";
        int q;
        cin >> q;
        while (q--) {
            int type, pos;
            cin >> type >> pos;
            if (type == 1) {
                auto it = segments.upper_bound(make_pair(pos, inf)); --it;
                cout << (*it).second - (*it).first + 1 << "\n";
            }
            else {
                auto it = segments.upper_bound(make_pair(pos, inf)); --it;
                int l = (*it).first, r = (*it).second;
                segments.erase(it);
                if (l != pos && pos - 1 >= 0) segments.insert(make_pair(l, pos - 1));
                if (r != pos && pos + 1 < len) segments.insert(make_pair(pos + 1, r));
            }
        }
    }
    return 0;
}


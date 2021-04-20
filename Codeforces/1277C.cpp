#include <bits/stdc++.h>
using namespace std;
 
const int inf = 1e9;
const int N = 2e5 + 5;
 
int len;
string s;
int dp[ N ][ 5 ][ 5 ];
string a = "one";
string b = "two";
vector <int> ans;
int mn;
 
int solve(int idx, int x, int y) {
    if (x >= 3 || y >= 3) return inf;
  
    if (idx >= len) return x >= 3 || y >= 3 ? inf : 0;
  
    if (dp[idx][x][y] != -1) return dp[idx][x][y];
  
    int ret = inf;
    ret = min(ret, solve(idx + 1, (s[idx] == a[x]) ? x + 1 : (s[idx] == a[0] ? 1 : 0),
                                  (s[idx] == b[y]) ? y + 1 : (s[idx] == b[0] ? 1 : 0)));
    ret = min(ret, 1 + solve(idx + 1, x, y));
  
    return dp[idx][x][y] = ret;
}

void print(int idx, int x, int y, int cur) {
    if (idx >= len) return;
  
    if (1 + solve(idx + 1, x, y) + cur == mn) {
        ans.push_back(idx);
        print(idx + 1, x, y, cur + 1);
        return;
    }
    else {
        print(idx + 1, (s[idx] == a[x]) ? x + 1 : (s[idx] == a[0] ? 1 : 0),
                       (s[idx] == b[y]) ? y + 1 : (s[idx] == b[0] ? 1 : 0), cur);
        return;
    }
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        len = s.size();
      
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= 3; j++) {
                for (int k = 0; k <= 3; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
      
        ans.clear();
      
        mn = solve(0, 0, 0);
        print(0, 0, 0, 0);
      
        cout << mn << "\n";
        for (auto x: ans) cout << x + 1 << " "; cout << "\n";
    }
    return 0;
}

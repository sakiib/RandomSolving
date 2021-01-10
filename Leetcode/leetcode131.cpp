class Solution {
public:
    vector <vector <string> > ans;
    
    bool palindrome(int l, int r, string s) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++; r--;
        }
        return true;
    }
    
    void solve(int idx, string s, vector <string> v) {
        if (idx >= s.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (palindrome(idx, i, s)) {
                v.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        solve(0, s, {});
        return ans;
    }
};

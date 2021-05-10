class Solution {
public:
    int longestPalindrome(string s) {
        map <char, int> cnt;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]]++;
        }
        
        int ans = 0;
        bool odd = false;
        for (auto x: cnt) {
            if (x.second % 2 == 0) ans += x.second;
            else ans += x.second - 1, odd = true;
        }
        
        return ans + (odd? 1: 0);
    }
};

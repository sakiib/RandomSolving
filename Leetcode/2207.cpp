class Solution {
public:
    long long solve(string s, string t) {
        long long res = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[1]) {
                res += cnt;
            }
            if (s[i] == t[0]) {
                cnt++;
            }
        }
        
        return res;
    }
    
    long long maximumSubsequenceCount(string text, string pattern) {
        string x = pattern[0] + text;
        string y = text + pattern[1];
        return max(solve(x, pattern), solve(y, pattern));
    }
};

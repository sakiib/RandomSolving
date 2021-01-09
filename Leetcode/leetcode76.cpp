class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.size(), tlen = t.size();
        
        int l = 0, r = 0;
        map <char,int> have, need;
        
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }
        
        auto ok = [&](){
            for (auto x: need) {
                if (have[x.first] < x.second) {
                    return false;
                }
            }
            return true;
        };
        
        int minlen = 1e6, start = -1;
        string ans = "";
        
        while (r < s.size()) {
            have[s[r]]++;
            while (ok() && l <= r) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }
                have[s[l]]--;
                l++;
            }
            r++;
        }
        
        if (minlen == 1e6) {
            return "";
        }
        
        ans = s.substr(start, minlen);
        return ans;
    }
};

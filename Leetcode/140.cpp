class Solution {
public:
    vector <string> res;
    map <string, bool> have;
    
    void solve(vector<string>& wordDict, string s, int idx, string str) {
        if (idx >= (int)s.size()) {
            res.push_back(str);
            return;
        }
        
        for (int i = idx; i < (int)s.size(); i++) {
            if (have.count(s.substr(idx, i - idx + 1))) {
                string cur = s.substr(idx, i - idx + 1);
                if ((int)str.size() > 0) {
                    cur = str + " " + cur;
                } 
                solve(wordDict, s, i + 1, cur);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto word: wordDict) {
            have[word] = true;
        }
        
        solve(wordDict, s, 0, "");
        
        return res;
    }
};

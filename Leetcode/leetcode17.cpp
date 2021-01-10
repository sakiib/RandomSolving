class Solution {
public:
    vector <string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector <string> words;
    
    void solve(int idx, string digits, string res) {
        if (idx >= digits.size()) {
            words.push_back(res);
            return;
        }
        
        int cur = digits[idx] - '0';
        for (auto x: v[cur]) {
            solve(idx + 1, digits, res + x);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        
        solve(0, digits, "");
        return words;
    }
};

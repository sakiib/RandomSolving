class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        
        auto subsequence = [&](string word, string s) {
            int idx = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == word[idx]) idx++;
                if (idx == word.size()) return true;
            }
            return false;
        };
        
        string ans = "";
        for (auto word: dictionary) {
            if (subsequence(word, s)) {
                if (word.size() > ans.size()) {
                    ans = word;
                }
            }
        }
        
        return ans;
    }
};

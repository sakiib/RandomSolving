// Link: https://leetcode.com/contest/weekly-contest-275/problems/count-words-obtained-after-adding-a-letter/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        map <string, bool> have;
        for (auto word: startWords) {
            sort(word.begin(), word.end());
            have[word] = true;
        }
        
        int ans = 0;
        for (auto word: targetWords) {
            string cur = word;
            sort(cur.begin(), cur.end());
            for (int i = 0; i < cur.size(); i++) {
                string temp = cur;
                string now = "";
                for (int j = 0; j < cur.size(); j++) {
                    if (i != j) {
                        now += temp[j];
                    }
                }
                if (have.count(now)) {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};

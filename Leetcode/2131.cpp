class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        
        map <string, int> have;
        for (auto word: words) {
            if (word[0] == word[1]) {
                continue;
            }
            string temp = word;
            reverse(temp.begin(), temp.end());
            if (have[temp] > 0) {
                ans += 4;
                have[temp]--;
            } else {
                have[word] ++;
            }
        }
        
        
        map <string, int> same;
        for (auto word: words) {
            if (word[0] == word[1]) {
                same[word]++;
            }
        }
        
        bool done = false;
        for (auto [key, val]: same) {
            if (val % 2 == 0) {
                ans += 2 * val;
            } else {
                if (!done) {
                    ans += 2 * val;
                    done = true;
                } else {
                    ans += 2 * (val - 1);
                }
            }
        }
        
        return ans;
    }
};

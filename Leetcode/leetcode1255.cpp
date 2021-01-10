class Solution {
public:
    int solve(int idx, vector <string>& words, map <char,int> cnt, vector <int> &score) {
        if (idx == words.size()) {
            return 0;
        }
        int mx = 0;
        mx = max(mx, solve(idx + 1, words, cnt, score));
        
        map <char,int> temp = cnt;
        map <char,int> need;
        
        for (auto ch: words[idx]) {
            need[ch]++;
        }
        
        bool can = true;
        for (auto ch: words[idx]) {
            if (cnt[ch] < need[ch]) {
                can = false;
            }
        }
        
        if (can) {
            int add = 0;
            vector <bool> done (30, false);
            for (auto ch: words[idx]) {
                if (done[ch - 'a']) continue;
                done[ch - 'a'] = true;
                temp[ch] -= need[ch];
                add += score[ch - 'a'] * need[ch];
            }
            mx = max(mx, solve(idx + 1, words, temp, score) + add);
        }
        
        return mx;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map <char,int> cnt;
        for (auto ch: letters) {
            cnt[ch]++;
        }
        
        return solve(0, words, cnt, score);
    }
};

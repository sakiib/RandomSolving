class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map <string,int> have;
        for (auto &word: wordList) have[word] = 1;
        
        map <string,int> cost;
        queue <string> q;
        q.push(beginWord);
        cost[beginWord] = 1;
        
        while (!q.empty()) {
            string f = q.front();
            q.pop();
            for (int i = 0; i < f.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == f[i]) continue;
                    string cur = f;
                    cur[i] = ch;
                    if (!cost.count(cur) && have.count(cur)) {
                        cost[cur] = cost[f] + 1;
                        q.push(cur);
                    }
                }
            }
        }
        return cost.count(endWord) ? cost[endWord] : 0;
    }
};

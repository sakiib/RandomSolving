class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> indices;
        vector <int> need (26, 0);
        vector <vector <int> > occurrence(s.size(), vector <int> (26, 0));
        
        for (int i = 0; i < p.size(); i++) need[p[i] - 'a']++;
        
        for (int i = 0; i < s.size(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                occurrence[i][ch - 'a'] = (ch == s[i]);
                if (i > 0) occurrence[i][ch - 'a'] += occurrence[i - 1][ch - 'a'];
            }
        }
        
        auto anagrams = [&] (int l, int r) {
            for (int i = 0; i < 26; i++) {
                int have = occurrence[r][i] - (l > 0? occurrence[l - 1][i]: 0);
                if (have != need[i]) return false;
            }    
            return true;
        };
        
        for (int i = 0; i + p.size() - 1 < s.size(); i++) {
            if (anagrams(i, i + p.size() - 1)) indices.push_back(i);
        }
        
        return indices;
    }
};

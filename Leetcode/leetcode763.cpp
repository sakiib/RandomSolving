class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.size();
        vector <vector <int> > cnt (len + 5, vector <int> (30, 0));
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i][j] = (S[i] - 'a' == j);
                if (i > 0) cnt[i][j] += cnt[i - 1][j];
            }
        }
        
        int curLength = 0;
        vector <int> ans;
        map <char,int> have;
        
        auto getCnt = [&](int l, int r, int id) {
            if (l == 0) return cnt[r][id];
            else return cnt[r][id] - cnt[l - 1][id];
        };
        
        auto canPartition = [&](int l, int r) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                int cnt = getCnt(l, r, ch - 'a');
                if (cnt > 0 && have.count(ch) > 0) return false;
            }
            return true;
        };
        
        for (int i = 0; i < len; i++) {
            curLength += 1;
            have[S[i]]++;
            if (canPartition(i + 1, len - 1)) {
                have.clear();
                ans.push_back(curLength);
                curLength = 0;
            }
        }
        if (curLength > 0) ans.push_back(curLength);
        
        return ans;
    }
};

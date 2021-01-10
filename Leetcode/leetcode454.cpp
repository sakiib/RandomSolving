class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map <int,int> cnt;
        for (auto &a: A) {
            for (auto &b: B) {
                cnt[a + b]++;
            }
        }
        
        int ans = 0;
        for (auto &c: C) {
            for (auto &d: D) {
                ans += cnt[-(c + d)];
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> cnt (105, 0);
        for (auto val: nums) cnt[val]++;
        
        for (int i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
        
        vector <int> ans;
        for (auto val: nums) {
            if (val == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(cnt[val - 1]);
            }
        }
        
        return ans;
    }
};

// O(N)

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map <int, int> cnt;
        for (auto val: nums) {
            cnt[val]++;
        }
        
        for (auto [key, val]: cnt) {
            if (val % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};

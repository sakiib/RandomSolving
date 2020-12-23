class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (auto num: nums) {
            ans = (ans^num);
        }
        return ans;
    }
};

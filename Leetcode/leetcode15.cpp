class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector <int> > ans;
        
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = (int)nums.size() - 1, need = -nums[i];
            while (l < r) {
                int cur = nums[l] + nums[r];
                if (cur < need) {
                    l++;
                } else if (cur > need) {
                    r--;
                } else {
                    vector <int> temp = {-need, nums[l], nums[r]};
                    ans.push_back(temp);
                    while (l < r && nums[l] == temp[1]) l++;
                    while (l < r && nums[r] == temp[2]) r--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};

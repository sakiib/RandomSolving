class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        vector <vector <int> > ans;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int need = target - nums[i];
            int l = i + 1, r = (int)nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] > need) {
                    r--;
                } else if (nums[l] + nums[r] < need) {
                    l++;
                } else {
                    ans.push_back(vector <int> {nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < nums.size() && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (r >= 0 && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector <vector <int> > ans;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j += 0) {
                int need = target - nums[i] - nums[j];
                int l = j + 1, r = (int)nums.size() - 1;
                while (l < r) {
                    if (nums[l] + nums[r] > need) {
                        r--;
                    } else if (nums[l] + nums[r] < need) {
                        l++;
                    } else {
                        ans.push_back(vector <int> {nums[i], nums[j], nums[l], nums[r]});
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
                int id = j + 1;
                while (id < nums.size() && nums[j] == nums[id]) {
                    id++;
                }
                j = id;
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    vector <int> temp;
    vector <vector <int> > ans;
    bool used[10];
    
    void generate(vector <int> &nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                temp.push_back(nums[i]);
                generate(nums);
                used[i] = false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums);
        return ans;
    }
};

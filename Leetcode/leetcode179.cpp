class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> v;
        for (auto num: nums) {
            v.push_back(to_string(num));
        }
        
        sort(v.begin(), v.end(), [] (string a, string b) {
            return a + b > b + a;
        });
        
        string ans = "";
        for (auto s: v) ans += s;
        
        reverse(ans.begin(), ans.end());
        
        while ((int)ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

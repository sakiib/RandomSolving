class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector <int> mul[3];
        int sum = 0;
        for (auto d: digits) {
            mul[d % 3].push_back(d);
            sum += d;
        }
        
        for (int i = 0; i <= 2; i++) {
            sort(mul[i].begin(), mul[i].end());
            reverse(mul[i].begin(), mul[i].end());
        }
        
        if (sum % 3 == 1) {
            if (mul[1].size() > 0) {
                sum -= mul[1].back();
                mul[1].pop_back();
            } else if (mul[2].size() > 1) {
                sum -= mul[2].back();
                mul[2].pop_back();
                sum -= mul[2].back();
                mul[2].pop_back();
            }
            
            if (sum % 3 != 0) return "";
        } else if (sum % 3 == 2) {
            if (mul[2].size() > 0) {
                sum -= mul[2].back();
                mul[2].pop_back();
            } else if (mul[1].size() > 1) {
                sum -= mul[1].back();
                mul[1].pop_back();
                sum -= mul[1].back();
                mul[1].pop_back();
            }
            
            if (sum % 3 != 0) return "";
        }
        
        string ans = "";
        for (int i = 0; i <= 2; i++) {
            for (auto d: mul[i]) {
                ans += ((char)(d+'0'));
            }
        }
        
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        
        while (ans.size() > 1 && ans[0] == '0') ans = ans.substr(1, ans.size() - 1);
        
        return ans;
    }
};

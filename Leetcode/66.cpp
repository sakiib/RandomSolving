class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = 0; i < len / 2; i++) {
            swap(digits[i], digits[len - 1 - i]);
        }
        
        int carry = 1;
        vector <int> ans;
        for (int i = 0; i < digits.size(); i++) {
            ans.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        if (carry) {
            ans.push_back(carry);
        }
        
        len = ans.size();
        for (int i = 0; i < len / 2; i++) {
            swap(ans[i], ans[len - 1 - i]);
        }
        
        return ans;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        while (num1.size() < num2.size()) num1 = "0" + num1;
        while (num2.size() < num1.size()) num2 = "0" + num2;
        
        string ans = "";
        int carry = 0;
        
        for (int i = num1.size() - 1; i >= 0; i--) {
            int dig = (num1[i] - '0') + (num2[i] - '0') + carry;
            carry = dig / 10;
            dig %= 10;
            ans += (char)(dig + '0');
        }
        if (carry) ans += (char)(carry + '0');
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

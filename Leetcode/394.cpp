class Solution {
public:
    string decodeString(string s) {
        stack <string> st;
        for (auto ch: s) {
            if (ch == ']') {
                string temp = "";
                while (!st.empty() && st.top() != "[") {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());
                
                string num = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int times = stoi(num);
                string res = "";
                for (int i = 1; i <= times; i++) {
                    res += temp;
                }
                reverse(res.begin(), res.end());
                st.push(res);
            } else {
                st.push(string (1, ch));
            }
        }
        
        string decoded = "";
        while (!st.empty()) {
            decoded += st.top();
            st.pop();
        }
        reverse(decoded.begin(), decoded.end());
        return decoded;
    }
};

class Solution {
public:
    bool opening(char s) {
        return s == '(' || s == '[' || s == '{';
    }
    bool match(char opening, char closing) {
        if (opening == '(' && closing == ')') return true;
        if (opening == '[' && closing == ']') return true;
        if (opening == '{' && closing == '}') return true;
        return false;
    }
    bool isValid(string s) {
        stack <char> st;
        for (int i = 0; i < s.size(); i++) {
            if (opening(s[i])) {
                st.push(s[i]);
            }
            else {
                if (st.empty()) st.push(s[i]);
                else {
                    if (match(st.top(), s[i])) st.pop();
                    else st.push(s[i]);
                }
            }
        }
        if (st.empty()) return true;
        else return false;
    }
};

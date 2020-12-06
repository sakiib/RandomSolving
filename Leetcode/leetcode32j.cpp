class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len == 0) return 0;
        vector <int> dp (len + 5, 0);
        stack <pair <char,int> > st;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push(make_pair('(', i));
            } else {
                if (st.empty()) continue;
                if (st.top().first == '(') {
                    if (st.top().second > 0) {
                        dp[i] = dp[st.top().second - 1] + (i - st.top().second + 1);
                    } else {
                        dp[i] = (i - st.top().second + 1);
                    }
                    st.pop();
                } else {
                    st.push(make_pair(')', i));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < len; i++) ans = max(ans, dp[i]);
        return ans;
    }
};

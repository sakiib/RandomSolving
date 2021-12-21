class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int ans = 0;
        vector <vector <int>> dp = vector <vector <int>> (row, vector <int> (col, 0));
        for (int i = 0; i < row; i++) {
            vector <int> heights;
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = (i > 0? dp[i - 1][j] + 1: 1);
                }
                heights.push_back(dp[i][j]);
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        vector <int> left_limit(sz, 0), right_limit(sz, 0);
        stack <int> st;
        for (int i = 0; i < sz; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                left_limit[i] = 0;
            } else {
                left_limit[i] = st.top() + 1;
            }
            
            st.push(i);
        }
        
        while (!st.empty()) {
            st.pop();
        }
        
       
        for (int i = sz - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                right_limit[i] = sz - 1;
            } else {
                right_limit[i] = st.top() - 1;
            }
            
            st.push(i);
        }
        
        int area = 0;
        for (int i = 0; i < sz; i++) {
            area = max(area, heights[i] * (right_limit[i] - left_limit[i] + 1));
        }
        
        return area;
    }
};

class Solution {
public:
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

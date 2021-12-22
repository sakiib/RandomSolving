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
        vector <int> v;
        vector <int> can ((int)heights.size(), 0);
        
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (v.size() > 0 && heights[v.back()] >= heights[i]) v.pop_back();
            can[i] = (v.size() == 0? heights.size() - i: v.back() - i);
            v.push_back(i);
        }
        
        v.clear();
        
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (v.size() > 0 && heights[v.back()] >= heights[i]) v.pop_back();
            ans = max(ans, heights[i] * (can[i] + (v.size() == 0? i + 1: i - v.back()) - 1));
            v.push_back(i);
        }
        
        return ans;
    }
};

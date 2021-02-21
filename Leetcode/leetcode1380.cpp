class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector <int> ans;
        
        auto lucky = [&](int val, int r, int c) {
            int mn = 1e9;
            for (int i = 0; i < col; i++) mn = min(mn, matrix[r][i]);
            int mx = -1e9;
            for (int i = 0; i < row; i++) mx = max(mx, matrix[i][c]);
            return mn == mx && mn == val;
        };
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (lucky(matrix[i][j], i, j)) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

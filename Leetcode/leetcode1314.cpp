class Solution {
public: 
    int row, col;
    int extractSum(int i, int j, const vector<vector<int>>& sum) {
        if (i < 0 || j < 0) return 0;
        if (i >= row) i = row - 1;
        if (j >= col) j = col - 1;
        return sum[i][j];
    }
        
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        row = mat.size();
        col = mat[0].size();
        
        vector<vector<int>> sum(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sum[i][j] = mat[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) - extractSum(i-1, j-1, sum);
            }
        }
        
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extractSum(i-K-1, j-K-1, sum);
            }
        }
        
        return ans;
    }
};

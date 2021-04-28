class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    int dp[201][201];
    
    bool insideMatrix(int nx, int ny, int row, int col) {
        return (nx >= 0 && ny >= 0 && nx < row && ny < col);    
    }
    
    int longestIncPath(int x, int y, int row, int col, vector <vector<int>>& matrix) {
        if (dp[x][y] != -1) return dp[x][y];
        
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!insideMatrix(nx, ny, row, col)) continue;
            if (matrix[nx][ny] <= matrix[x][y]) continue;
            ans = max(ans, 1 + longestIncPath(nx, ny, row, col, matrix));
        }
        
        return dp[x][y] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        
        int ans = 1;
        
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans = max(ans, 1 + longestIncPath(i, j, row, col, matrix));
            }
        }
        
        return ans;
    }
};
   

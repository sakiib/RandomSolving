class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    
    int row, col, dp[205][205];
    
    int solve(int x, int y, vector<vector<int>>& matrix) {
        if (dp[x][y] != -1) return dp[x][y];
        int ret = 0;
        for (int id = 0; id < 4; id++) {
            int nx = x + dx[id], ny = y + dy[id];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] > matrix[x][y]) {
                ret = max(ret, 1 + solve(nx, ny, matrix));
            }
        }
        return dp[x][y] = ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        int ans = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans = max(ans, 1 + solve(i, j, matrix));
            }
        }
        
        return ans;
    }
};

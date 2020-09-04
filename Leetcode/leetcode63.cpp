class Solution {
public:
    const int inf = 2e9;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector <vector <int> > dp (row, vector <int> (col, 0));
        dp[0][0] = 1;
        for (int i = 0; i < row; i++) {
            if (obstacleGrid[i][0] == 1) break;
            else dp[i][0] = 1;
        }
        for (int j = 0; j < col; j++) {
            if (obstacleGrid[0][j] == 1) break;
            else dp[0][j] = 1;
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return obstacleGrid[row - 1][col - 1] == 0 ? dp[row - 1][col - 1] : 0;
    }
};

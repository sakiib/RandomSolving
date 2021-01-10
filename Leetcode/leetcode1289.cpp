class Solution {
public:
    const int inf = 1e9;
    int minFallingPathSum(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        
        vector <vector <int> > dp = vector <vector <int> > (row + 1, vector <int> (col + 1, inf));
        for (int j = 0; j < col; j++) dp[0][j] = arr[0][j];
        
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col; k++) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + arr[i][j]);
                    }
                }
            }
        }
        
        int mn = inf;
        for (int j = 0; j < col; j++) mn = min(mn, dp[row - 1][j]);
        
        return mn;
    }
};

class Solution {
public:
    const int inf = 2e7;
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size(), col = 0;
        for (auto &x: triangle) col = (int)x.size();
        if (row == 0) return 0;
        
        vector <vector <int>> dp (2, vector <int> (col, inf));
        int id = 0;
        dp[id][0] = triangle[0][0];
        
        for (int i = 1; i < row; i++) {
            id = (id ^ 1);
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i - 1 >= 0) dp[id][j] = dp[id ^ 1][j] + triangle[i][j];
                if (i - 1 >= 0 && j - 1 >= 0) dp[id][j] = min(dp[id][j], dp[id ^ 1][j - 1] + triangle[i][j]);
            }
        }
        
        int ans = inf;
        for (int j = 0; j < col; j++) ans = min(ans, dp[id][j]);
        return ans;
    }
};

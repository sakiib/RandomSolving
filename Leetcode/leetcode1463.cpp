class Solution {
public:
    int dp[75][75][75];
    int row, col;
    
    int solve(vector<vector<int>>& grid, int r, int c1, int c2) {
        if (r == row) return 0;
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        auto inside = [&](int c1, int c2) {
            return c1 >= 0 && c2 >= 0 && c1 < col && c2 < col;
        };
        
        int mx = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (!inside(nc1, nc2)) continue;
                int cherries = (c1 == c2)? grid[r][c1] : grid[r][c1] + grid[r][c2];
                mx = max(mx, solve(grid, r + 1, nc1, nc2) + cherries);
            }
        }
        
        return dp[r][c1][c2] = mx;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, col - 1);
    }
};

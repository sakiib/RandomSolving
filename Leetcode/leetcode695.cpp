class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    int row, col;
    bool visited[55][55];
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        auto inside = [&](int nx, int ny) -> bool {
            return nx >= 0 && ny >= 0 && nx < row && ny < col;
        };
        
        visited[x][y] = true;
        
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (inside(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 1) {
                ret += 1 + dfs(grid, nx, ny);
            }
        }
        return ret;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        row = grid.size(), col = grid[0].size();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    mx = max(mx, 1 + dfs(grid, i, j));
                }
            }
        }
        return mx;
    }
};

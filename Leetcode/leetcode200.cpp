class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    bool visited[305][305];
    
    void dfs(int x, int y, vector<vector<char>>& grid) {
        visited[x][y] = true;
        
        auto inside = [&](int nx, int ny) -> bool {
            return nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size();
        };
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (inside(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(nx, ny, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        memset(visited, false, sizeof(visited));
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

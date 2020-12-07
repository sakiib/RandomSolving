class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    int startX, startY, endX, endY, pathLength, row, col;
    bool visited[25][25];
    
    inline bool insideGrid(int nx, int ny) {
        return nx >= 0 && ny >= 0 && nx < row && ny < col;
    }
    int numberOfPaths(int sx, int sy, int len, vector<vector<int>>& grid) {
        if (sx == endX && sy == endY && len == 0) {
            return 1;
        }
        int ways = 0;
        for (int i = 0; i < 4; i++) {
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if (insideGrid(nx, ny) && grid[nx][ny] != -1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                ways += numberOfPaths(nx, ny, len - 1, grid);
                visited[nx][ny] = false;
            }
        }
        return ways;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                } else if (grid[i][j] == 0) {
                    pathLength += 1;
                }
            }
        }
        memset(visited, false, sizeof(visited));
        visited[startX][startY] = true;
        return numberOfPaths(startX, startY, pathLength + 1, grid);
    } 
};

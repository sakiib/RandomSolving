class Solution {
public:
    const int dx[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    const int dy[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
    
    int cost[105][105];
    
    int bfs(vector <vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if (grid[0][0] == 1) return -1;
        
        memset(cost, -1, sizeof(cost));
        queue <pair <int, int> > q;
        
        q.push(make_pair(0, 0));
        cost[0][0] = 1;
        
        auto inside = [&](int nx, int ny) {
            return nx >= 0 && ny >= 0 && nx < row && ny < col;    
        };
        
        while (!q.empty()) {
            pair <int, int> f = q.front(); q.pop();
            int x = f.first, y = f.second;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!inside(nx, ny) || grid[nx][ny] == 1) continue;
                if (cost[nx][ny] == -1 || cost[nx][ny] > cost[x][y] + 1) {
                    cost[nx][ny] = cost[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        return cost[row - 1][col - 1];
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};

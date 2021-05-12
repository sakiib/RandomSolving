class Solution {
public:
    const int inf = 1e9;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    int cost[100][100];
    
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue <pair <int, int> > q;
        bool good = false;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    cost[i][j] = inf;
                    good = true;
                } 
                if (grid[i][j] == 2) {
                    cost[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        
        if (!good) return 0;
        
        auto inside = [&] (int nx, int ny) {
            return nx >= 0 && ny >= 0 && nx < row && ny < col;    
        };
        
        while (!q.empty()) {
            pair <int, int> f = q.front(); q.pop();
            int x = f.first, y = f.second;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!inside(nx, ny) || grid[nx][ny] == 0) continue;
                if (cost[nx][ny] == inf || cost[nx][ny] > cost[x][y] + 1) {
                    cost[nx][ny] = cost[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        int ans = -inf;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if (cost[i][j] == inf) return -1;
                    ans = max(ans, cost[i][j]);
                }
            }
        }
        
        return ans;
    }
};



// [2,1,1]
// [0,1,1]
// [1,0,1]

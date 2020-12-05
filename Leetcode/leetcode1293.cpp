class Solution {
public:
    const int inf = 1e9;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    int cost[40 + 1][40 + 1][40*40 + 1];
    
    struct node {
        int x, y, c;
        node(){}
        node(int x, int y, int c): x(x), y(y), c(c) {}
    };
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        assert((int)grid.size() > 0);
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int kk = 0; kk <= k; kk++) {
                    cost[i][j][kk] = inf;
                }
            }
        }
        queue <node> q;
        q.push(node(0, 0, 0));
    
        cost[0][0][0] = 0;
        while (!q.empty()) {
            node f = q.front(); q.pop();
            int x = f.x, y = f.y, c = f.c;
            for (int id = 0; id < 4; id++) {
                int nx = dx[id] + x, ny = dy[id] + y;
                if (!(nx >= 0 && ny >= 0 && nx < row && ny < col)) continue;
                int nc = c + (grid[nx][ny] == 1);
                if (cost[nx][ny][nc] > cost[x][y][c] + 1) {
                    cost[nx][ny][nc] = cost[x][y][c] + 1;
                    q.push(node(nx, ny, nc));
                }
            }
        }
        int ans = inf;
        for (int kk = 0; kk <= k; kk++) {
            ans = min(ans, cost[row - 1][col - 1][kk]);
        }
        return ans == inf ? -1 : ans;
    }
};

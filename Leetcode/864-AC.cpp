class Solution {
public:
    const int inf = 1e5;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    inline int  Set(int N , int pos) { 
        return N |= (1 << pos); 
    }
    
    inline bool Check(int N, int pos) { 
        return (bool)(N & (1 << pos));
    }
    
    int dp[31][31][(1 << 6) + 1][(1 << 6) + 1];
    
    struct data {
        int x, y, havemask, needmask;
        data(int x, int y, int havemask, int needmask): x(x), y(y), havemask(havemask), needmask(needmask) {}
    };
    
    bool insideGrid(int nx, int ny, int row, int col) {
        return (nx >= 0 && ny >= 0 && nx < row && ny < col);    
    }
    
    int findShortestPath(int startx, int starty, vector <string>& grid, int row, int col, int maze) {
        memset(dp, -1, sizeof(dp));
        
        queue <data> q;
        q.push(data(startx, starty, 0, 0));
        dp[startx][starty][0][0] = 0;
        
        while (!q.empty()) {
            data f = q.front(); q.pop();
            int x = f.x, y = f.y, havemask = f.havemask, needmask = f.needmask;
                                    
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!insideGrid(nx, ny, row, col) || grid[nx][ny] == '#') {
                    continue;
                }
                
                int chavemask = havemask, cneedmask = needmask;
                if (isalpha(grid[nx][ny]) && isupper(grid[nx][ny])) {
                    if (!Check(chavemask, grid[nx][ny] - 'A')) continue;
                    cneedmask = Set(cneedmask, grid[nx][ny] - 'A');
                }
                
                if (isalpha(grid[nx][ny]) && islower(grid[nx][ny])) {
                    chavemask = Set(chavemask, grid[nx][ny] - 'a');  
                }
                
                if (dp[nx][ny][chavemask][cneedmask] == -1) {
                    dp[nx][ny][chavemask][cneedmask] = dp[x][y][havemask][needmask] + 1;
                    q.push(data(nx, ny, chavemask, cneedmask));
                }
            }
        }
        
        int ans = inf;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < (1 << maze/2); k++) {
                    if (dp[i][j][(1 << maze/2) - 1][k] != -1) {
                        ans = min(ans, dp[i][j][(1 << maze/2) - 1][k]);
                    }
                }
            }
        }
        
        return ans == inf? -1: ans;
    }
    
    int shortestPathAllKeys(vector<string>& grid) {
        int startx = 0, starty = 0, maze = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isalpha(grid[i][j])) {
                    maze++;
                }  else if (grid[i][j] == '@') {
                    startx = i, starty = j;
                } 
            }
        }
        
        int ans = findShortestPath(startx, starty, grid, row, col, maze);
        return ans;
    }
};

// AC

// @.a.# 
// ###.# 
// b.A.B

class Solution {
public:
    const int inf = 1e5;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    pair <int, int> keys[10];
    pair <int, int> locks[10];
    int dp[35][35][35][35];
    
    bool insideGrid(int nx, int ny, int row, int col) {
        return (nx >= 0 && ny >= 0 && nx < row && ny < col);    
    }
    
    void findShortestPath(int x, int y, vector <string>& grid, int row, int col) {
        dp[x][y][x][y] = 0;
        queue <pair <int, int> > q;
        q.push(make_pair(x, y));
        
        while (!q.empty()) {
            pair <int, int> f = q.front(); q.pop();
            int px = f.first, py = f.second;
            for (int i = 0; i < 4; i++) {
                int nx = px + dx[i], ny = py + dy[i];
                if (!insideGrid(nx, ny, row, col) || grid[nx][ny] == '#') continue;
                if (dp[x][y][nx][ny] == -1 || dp[x][y][nx][ny] > dp[x][y][px][py] + 1) {
                    dp[x][y][nx][ny] = dp[x][y][px][py] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    int shortestPathAllKeys(vector<string>& grid) {
        int startx = 0, starty = 0, maze = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isalpha(grid[i][j]) && islower(grid[i][j])) {
                    keys[grid[i][j] - 'a'] = make_pair(i, j);
                    maze++;
                } else if (isalpha(grid[i][j]) && isupper(grid[i][j])) {
                    locks[grid[i][j] - 'A'] = make_pair(i, j);
                }  else if (grid[i][j] == '@') {
                    startx = i, starty = j;
                } 
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < row; k++) {
                    for (int l = 0; l < col; l++) {
                        dp[i][j][k][l] = -1; 
                    }
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != '#') {
                    findShortestPath(i, j, grid, row, col);
                }
            }
        }
        
        vector <int> permutations;
        for (int i = 0; i < maze; i++) permutations.push_back(i);
        
        int ans = inf;
        do {
            int cost = 0;
            for (int i = 0; i < permutations.size(); i++) {
                int idx = permutations[i];
                int fx = keys[idx].first, fy = keys[idx].second, tx = locks[idx].first, ty = locks[idx].second;
                if (i == 0) {
                    cost += dp[startx][starty][fx][fy];
                    cost += dp[fx][fy][tx][ty];
                } else {
                    cost += dp[fx][fy][tx][ty];
                }
            }
            ans = min(ans, cost);
        } while (next_permutation(permutations.begin(), permutations.end()));
        
        return ans;
    }
};

// WA - fix

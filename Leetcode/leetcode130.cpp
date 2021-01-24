class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        
        vector <vector <bool> > visited = vector <vector <bool> > (row, vector <bool> (col, false));
        
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (visited[i][j] || board[i][j] == 'X') continue;
                vector <pair <int,int> > pos;
                if (ok(i, j, row, col, visited, board, pos)) {
                    for (auto p: pos) {
                        assert(board[p.first][p.second] == 'O');
                        board[p.first][p.second] = 'X';
                    }
                }
            }
        }
        
        return;
    }
    
    bool ok(int x, int y, int row, int col, vector <vector <bool> >& visited, vector <vector <char> >& board, vector <pair <int,int> >& pos) {
        bool ret = true;
        pos.push_back(make_pair(x, y));
        visited[x][y] = true;
        
        if (x == 0 || x == row - 1 || y == 0 || y == col - 1) return false;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!(nx >= 0 && nx < row && ny >= 0 && ny < col)) return false;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] != 'O') continue;
            ret &= ok(nx, ny, row, col, visited, board, pos);
        }
        
        return ret;
    }
};

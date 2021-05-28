class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    bool solve(vector<vector<char>>& board, string word, int idx, int x, int y, int row, int col, vector<vector<bool>>& visited) {
        if (idx >= word.size()) return true;
        bool ret = false;
        auto inside = [&](int nx, int ny) {
            return (nx >= 0 && ny >= 0 && nx < row && ny < col);    
        };
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!inside(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == word[idx]) {
                visited[nx][ny] = true;
                ret |= solve(board, word, idx + 1, nx, ny, row, col, visited);
                visited[nx][ny] = false;
            }
        }
        
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        bool possible = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    vector <vector<bool>> visited(row, vector<bool>(col, false));
                    visited[i][j] = true;
                    possible |= solve(board, word, 1, i, j, row, col, visited);
                }
            }
        }
        return possible;
    }
};

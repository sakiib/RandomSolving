class Solution {
public:
    char s[5][5];
    bool win(int id) {
        if (id == 1) {
            if (s[0][0] == 'X' && s[0][1] == 'X' && s[0][2] == 'X') return true;
            if (s[1][0] == 'X' && s[1][1] == 'X' && s[1][2] == 'X') return true;
            if (s[2][0] == 'X' && s[2][1] == 'X' && s[2][2] == 'X') return true;

            if (s[0][0] == 'X' && s[1][0] == 'X' && s[2][0] == 'X') return true;
            if (s[0][1] == 'X' && s[1][1] == 'X' && s[2][1] == 'X') return true;
            if (s[0][2] == 'X' && s[1][2] == 'X' && s[2][2] == 'X') return true;

            if (s[0][0] == 'X' && s[1][1] == 'X' && s[2][2] == 'X') return true;
            if (s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X') return true;
            return false;
        }
        else {
            if (s[0][0] == 'O' && s[0][1] == 'O' && s[0][2] == 'O') return true;
            if (s[1][0] == 'O' && s[1][1] == 'O' && s[1][2] == 'O') return true;
            if (s[2][0] == 'O' && s[2][1] == 'O' && s[2][2] == 'O') return true;

            if (s[0][0] == 'O' && s[1][0] == 'O' && s[2][0] == 'O') return true;
            if (s[0][1] == 'O' && s[1][1] == 'O' && s[2][1] == 'O') return true;
            if (s[0][2] == 'O' && s[1][2] == 'O' && s[2][2] == 'O') return true;

            if (s[0][0] == 'O' && s[1][1] == 'O' && s[2][2] == 'O') return true;
            if (s[0][2] == 'O' && s[1][1] == 'O' && s[2][0] == 'O') return true;
            return false;
        }
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                s[i][j] = '-';
            }
        }
        for (int i = 0; i < moves.size(); i++) {
            vector <int> cur = moves[i];
            int x = cur[0], y = cur[1];
            if (i%2 == 0) {
                s[cur[0]][cur[1]] = 'X';
                if (win(1)) return "A";
            }
            else {
                s[cur[0]][cur[1]] = 'O';
                if (win(2)) return "B";
            }
        }
        if (moves.size() < 9) return "Pending";
        else return "Draw";
    }
};

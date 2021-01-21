class Solution {
public:
    const int INF = 1e9;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return vector <vector <int> > {};
        }
        
        int col =  matrix[0].size();
        
        queue <pair <int,int> > q;
        vector <vector <int> > distance = vector <vector <int> > (row, vector <int> (col, 0));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    q.push(make_pair(i, j));
                } else {
                    distance[i][j] = INF;
                }
            }
        }
        
        bfs(row, col, matrix, q, distance);
        return distance;
    }
    
    void bfs(int row, int col, vector <vector <int> >& matrix, queue <pair <int,int> >& q, vector <vector <int> >& distance) {
        while (!q.empty()) {
            pair <int,int> f = q.front(); q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = f.first + dx[i], ny = f.second + dy[i];
                if (!(nx >= 0 && nx < row && ny >= 0 && ny < col)) continue;
                if (distance[nx][ny] == INF || distance[nx][ny] > distance[f.first][f.second] + 1) {
                    distance[nx][ny] = distance[f.first][f.second] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
};

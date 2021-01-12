class Solution {
public:
	const int inf = 1e9;
	const int dx[4] = {0, 0, 1, -1};
	const int dy[4] = {1, -1, 0, 0};
	
	int minCost (vector <vector <int> >& matrix) {
		int row = matrix.size(), col = matrix[0].size();
		vector <vector <int> > cost = vector <vector <int> > (row + 1, vector <int> (col + 1, inf));
		
		auto inside = [&](int nx, int ny) -> bool {
			return nx >= 0 && nx < row && ny >= 0 && ny < col;
		};
		
		// cost[i][j] = minimum cost of reaching cell (i, j)
		cost[0][0] = 0;
		
		queue <pair <int,int> > q;
		q.push(make_pair(0, 0));
		
		while (!q.empty()) {
			pair <int,int> f = q.front(); q.pop();
			int x = f.first, y = f.second;
			
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				
				if (!inside(nx, ny)) continue;
				
				int add = (matrix[x][y] != i + 1);
				
				if (cost[nx][ny] == inf || cost[nx][ny] > cost[x][y] + add) {
					cost[nx][ny] = cost[x][y] + add;
					q.push(make_pair(nx, ny));
				}
			}
		}
		
		return cost[row - 1][col - 1];
	}	
};

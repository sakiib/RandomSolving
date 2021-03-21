#include <bits/stdc++.h>
using namespace std;

struct cell {
	int x, y, val;
	cell(): x(0), y(0), val(0) {}
	cell(int x, int y, int val): x(x), y(y), val(val) {}

	bool operator <(const cell &other) const {
		return val < other.val;
	}
};

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int row, col;
		cin >> row >> col;
		vector <vector <int> > grid = vector <vector <int> > (row + 1, vector <int> (col + 1));

		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				cin >> grid[i][j];
			}
		}

		priority_queue <cell> q;
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				q.push(cell(i, j, grid[i][j]));
			}
		}

		vector <vector <int> > visited = vector <vector <int> > (row + 1, vector <int> (col + 1));
		long long ans = 0;

		while (!q.empty()) {
			cell tp = q.top(); q.pop();
			int x = tp.x, y = tp.y, val = tp.val;

			if (visited[x][y]) continue;
			visited[x][y] = true;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!(nx >= 1 && ny >= 1 && nx <= row && ny <= col)) continue;

				if (val - grid[nx][ny] > 1) {
					ans += val - grid[nx][ny] - 1;
					grid[nx][ny] = val - 1;
					q.push(cell(nx, ny, grid[nx][ny]));
				}
			}
		}

		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}

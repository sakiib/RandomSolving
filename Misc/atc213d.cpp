#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector <int> graph[N];

void dfs(int s, int p) {
	cout << s << " ";
	for (auto val: graph[s]) {
		if (val != p) {
			dfs(val, s);
			cout << s << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(1, 0);
	return 0;
}

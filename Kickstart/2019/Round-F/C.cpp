#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e15;

int n;
long long val[N], dp[N][3], subdp[N][3];
vector <int> graph[N];

void dfs(int s, int p) {
  vector <int> childern;
  for (auto nxt: graph[s]) {
    if (nxt != p) {
      dfs(nxt, s);
      childern.push_back(nxt);
    }
  }

  dp[s][0] = -INF, dp[s][1] = -INF, dp[s][2] = -INF;
  // i. don't lit this node at all - 0
  // add value = max(child not lit, child lit indirectly)
  long long res = 0;
  for (auto ch: childern) {
    res += max(dp[ch][0], dp[ch][1]);
  }
  dp[s][0] = res;

  // ii. lit this node directly - 2
  // add value = max(child not lit before but now lit, lit indirectly, lit directly)
  res = val[s];
  for (auto ch: childern) {
    res += max(dp[ch][0] + val[ch], max(dp[ch][1], dp[ch][2]));
  }
  dp[s][2] = res;

  // iii. lit this node from it's child - 1
  // sub-dp problem here: which set of children will result in max value
  for (int i = 0; i < childern.size(); i++) {
    for (int j = 0; j < 2; j++) {
      subdp[i][j] = -INF;
    }
  }

  for (int i = 0; i < childern.size(); i++) {
    // implement me...
  }
}

long long solve() {
  dfs(1, 0);
  return max(dp[1][0], max(dp[1][1], dp[1][2]));
}

int main() {
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> val[i];
    }

    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    solve();
    cout << "Case #" << tc << ": " << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/000000000018666b

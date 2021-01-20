#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, a[N], b[N];
vector <int> graph[N];
int matched[N];
bool visited[N];

bool findMatch(int s) {
    visited[s] = true;
    for (int i = 0; i < graph[s].size(); i++) {
        int node = graph[s][i];
        int next = matched[node];
        if (visited[next]) continue;
        if (next == -1 || findMatch(next)) {
            matched[node] = s;
            return true;
        }
    }
    return false;
}

int kuhn() {
    int mx_matching = 0;
    memset(matched, -1, sizeof(matched));
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        if (findMatch(i)) mx_matching++;
    }
    return mx_matching;
}

int main() {
    int t;
    scanf("%d", & t);
    for (int tc = 1; tc <= t; tc++) {
        for (int i = 1; i < N; i++) graph[i].clear();
        scanf("%d", & n);
        for (int i = 1; i <= n; i++) scanf("%d", & a[i]);
        scanf("%d", & m);
        for (int i = 1; i <= m; i++) scanf("%d", & b[i]);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (b[j] % a[i] == 0) graph[i].push_back(j);
            }
        }
        
        int mxMatching = kuhn();
        printf("Case %d: %d\n", tc, mxMatching);
    }
    return 0;
}

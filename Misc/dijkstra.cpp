#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;
typedef pair <int,int> pii;

vector <pii> graph[N];

vector <int> dijkstra(int s) {
    priority_queue <pii, vector<pii>, greater<pii>> q;
    vector <int> dist(N + 1, inf);
    vector <bool> relaxed(N + 1, false);
    q.push(make_pair(0, s));
    dist[s] = 0;
    while (!q.empty()){
        pii x = q.top(); q.pop();
        int u = x.second;
        if (relaxed[u]) continue; relaxed[u] = true;
        for (auto cur: graph[u]){
            int v = cur.first; int w = cur.second;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w; q.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define SZ(v) (int)v.size()
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 1e9;
const LL INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int cost[100][100];
int ID[10][10];

void fw() {
    int id = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) ID[i][j] = ++id;
    }

    for (int i = 1; i <= id; i++) {
        for (int j = 1; j <= id; j++) cost[i][j] = inf; cost[i][i] = 0;
    }

    auto inside = [&](int nx, int ny) {
        return nx >= 0 && nx < 8 && ny >= 0 && ny < 8;
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (!inside(nx, ny)) continue;
                cost[ID[i][j]][ID[nx][ny]] = min(cost[ID[i][j]][ID[nx][ny]], nx * i + ny * j);
            }
        }
    }

    for (int k = 1; k <= id; k++) {
        for (int i = 1; i <= id; i++) {
            for (int j = 1; j <= id; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

void solve() {
    fw();
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        cout << cost[ID[a][b]][ID[c][d]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1;

    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}

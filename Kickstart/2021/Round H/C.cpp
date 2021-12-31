#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int a[N], nxt[N], prv[N];
vector <int> who[10];
bool bad[N];

inline bool good(int x, int y) {
  return (x + 1) % 10 == y;
}

void reset() {
  memset(bad, false, sizeof(bad));

  for (int i = 0; i < 10; i++) {
    who[i].clear();
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int len;
    cin >> len;
    string s;
    cin >> s;
    for (int i = 0; i < len; i++) {
      a[i + 1] = (s[i] - '0');
    }

    reset();

    for (int i = 1; i <= len; i++) {
      nxt[i] = i + 1;
      prv[i] = i - 1;
    }

    for (int i = 1; i < len; i++) {
      if (good(a[i], a[i + 1])) {
        who[a[i]].push_back(i);
      }
    }

    while (true) {
      bool change = false;
      for (int i = 0; i < 10; i++) {
        if (!who[i].empty()) {
          change = true;
        }
        for (int idx: who[i]) {
          if (a[idx] != i || bad[idx] || nxt[idx] > len || !good(a[idx], a[nxt[idx]])) {
            continue;
          }

          // discard the nxt index
          bad[nxt[idx]] = true;
          // update the replaced value at current index
          a[idx] = (i + 2) % 10;

          // update the nxt pointer
          nxt[idx] = nxt[nxt[idx]];
          // update the previous pointer
          if (nxt[idx] <= len) {
            prv[nxt[idx]] = idx;
          }

          // check if any new valid pair is formed, push indexes if any
          if (prv[idx] >= 1 && good(a[prv[idx]], a[idx])) {
            who[a[prv[idx]]].push_back(prv[idx]);
          }
          if (nxt[idx] <= len && good(a[idx], a[nxt[idx]])) {
            who[a[idx]].push_back(idx);
          }
        }
        who[i].clear();
      }
      if (!change) {
        break;
      }
    }

    cout << "Case #" << tc << ": ";
    for (int i = 1; i <= len; i = nxt[i]) {
      if (!bad[i]) {
        cout << a[i];
      }
    }

    cout << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d94f5

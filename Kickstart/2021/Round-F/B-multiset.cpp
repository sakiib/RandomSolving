#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
vector <pair <long long, long long> > intervals[N];

void reset() {
  for (int i = 1; i < N; i++) {
    intervals[i].clear();
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int d, n, k;
    cin >> d >> n >> k;

    reset();

    for (int i = 1; i <= n; i++) {
      int val, l, r;
      cin >> val >> l >> r;
      intervals[l].push_back(make_pair(val, i));
      intervals[r + 1].push_back(make_pair(val, -i));
    }

    long long ans = 0, cur = 0;
    multiset <pair <long long, long long> > best;
    multiset <pair <long long, long long> > rest;
    for (int i = 1; i <= d; i++) {
      for (auto [val, id]: intervals[i]) {
        if (id > 0) {
          if ((int)best.size() < k) {
            best.insert({val, id});
            cur += val;
          } else {
            auto smallest = best.begin();
            if ((*smallest).first > val) {
              rest.insert({val, id});
            } else {
              best.erase({(*smallest).first, (*smallest).second});
              cur -= (*smallest).first;

              rest.insert({{(*smallest).first, (*smallest).second}});

              best.insert({val, id});
              cur += val;
            }
          }
        } else {
          if (rest.find({val, - id}) != rest.end()) {
            rest.erase({val, - id});
          } else {
            if (best.find({val, - id}) != best.end()) {
              best.erase({val, - id});
              cur -= val;
            }

            if ((int)rest.size() > 0) {
              auto biggest = rest.rbegin();

              best.insert({(*biggest).first, (*biggest).second});
              cur += (*biggest).first;

              rest.erase({(*biggest).first, (*biggest).second});
            }
          }
        }
        ans = max(ans, cur);
      }
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000887dba

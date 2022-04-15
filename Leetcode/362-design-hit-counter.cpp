#include <bits/stdc++.h>
using namespace std;

// approach: 1
queue <int> q;

void hit(int t) {
  while (!q.empty() && t - q.front() >= 300) {
    q.pop();
  }
  q.push(t);
}

int getHits(int t) {
  while (!q.empty() && t - q.front() >= 300) {
    q.pop();
  }

  return q.size();
}

// approach: 2
// timestamp, counter
int total;
queue <pair <int, int> > q;

void hit(int t) {
  if (q.empty() || q.front().first < t) {
    q.push({t, 1});
  } else {
    q.front().second++;
  }

  total++;
  while (!q.empty() && t - q.front().first >= 300) {
    total -= q.front().second;
    q.pop();
  }
}

int getHits(int t) {
  while (!q.empty() && t - q.front().first >= 300) {
    total -= q.front().second;
    q.pop();
  }

  return total;
}

int main() {
  // hit at timestamp 1.
  hit(1);
  // hit at timestamp 2.
  hit(2);
  // hit at timestamp 3.
  hit(3);
  // get hits at timestamp 4, should return 3.
  cout << getHits(4) << endl;
  // hit at timestamp 300.
  hit(300);
  // get hits at timestamp 300, should return 4.
  cout << getHits(300) << endl;
  // get hits at timestamp 301, should return 3.
  cout << getHits(301) << endl;
  return 0;
}

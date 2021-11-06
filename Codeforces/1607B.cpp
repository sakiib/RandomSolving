#include <bits/stdc++.h>
using namespace std;

void solveEven(long long x, long long n) {
  if (n % 4 == 1) {
    cout << x - n << "\n";
  } else if (n % 4 == 2) {
    cout << x + 1 << "\n";
  } else if (n % 4 == 3) {
    cout << x + n + 1 << "\n";
  } else {
    cout << x << "\n";
  }
}

void solveOdd(long long x, long long n) {
  if (n % 4 == 1) {
    cout << x + n << "\n";
  } else if (n % 4 == 2) {
    cout << x - 1 << "\n";
  } else if (n % 4 == 3) {
    cout << x - (n + 1) << "\n";
  } else {
    cout << x << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;

    if (abs(x) % 2 == 0) {
      solveEven(x, n);
    } else {
      solveOdd(x, n);
    }
  }
  return 0;
}

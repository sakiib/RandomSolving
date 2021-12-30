#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct MillerRabinPrimalityCheck {
  #define ran(a, b) rng() % ((b) - (a) + 1) + (a)
  typedef long long LL;

  inline LL mulMod(LL a, LL b, LL c) {
    LL x = 0, y = a % c;
    while (b > 0) {
      if (b & 1) x = (x + y) % c;
      y = (y << 1) % c;
      b = (b >> 1);
    }
    return x;
  }

  inline LL modulo(LL a, LL b, LL c) {
    LL x = 1, y = a % c;
    while (b > 0) {
      if (b & 1) x = mulMod(x, y, c);
      y = mulMod(y, y, c);
      b = (b >> 1);
    }
    return x;
  }

  inline bool millerRabin(LL p, int iter = 5) {
    if (p == 2) {
        return true;
    }
    if (p < 2 || !(p & 1)) {
        return false;
    }

    LL s = p - 1, a, temp, mod;
    while (!(s & 1)) {
      s = (s >> 1);
    }

    for (int i = 0; i < iter; i++) {
      a = ran(2, p - 1);
      temp = s;
      mod = modulo(a, temp, p);
      while (temp != (p - 1) && mod != 1 && mod != (p - 1)) {
        mod = mulMod(mod, mod, p);
        temp = (temp << 1);
      }
      if (mod != (p - 1) && !(temp & 1)) {
        return false;
      }
    }
    return true;
  }

  inline bool isPrime(LL n) {
    return millerRabin(n, 5);
  }
} M;

typedef long long LL;

#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())

LL SQRT(LL n) {
  LL lo = 1, hi = 1e9, ret = 1;
  while (lo <= hi) {
    LL mid = (lo + hi) >> 1;
    if (mid * mid <= n) {
      ret = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return ret;
}

LL solve(LL n) {
  LL sq = SQRT(n);

  vector <LL> v;
  for (LL i = sq; i <= n && (int)v.size() <= 3; i++) {
    if (M.isPrime(i)) {
      v.push_back(i);
    }
  }
  for (LL i = sq - 1; i >= 2 && (int)v.size() <= 6; i--) {
    if (M.isPrime(i)) {
      v.push_back(i);
    }
  }

  Unique(v);

  LL ans = 0;
  for (int i = 1; i < (int)v.size(); i++) {
    if (v[i] * v[i - 1] <= n) {
      ans = max(ans, v[i] * v[i - 1]);
    }
  }

  return ans;
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    LL n;
    cin >> n;
    cout << "Case #" << tc << ": " << solve(n) << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a8e6

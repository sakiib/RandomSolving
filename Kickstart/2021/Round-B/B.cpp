#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int a[N];

vector <int> calcPrefix(int n) {
  // prefix[i] = longest arithmetic progression from prefix ending at position i without any changes
  vector <int> prefix (n + 1, 0);

  for (int i = 1; i <= n; i++) {
    // for length <= 2, we can make arithmetic progression with this length
    if (i <= 2) {
      prefix[i] = i;
      continue;
    }

    // if common difference is same, extend with the prefix or put default value which is 2
    if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
      prefix[i] = prefix[i - 1] + 1;
    } else {
      prefix[i] = 2;
    }
  }

  return prefix;
}

vector <int> calcSuffix(int n) {
  // suffix[i] = longest arithmetic progression from suffix ending at position i without any changes
  vector <int> suffix (n + 1, 0);

  for (int i = n; i >= 1; i--) {
    // for length <= 2, we can make arithmetic progression with this length
    if (i >= n - 1) {
      suffix[i] = n - i + 1;
      continue;
    }

    // if common difference is same, extend with the prefix or put default value which is 2
    if (a[i] - a[i + 1] == a[i + 1] - a[i + 2]) {
      suffix[i] = suffix[i + 1] + 1;
    } else {
      suffix[i] = 2;
    }
  }

  return suffix;
}

int solve(int n) {
  // for size n <= 3, we can always make this an arithmetic progression with atmost 1 changes
  if (n <= 3) {
    return n;
  }

  vector <int> prefix = calcPrefix(n);
  vector <int> suffix = calcSuffix(n);

  // first value can be extended with suffix[2], last value can be extended with prefix[n -1]
  int ans = max(suffix[2], prefix[n - 1]) + 1;

  for (int i = 2; i <= n - 1; i++) {
    // max value from suffix or prefix without making any changes
    ans = max(ans, suffix[i + 1] + 1);
    ans = max(ans, prefix[i - 1] + 1);

    // want to change the i'th value to merge it from both the suffix & the prefix
    // difference of a[i + 1] - a[i - 1] must be even to split it by exactly half
    if ((a[i + 1] - a[i - 1])&1) {
      continue;
    }

    // common difference
    int k = (a[i + 1] - a[i - 1]) / 2;
    // i. we have 2 or more value on both end, find their commond difference & see if we can merge them
    // ii. we're at the 2nd index, so no common difference on the prefix
    // iii. we're at the second last index, so no commond difference on the suffix
    if (i + 2 <= n && i - 2 >= 1) {
      int d1 = a[i - 1] - a[i - 2];
      int d2 = a[i + 2] - a[i + 1];
      // i. we can merge both chunk
      // ii. we can merge only with the left chunk
      // iii. we can merge only with the right chunk
      if (d1 == d2 && d1 == k) {
        ans = max(ans, prefix[i - 1] + 1 + suffix[i + 1]);
      } else if (k == d1) {
        ans = max(ans, prefix[i - 1] + 2);
      } else if (k == d2) {
        ans = max(ans, suffix[i + 1] + 2);
      }
    } else if (i + 2 <= n) {
      int d2 = a[i + 2] - a[i + 1];
      if (k == d2) {
        ans = max(ans, prefix[i - 1] + 1 + suffix[i + 1]);
      }
    } else if (i - 2 >= 1) {
      int d1 = a[i - 1] - a[i - 2];
      if (k == d1) {
        ans = max(ans, prefix[i - 1] + 1 + suffix[i + 1]);
      }
    }
  }

  return ans;
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    cout << "Case #" << tc << ": " << solve(n) << "\n";
  }
  return 0;
}

// Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a3a5 

#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

vector <int> prime;
vector <bool> isprime(N, true);

void sieve() {
    isprime[0] = isprime[1] = false;
    prime.push_back(2);
    for (int i = 4; i <= N; i += 2) isprime[i] = false;
    int sq = sqrt(N);
    for (int i = 3; i <= sq; i += 2) {
        if (isprime[i]) {
            for (int j = i * i; j <= N; j += 2 * i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 3; i <= N; i += 2) {
        if (isprime[i]) prime.push_back(i);
    }
}

void solve() {
    vector <int> ans(N, 0);
    for (int i = 0; i < prime.size() && prime[i] <= 1e6; i++) {
        if (2 + prime[i] <= 1e6 && isprime[2 + prime[i]]) {
            ans[2 + prime[i]]++;
        }
    }
    for (int i = 1; i < N; i++) {
        ans[i] += ans[i - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    solve();
    return 0;
}

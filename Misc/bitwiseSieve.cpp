#include <bits/stdc++.h>
using namespace std;

vector <int> primes;
const int N = 1e6;

inline bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

inline int Set(int N, int pos) {
    return N = N | (1 << pos);
}

int status[(N / 32) + 2];

void sieve() {
    int sqrtN = sqrt(N);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (Check(status[i >> 5], (i & 31)) == 0) {
            for (int j = i * i; j <= N; j += (i << 1)) {
                status[j >> 5] = Set(status[j >> 5], (j & 31));
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2) {
        if (Check(status[i >> 5], (i & 31)) == 0) primes.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    return 0;
}

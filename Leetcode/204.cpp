class Solution {
public:
    static const int N = 5e6;
    vector <int> prime;
    bool isprime[N + 5];
    
    void sieve( ) {
            memset(isprime, true, sizeof(isprime));
            isprime[0] = isprime[1] = false;
            prime.push_back( 2 );
            for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
            int sq = sqrt(N);
            for( int i = 3; i <= sq; i += 2 ) {
                    if( isprime[i] ) {
                            for( int j = i*i; j <= N; j += 2*i ) {
                                    isprime[j] = false;
                            }
                    }
            }
            for( int i = 3; i <= N; i += 2 ) {
                    if( isprime[i] ) prime.push_back( i );
            }
    }
    
    int countPrimes(int n) {
        int ans = 0;
        sieve();
        for (auto p: prime) {
            if (p < n) ans++;
        }
        return ans;
    }
};

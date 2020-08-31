class Solution {
public:
    bool divisorGame(int N) {
        vector <int> d[ 1005 ];
        for( int i = 1; i <= N; i++ ) {
            for( int j = 2 * i; j <= N; j += i) {
                d[j].push_back( i );
            }
        }
        int dp[ 1005 ];
        memset( dp , 0 , sizeof( dp ) );
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for( int i = 3; i <= N; i++ ) {
            for( auto x : d[i] ) {
                if( dp[i - x] == 0 ) dp[i] = 1;
            }
        }
        if( dp[N] ) return true;
        else return false;
    }
};

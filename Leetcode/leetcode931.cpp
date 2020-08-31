class Solution {
public:
    static const int inf = 1e9;
    int minFallingPathSum(vector<vector<int>>& A) {
        int a[ 105 ][ 105 ];
        int dp[ 105 ][ 105 ];
        int r = A.size() , c = A[0].size();
        for( int i = 0; i < A.size(); i++ ) {
            for( int j = 0; j < A[i].size(); j++ ) {
                a[i + 1][j + 1] = A[i][j];
            }
        }
        int mn = inf;
        for( int i = 0; i <= r + 1; i++ ) {
            for( int j = 0; j <= c + 1; j++ ) {
                dp[i][j] = inf;
            }
        }
        for( int i = 1; i <= c; i++ ) dp[1][i] = a[1][i];
        for( int i = 2; i <= r; i++ ) {
            for( int j = 1; j <= c; j++ ) {
                dp[i][j] = min( dp[i - 1][j], min( dp[i - 1][j - 1], dp[i - 1][j + 1] ) ) + a[i][j];
            }
        }
        for( int i = 1; i <= c; i++ ) mn = min( mn , dp[r][i] );
        return mn;
    }
};

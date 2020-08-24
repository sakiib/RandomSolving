class Solution {
public:
    map <string,bool> have;
    int dp[ 100005 ];
    int l;
    string ss;

    int solve( int idx ) {
        if( idx >= l ) return 1;
        if( dp[idx] != -1 ) return dp[idx];
        string cur = "";
        int ret = 0;
        for( int i = idx; i < l; i++ ) {
            cur += ss[i];
            if( have[cur] ) ret |= solve( i + 1 );
        }
        return dp[idx] = ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for( auto x : wordDict ) have[x] = true;
        ss = s;
        l = s.size();
        memset( dp , -1 , sizeof( dp ) );
        int ok = solve( 0 );
        if( ok ) return true;
        else return false;
    }
};

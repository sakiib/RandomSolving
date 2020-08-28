class Solution {
public:
    int sum[ 100005 ][ 50 ];

    int getval( int l , int r , int id ) {
        return l == 0 ? sum[r][id] : sum[r][id] - sum[l - 1][id];
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector <bool> ans;
        for( int i = 0; i < s.size(); i++ ) {
            for( char j = 'a'; j <= 'z'; j++ ) {
                sum[i][j - 'a'] = ( s[i] == j ? 1 : 0 );
                if( i ) sum[i][j - 'a'] += sum[i - 1][j - 'a'];
            }
        }
        for( auto x : queries ) {
            int l = x[0] , r = x[1] , k = x[2];
            int odd = 0;
            for( char i = 'a'; i <= 'z'; i++ ) {
                if( getval( l , r , i - 'a' )%2 ) odd++;
            }
            if( (r - l + 1)%2 == 0 ) {
                if( odd <= 2 * k ) ans.push_back( true );
                else ans.push_back( false );
            }
            else {
                if( odd - 1 <= 2 * k ) ans.push_back( true );
                else ans.push_back( false );
            }
        }
        return ans;
    }
};

class Solution {

struct data{
    int l , r , len;
    data() {}
    data( int l , int r , int len ) : l(l) , r(r) , len(len) {}
};

public:
    int maxRepOpt1(string text) {
        vector <data> V[ 30 ];
        for( int i = 0; i < text.size(); ) {
            int j = i;
            while( j < text.size() && text[j] == text[i] ) j++;
            V[ text[i] - 'a' + 1 ].push_back( data( i , j - 1 , j - i ) );
            i = j;
        }
        int mx = 1;
        for( int d = 1; d <= 26; d++ ) {
            vector <data> cur = V[d];
            if( cur.size() == 0 ) continue;
            if( cur.size() == 1 ) {
                mx = max( mx , cur[0].len );
                continue;
            }
            for( int i = 0; i < cur.size(); i++ ) {
                mx = max( mx , cur[i].len + 1 );
            }
            for( int i = 0; i < cur.size() - 1; i++ ) {
                if( cur[i].r + 2 == cur[i+1].l ) {
                    if( cur.size() > 2 ) mx = max( mx , cur[i].len + 1 + cur[i+1].len );
                    else mx = max( mx , cur[i].len + cur[i+1].len );
                }
            }
        }
        return mx;
    }
};

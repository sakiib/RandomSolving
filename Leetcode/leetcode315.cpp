class Solution {
public:
    vector <int> a;
    vector <int> tree[4*100000 + 5];
    void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
            tree[node].push_back( a[b] );
            return;
        }
        int l = node << 1 , r = l|1 , m = ( b + e )>>1;
        build( l , b , m );
        build( r, m + 1 , e );
        merge( tree[l].begin() , tree[l].end() , tree[r].begin() ,
                tree[r].end() ,back_inserter(tree[node]));
    }
    int query( int node , int b , int e , int i , int j , int key ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return lower_bound(tree[node].begin(), tree[node].end(), key) - tree[node].begin();
        int l = node << 1 , r = l|1 , m = ( b + e )>>1;
        return query( l , b , m , i , j , key ) + query( r , m + 1 , e , i , j , key );
    }
    vector<int> countSmaller(vector<int>& nums) {
        a.push_back( 0 );
        for( auto x : nums ) a.push_back( x );
        int n = a.size() - 1;
        build(1 , 1 , n );
        vector <int> ans;
        for( int i = 1; i < a.size(); i++ ) {
            ans.push_back( query( 1 ,1 , n , i + 1 , n , a[i] ) );
        }
        return ans;
    }
};

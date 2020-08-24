class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> Q;
        if( stones.size() == 0 ) return 0;
        for( auto x : stones ) Q.push( x );
        while( Q.size() >= 2 ) {
            int x = Q.top(); Q.pop();
            int y = Q.top(); Q.pop();
            if( x != y ) Q.push( abs( x - y ) );
        }
        if( Q.size() == 0 ) return 0;
        else return Q.top();
    }
};

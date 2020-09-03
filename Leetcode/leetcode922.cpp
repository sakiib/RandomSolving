class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        queue <int> O , E;
        for( auto x : A ) {
            if( x%2 == 0 ) E.push( x );
            else O.push( x );
        }
        vector <int> ans;
        for( int i = 0; i < A.size(); i++ ) {
            if( i%2 == 0 ) {
                ans.push_back( E.front() );
                E.pop();
            }
            else {
                ans.push_back( O.front() );
                O.pop();
            }
        }
        return ans;
    }
};

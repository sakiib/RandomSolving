class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int,int> cnt;
        for( auto x : nums ) cnt[x]++;
        vector < pair <int,int> > V;
        for( auto x : cnt ) V.push_back( make_pair( x.second, x.first ) );
        sort( V.rbegin(), V.rend() );
        vector <int> ret;
        for( int i = 0; i < k; i++ ) ret.push_back( V[i].second );
        return ret;
    }
};

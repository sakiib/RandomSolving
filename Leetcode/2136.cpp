class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector <pair <int, int> > v;
        for (int i = 0; i < plantTime.size(); i++) {
            v.push_back({growTime[i], plantTime[i]});
        }
        
        // plant first which takes longer to grow
        auto comp = [&](pair <int, int> a, pair <int, int> b) {
            return a.first > b.first;    
        };
        
        sort(v.begin(), v.end(), comp);
        
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < v.size(); i++) {
            ans = max(ans, cur + v[i].second + v[i].first);
            cur += v[i].second;
        }
        
        return ans;
    }
};

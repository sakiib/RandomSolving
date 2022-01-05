class Solution {
public:
    typedef pair <int, int> T;
    int candy(vector<int>& ratings) {
        priority_queue <T, vector <T>, greater<T> > q;
        for (int i = 0; i < (int)ratings.size(); i++) {
            q.push({ratings[i], i});
        }
        
        vector <int> candies ((int)ratings.size(), 1);
        while (!q.empty()) {
            T tp = q.top(); q.pop();
            int rating = tp.first, idx = tp.second;
            
            if (idx - 1 >= 0 && rating > ratings[idx - 1]) {
                candies[idx] = max(candies[idx], candies[idx - 1] + 1);
            }
            if (idx + 1 < (int)ratings.size() && rating > ratings[idx + 1]) {
                candies[idx] = max(candies[idx], candies[idx + 1] + 1);
            }
        }
        
        int ans = 0;
        for (int i  = 0; i < (int)candies.size(); i++) {
            ans += candies[i];
        }
        
        return ans;
    }
};

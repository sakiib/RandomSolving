class Solution {
public:
    typedef pair <int, int> T;
    int candy(vector<int>& ratings) {
        vector <int> candies ((int)ratings.size(), 1);
      
        for (int i = 0; i < ratings.size(); i++) {
            if (i - 1 >= 0 && ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        for (int i = (int)ratings.size() - 1; i >= 0; i--) {
            if (i + 1 < (int)ratings.size() && ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < (int)candies.size(); i++) {
            ans += candies[i];
        }
        
        return ans;
    }
};

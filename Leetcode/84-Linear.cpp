class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector <int> v;
        vector <int> can ((int)heights.size(), 0);
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (v.size() > 0 && heights[v.back()] >= heights[i]) v.pop_back();
            can[i] = (v.size() == 0? heights.size() - i: v.back() - i);
            v.push_back(i);
        }
        
        v.clear();
        
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (v.size() > 0 && heights[v.back()] >= heights[i]) v.pop_back();
            ans = max(ans, heights[i] * (can[i] + (v.size() == 0? i + 1: i - v.back()) - 1));
            v.push_back(i);
        }
        
        return ans;
    }
};



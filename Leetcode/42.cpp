class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector <int> left_max(n, 0);
        vector <int> right_max(n, 0);
        
        int h = 0;
        for (int i = 0; i < n; i++) {
            left_max[i] = h;
            h = max(h, height[i]);
        }
        
        h = 0;
        for (int i = n - 1; i >= 0; i--) {
            right_max[i] = h;
            h = max(h, height[i]);
        }
        
        int water = 0;
        for (int i = 0; i < n; i++) {
            // water level = min(left_max[i], right_max[i]);
            // stored water by (above) this block: max(0, water level - height[i])
            water += max(0, min(left_max[i], right_max[i]) - height[i]);
        }
        
        return water;
    }
};

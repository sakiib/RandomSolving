class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if (N == 0) {
            return 0;
        }
        
        vector <int> mxLeft (N, 0);
        for (int i = 0; i < N; i++) {
            mxLeft[i] = height[i];
            if (i - 1 >= 0) {
                mxLeft[i] = max(mxLeft[i - 1], mxLeft[i]);
            }
        }
        
        vector <int> mxRight (N, 0);
        for (int i = N - 1; i >= 0; i--) {
            mxRight[i] = height[i];
            if (i + 1 < N) {
                mxRight[i] = max(mxRight[i + 1], mxRight[i]);
            }
        }
        
        int ans = 0;
        for (int i = 1; i < N - 1; i++) {
            ans += max(0, min(mxLeft[i], mxRight[i]) - height[i]);
        }
        
        return ans;
    }
};

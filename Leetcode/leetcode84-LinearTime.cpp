class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        vector <int> leftIndex (N, -1);
        vector <int> rightIndex (N, N);
        
        for (int i = 0; i < N; i++) {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) {
                j = leftIndex[j];
            }
            leftIndex[i] = j;
        }
        
        for (int i = N - 1; i >= 0; i--) {
            int j = i + 1;
            while (j < N && heights[j] >= heights[i]) {
                j = rightIndex[j];
            }
            rightIndex[i] = j;
        }
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, heights[i] * (rightIndex[i] - leftIndex[i] - 1));
        }
        
        return ans;
    }
};

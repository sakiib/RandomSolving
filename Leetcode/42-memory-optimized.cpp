class Solution {
public:
    int trap(vector<int>& height) {
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        while (leftIndex < rightIndex) {
            if (height[leftIndex] <= height[rightIndex]) {
                leftMax = max(leftMax, height[leftIndex]);
                ans += max(0, leftMax - height[leftIndex]);
                leftIndex++;
            } else {
                rightMax = max(rightMax, height[rightIndex]);
                ans += max(0, rightMax - height[rightIndex]);
                rightIndex--;
            }
        }
        return ans;
    }
};
// Time: O(N)
// Memory: O(1)

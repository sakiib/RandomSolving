class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ((int)matrix.size() == 0) return false;
        int row = matrix.size(), col = matrix[0].size();
        int lo = 0, hi = row * col - 1, ans = false;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int r = mid / col, c = mid % col;
            if (matrix[r][c] < target) lo = mid + 1;
            else if (matrix[r][c] > target) hi = mid - 1;
            else {
                ans = true;
                break;
            }
        }
        return ans;
    }
};

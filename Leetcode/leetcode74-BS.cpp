class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        
        int lo = 0, hi = row - 1, whichRow = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (target >= matrix[mid][0] && target <= matrix[mid][col - 1]) {
                whichRow = mid;
                break;
            } else if (target > matrix[mid][col - 1]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (whichRow == -1) {
            return false;
        }
        
        lo = 0, hi = col - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (matrix[whichRow][mid] == target) {
                return true;
            } else if (matrix[whichRow][mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return false;
    }
};

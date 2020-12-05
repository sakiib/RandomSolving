class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector <vector <int>> mat(row + 5, vector <int> (col + 5, 0));
        vector <vector <int>> dp(row + 5, vector <int> (col + 5, 0));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mat[i + 1][j + 1] = (matrix[i][j] - '0');
            }
        }
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i][j];
            }
        }
        
        auto ok = [&](int l) {
            for (int i = 1; i + l - 1 <= row; i++) {
                for (int j = 1; j + l - 1 <= col; j++) {
                    int kk = i + l - 1 , ll = j + l - 1;
                    int tot = dp[kk][ll] - dp[i-1][ll] - dp[kk][j-1] + dp[i-1][j-1];
                    if(tot == l * l) return true;
                }
            }
            return false;
        };
        
        int lo = 1, hi = min(row, col), len = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (ok(mid)) {
                len = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return (len * len);
    }
};

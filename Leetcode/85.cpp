class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector <vector <int>> dp = vector <vector <int>> (row, vector <int> (col, 0));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dp[i][j] = matrix[i][j] - '0';
                if (i - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] -= dp[i - 1][j - 1];
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = i; k < row; k++) {
                    for (int l = j; l < col; l++) {
                        int temp = dp[k][l];
                        if (j - 1 >= 0) {
                            temp -= dp[k][j - 1];
                        }
                        if (i - 1 >= 0) {
                            temp -= dp[i - 1][l];
                        }
                        if (i - 1 >= 0 && j - 1 >= 0) {
                            temp += dp[i - 1][j - 1];
                        }
                        if ((k - i + 1) * (l - j + 1) == temp) {
                            ans = max(ans, temp);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

// TLE - N^4

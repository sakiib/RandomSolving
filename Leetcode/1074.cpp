class Solution {
public:
    int a[105][105], sum[105][105];
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        memset(sum, 0, sizeof(sum));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                a[i + 1][j + 1] = matrix[i][j];
            }
        }
        
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++){
                for (int k = i; k <= row; k++) {
                    for (int l = j; l <= col; l++) {
                        // [i, j] - [i][l]
                        // [k, j] - [k][l]
                        int tot = sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
                        if (tot == target) ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        bool rowToo = false, colToo = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if (i == 0) {
                        rowToo = true;
                    }
                    if (j == 0) {
                        colToo = true;
                    }
                }
            }
        }
        
        // first pos of row & col contains the marker for this row/col
        // start with row 1 & col 1 so that we don't manipulate the markers
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // now, the first row might be left out, rowToo=true indiceted that first row must be zero as well
        if (rowToo) {
            for (int i = 0; i < col; i++) {
                matrix[0][i] = 0;
            }
        }
        
        // now, the first col might be left out, colToo=true indiceted that first col must be zero as well

        if (colToo) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

// TC: O(R * C)
// MC: O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int cr = row - 1, cc = 0, ans = 0;
        
        while (cr >= 0 && cc < col) {
            if (grid[cr][cc] < 0) {
                ans += col - cc;
                cr--;
            } else {
                cc++;
            }
        }
        
        return ans;
    }
};

// Brute: O(R * C)
// Optimal: O(R + C)
// Alternative: O(R lgC) or O(C lgR)

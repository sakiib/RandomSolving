class Solution {
public:
    int l1, l2, l3;
    string a, b, c;
    int dp[101][101][201];
    
    int solve(int i, int j, int k) {
        if (k == l3) return i == l1 && j == l2;
        if (i >= l1 && j >= l2) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int ok = 0;
        if (i < l1 && a[i] == c[k]) {
            ok |= solve(i + 1, j, k + 1);
        }
        if (j < l2 && b[j] == c[k]) {
            ok |= solve(i, j + 1, k + 1);
        }
        return dp[i][j][k] = ok;
    }
    bool isInterleave(string s1, string s2, string s3) {
        a = s1, b = s2, c = s3;
        l1 = s1.size();
        l2 = s2.size();
        l3 = s3.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0) == 1;
    }
};

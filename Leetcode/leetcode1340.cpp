class Solution {
public:
    int len, dp[1001];
    
    int solve(int idx, int d, vector <int>& arr) {
        if (dp[idx] != -1) return dp[idx];
       
        int ret = 0;
        for (int i = idx + 1; i <= min(idx + d, len - 1) && arr[i] < arr[idx]; i++) {
            ret = max(ret, 1 + solve(i, d, arr));
        }
        
        for (int i = idx - 1; i >= max(idx - d, 0) && arr[i] < arr[idx]; i--) {
            ret = max(ret, 1 + solve(i, d, arr));
        }
        
        return dp[idx] = ret;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        len = arr.size();
        memset(dp, -1, sizeof(dp));
        
        int mx = 1;
        for (int i = 0; i < arr.size(); i++) {
            mx = max(mx, 1 + solve(i, d, arr));
        }
        
        return mx;
    }
};

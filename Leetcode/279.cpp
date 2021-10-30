class Solution {
public:
    const int INF = 1e8;
    int numSquares(int n) {
        vector <int> p;
        for (int i = 1; i <= 100; i++){
            p.push_back(i * i);
        }
        
        vector <int> dp (n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (auto val: p) {
                if (i >= val) {
                    dp[i] = min(dp[i], dp[i - val] + 1);
                }
            }    
        }
        
        return dp[n];
    }
};

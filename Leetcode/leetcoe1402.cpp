class Solution {
public:
    vector <int> items;
    int dp[505][505];
    
    int solve(int idx, int cnt) {
        if (idx >= items.size()) return 0;
        if (dp[idx][cnt] != -1) return dp[idx][cnt];
        int mx = 0;
        mx = max(mx, solve(idx + 1, cnt));
        mx = max(mx, solve(idx + 1, cnt + 1) + (items[idx] * cnt));
        return dp[idx][cnt] = mx;
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        items = satisfaction;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1);
    }
};

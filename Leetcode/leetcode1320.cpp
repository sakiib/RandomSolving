class Solution {
public:
    const int inf = 1e9;
    int row = 5, col = 6, dp[305][30][30];
    
    int cellToIndex(int x, int y) {
        return x * col + y;
    }
    
    pair <int,int> indexToCell(int idx) {
         return make_pair(idx / col, idx % col);
    }
    
    int distance(pair <int,int> f, pair <int,int> s) {
        return abs(f.first - s.first) + abs(f.second - s.second);
    }
    
    int solve(int idx, int f, int s, string word) {
        if (idx == (int)word.size()) return 0;
        if (dp[idx][f][s] != -1) return dp[idx][f][s];
        
        int mn = inf;
        mn = min(mn, solve(idx + 1, word[idx] - 'A', s, word) + distance(indexToCell(f), indexToCell(word[idx] - 'A')));
        mn = min(mn, solve(idx + 1, f, word[idx] - 'A', word) + distance(indexToCell(s), indexToCell(word[idx] - 'A')));
        
        return dp[idx][f][s] = mn;
    }
    
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        // [first position][char where first finger at][second finger at]
        for (int i = 0; i < 26; i++) {
            dp[0][word[0] - 'A'][i] = 0;
        }
        
        int ans = inf;
        for (int i = 0; i < 26; i++) {
            ans = min(ans, solve(1, word[0] - 'A', i, word));
        }
        
        return ans;
        
        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < col; j++) {
        //         cout << i << " " << j << cellToIndex(i, j) << endl;
        //     }
        // }
        
        // for (int i = 0; i < 26; i++) {
        //     pair <int,int> pos = indexToCell(i);
        //     cout << pos.first << " " << pos.second << endl;
        // }
    }
};

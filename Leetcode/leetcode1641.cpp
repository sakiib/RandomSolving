class Solution {
public:
    int countVowelStrings(int n) {
        int ans = 0;
        for (int j=1; j<=(n+1); j++) {
            int cur = 0;
            for (int i=1; i<=j; i++) {
                cur += i;
                ans += cur;
            }
        }
        return ans;
    }
};

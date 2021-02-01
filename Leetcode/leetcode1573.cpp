class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(string s) {
        int ones = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            ones += (s[i] == '1');
        }
        
        if (ones == 0) {
            return (1LL * (n - 2) * (n - 1) / 2 % mod);
        }
        
        if (ones % 3 != 0) {
            return 0;
        }
        
        int onesInEachSplitedBlock = ones / 3;
        long waysOfFirstCut = 0, waysOfSecondCut = 0;
        for (int i = 0, count = 0; i < n; ++i) {
            count += (s[i] == '1');
            if (count == onesInEachSplitedBlock) {
                ++waysOfFirstCut;
            }else if (count == 2 * onesInEachSplitedBlock) {
                ++waysOfSecondCut;
            }
        }
        return (1LL * waysOfFirstCut * waysOfSecondCut % mod); 
    }
};

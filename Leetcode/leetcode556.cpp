class Solution {
public:
    int nextGreaterElement(int n) {
        vector <int> digits;
        int temp = n;
        while (temp) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        
        sort(digits.begin(), digits.end());
        
        long long ans = -1;
        do {
            long long cur = 0;
            for (auto d: digits) cur = cur * 10 + d;
            if (cur > n) {
                if (ans == -1) {
                    ans = cur;
                } else {
                    ans = min(ans, cur);
                }
            }
        } while (next_permutation(digits.begin(), digits.end()));
        
        if (ans > (1LL << 31) - 1) {
        	ans = -1;
        }
        return int(ans);
    }
};

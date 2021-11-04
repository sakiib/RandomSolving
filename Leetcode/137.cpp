class Solution {
public:
    const long long OFFSET = (1 << 31);
    
    long long Set(long long N, int pos) {
      return N |= (1LL << pos);
    }

    bool Check(long long N, int pos) {
      return (bool)(N & (1LL << pos));
    }
    
    int singleNumber(vector<int>& nums) {
        vector <long long> numbers;
        for (auto num: nums) {
            numbers.push_back(num + OFFSET);
        }
        
        vector <int> counter (33, 0);
        for (auto num: numbers) {
            for (int i = 0; i <= 32; i++) {
                if (Check(num, i)) {
                    counter[i]++;
                }
            }
        }
        
        long long ans = 0;
        for (int i = 0; i <= 32; i++) {
            if (counter[i] % 3 == 1) {
                ans = Set(ans, i);
            }
        }
        
        return ans - OFFSET;
    }
};

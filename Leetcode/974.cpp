class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        map <int, int> prefix;
        prefix[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum %= k;
            if (sum < 0) sum += k;
            if (prefix.count(sum)) ans += prefix[sum];
            prefix[sum]++;
        }
        return ans;
    }
};

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        int can = target[0];
        for (int i = 1; i < target.size(); i++) {
            if (target[i] <= can) {
                can = target[i];
            } else {
                ans += target[i] - can;
                can = target[i];
            }
        }
        return ans;
    }
};

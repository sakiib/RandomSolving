class Solution {
public:
    typedef long double ld;
    
    int halveArray(vector<int>& nums) {
        long double sum = 0.0;
        priority_queue <ld> q;

        for (auto num: nums) {
            sum += num;
            q.push(num);
        }
        
        int ans = 0;
        long double cur = 0.0;
        while (!q.empty()) {
            ans ++;
            long double tp = q.top();
            q.pop();
            long double half = tp * 0.5;
            cur += half;
            q.push(half);
            if (cur * 2.0 >= sum) {
                break;
            }
        }
            
        return ans;
    }
};

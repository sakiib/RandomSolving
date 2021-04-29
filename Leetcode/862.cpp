class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int len = A.size();
        
        vector <int> sum (len, 0);
        for (int i = 0; i < len; i++) {
            sum[i] = A[i] + (i > 0? sum[i - 1]: 0);
        }
        
        int minLength = (int)1e9;
        deque <int> dq;
        for (int i = 0; i < len; i++) {
            while (!dq.empty() && sum[i] <= sum[dq.back()]) {
                dq.pop_back();
            }
            while (!dq.empty() && sum[i] - sum[dq.front()] >= K) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }
            if (sum[i] >= K) {
                minLength = min(minLength, i + 1);
            }
            dq.push_back(i);
        }
        
        return minLength == (int)1e9? -1: minLength;
    }
};

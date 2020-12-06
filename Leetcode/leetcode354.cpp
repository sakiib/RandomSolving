class Solution {
public:
    int longestIncreasingSubsequence(vector <int> &height) {
        multiset <int> st;
        for (auto x: height) {
            st.insert(x);
            auto it = st.lower_bound(x); ++it;
            if (it != st.end()) st.erase(it);
        }
        return (int)st.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector <int> a, vector <int> b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        vector <int> height;
        for (auto &x: envelopes) height.push_back(x[1]);
        return longestIncreasingSubsequence(height);
    }
};

/**
1. Sort the array. Ascend on width and descend on height if width are same.
2. Find the longest increasing subsequence based on height.

Since the width is increasing, we only need to consider height.
[3, 4] cannot contains [3, 3], so we need to put [3, 4] before [3, 3] 
when sorting otherwise it will be counted as an increasing number if the order is [3, 3], [3, 4]
*/

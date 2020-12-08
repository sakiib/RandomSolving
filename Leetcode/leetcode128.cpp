class Solution {
public:
    unordered_map <int,int> parent;
    unordered_map <int,int> size;
    unordered_map <int,int> have;
    
    void makeSet(vector <int>& nums) {
        for (auto num: nums) {
            parent[num] = num;
            size[num] = 1;
            have[num] = 1;
        }
    }
    int findRoot(int u) {
        return parent[u] == u? u : parent[u] = findRoot(parent[u]);
    }
    void unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v) {
            parent[u] = v;
            size[v] += size[u];
        } 
    }
    int longestConsecutive(vector<int>& nums) {
        if ((int)nums.size() == 0) return 0;
        makeSet(nums);
        int ans = 1;
        for (auto num: nums) {
            if (have.count(num) && have.count(num - 1)) {
                unite(num, num - 1);
                ans = max(ans, size[findRoot(num)]);
            } 
            if (have.count(num) && have.count(num + 1)) {
                unite(num, num + 1);
                ans = max(ans, size[findRoot(num)]);
            }
        }
        return ans;
    }
};

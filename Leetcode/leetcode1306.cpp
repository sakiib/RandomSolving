class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue <int> q;
        vector <bool> visited (5e4 + 5, false);
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            visited[f] = true;
            if (arr[f] == 0) return true;
            if (f - arr[f] >= 0 && !visited[f - arr[f]]) {
                q.push(f - arr[f]);
            }
            if (f + arr[f] < arr.size() && !visited[f + arr[f]]) {
                q.push(f + arr[f]);
            }
        }
        return false;
    }
};

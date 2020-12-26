class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector <bool> visited(rooms.size(), false);
        queue <int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            for (auto key: rooms[id]) {
                if (!visited[key]) {
                    q.push(key);
                    visited[key] = true;
                }
            }
        }
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};

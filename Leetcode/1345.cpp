class Solution {
public:
    int minJumps(vector<int>& arr) {
        map <int, vector <int> > pos;
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
        
        vector <int> cost ((int)arr.size(), -1);
        map <int, bool> jumped;
        
        queue <int> q;
        q.push(0);
        cost[0] = 0;
        
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            
            if (f - 1 >= 0 && (cost[f - 1] == -1 || cost[f - 1] > cost[f] + 1)) {
                cost[f - 1] = cost[f] + 1;
                q.push(f - 1);
            }
            
            if (f + 1 < arr.size() && (cost[f + 1] == -1 || cost[f + 1] > cost[f] + 1)) {
                cost[f + 1] = cost[f] + 1;
                q.push(f + 1);
            }
            
            int curval = arr[f];
            if (jumped[curval]) continue;
            
            jumped[curval] = true;
            for (int i = 0; i < pos[curval].size(); i++) {
                if (cost[pos[curval][i]] == -1 || cost[pos[curval][i]] == cost[f] + 1) {
                    cost[pos[curval][i]] = cost[f] + 1;
                    q.push(pos[curval][i]);
                }
            }
        }
        
        return cost[(int)arr.size() - 1];
    }
};

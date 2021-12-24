class Solution {
public:
    static const int N = 5e3 + 1;
    
    vector <int> graph[N];
    int indegree[N];
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue <int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        
        vector <int> ans;
        while (!q.empty()) {
            int f = q.front(); 
            q.pop();
            ans.push_back(f);
            for (auto x: graph[f]) {
                indegree[x]--;
                if (!indegree[x]) {
                    q.push(x);
                }
            }
        }
        
        return (int)ans.size() == numCourses;
    }
};

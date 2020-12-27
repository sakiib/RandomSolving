/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static const int N = 1e5 + 5;
    vector <vector <int> > ans;
    vector <int> lvl[N];
    
    void dfs(int depth, TreeNode* root) {
        if (root == nullptr) return;
        lvl[depth].push_back(root -> val);
        if (root -> left) {
            dfs(depth + 1, root -> left);
        }
        if (root -> right) {
            dfs(depth + 1, root -> right);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(0, root);
        for (int i = 0; i < N; i++) {
            if (lvl[i].size() == 0) continue;
            ans.push_back(lvl[i]);
        }
        return ans;
    }
};

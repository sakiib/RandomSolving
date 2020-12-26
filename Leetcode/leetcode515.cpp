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
    static const int N = 1e5;
    const int inf = -2147483648;
    int mx_lvl;
    vector <int> levels[N];
    
    void solve(TreeNode* root, int lvl) {
        if (root == nullptr) return;
        levels[lvl].push_back(root -> val);
        mx_lvl = max(mx_lvl, lvl);
        if (root -> left != nullptr) {
            solve(root -> left, lvl + 1);
        }
        if (root -> right != nullptr) {
            solve(root -> right, lvl + 1);
        }
    }
    
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        solve(root, 0);
        vector <int> ans;
        for (int i = 0; i <= mx_lvl; i++) {
            int mx = inf;
            for (auto val: levels[i]) mx = max(mx, val);
            ans.push_back(mx);
        }
        return ans;
    }
};

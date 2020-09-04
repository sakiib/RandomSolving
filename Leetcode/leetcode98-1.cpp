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
    long long inf = 1e18;
    vector <int> inorder;
    void solve(TreeNode* temp) {
        if (temp == NULL) return;
        if (temp -> left != NULL) solve(temp -> left);
        inorder.push_back(temp -> val);
        if (temp -> right != NULL) solve(temp -> right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        bool valid = true;
        for (int i = 1; i < (int)inorder.size(); i++) {
            valid &= (inorder[i] > inorder[i - 1]);
        }
        return valid;
    }
};

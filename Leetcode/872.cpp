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
    void findLeaves(TreeNode* root, vector <int> &v) {
        if (root -> right == nullptr && root -> left == nullptr) {
            v.push_back(root -> val);
            return;
        }
        if (root -> left != nullptr) {
            findLeaves(root -> left, v);
        }
        if (root -> right != nullptr) {
            findLeaves(root -> right, v);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> a;
        vector <int> b;
        findLeaves(root1, a);
        findLeaves(root2, b);
        return a == b;
    }
};

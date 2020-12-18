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
    int solve(TreeNode* root, int parent, int grandParent) {
        if (root == nullptr) {
            return 0;
        }
        
        int sum = 0;
        if (grandParent != 0 && grandParent % 2 == 0) {
            sum = root -> val;
        }
        
        if (root -> left != nullptr) {
            sum += solve(root -> left, root -> val, parent);
        }
        
        if (root -> right != nullptr) {
            sum += solve(root -> right, root -> val, parent);
        }
        
        return sum;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, 0, 0);
    }
};

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
    int findHeight(TreeNode* root) {
        int height = 0;
        if (root -> left != nullptr) {
            height = max(height, findHeight(root -> left) + 1);
        }
        if (root -> right != nullptr) {
            height = max(height, findHeight(root -> right) + 1);
        }
        return height;
    }
    
    int sumOfDeepestLeaves(TreeNode* root, int height, int curHeight) {
        if (height == curHeight) {
            return root -> val;
        }
        int sum = 0;
        if (root -> left != nullptr) {
            sum += sumOfDeepestLeaves(root -> left, height, curHeight + 1);
        }
        if (root -> right != nullptr) {
            sum += sumOfDeepestLeaves(root -> right, height, curHeight + 1);
        }
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int height = findHeight(root);
        return sumOfDeepestLeaves(root, height, 0);
    }
};

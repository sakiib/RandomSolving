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
    bool solve(TreeNode* temp, long long mn, long long mx) {
        if (temp == NULL) return true;
        if (temp -> val < mn || temp -> val > mx) return false;
        bool ret = true;
        if (temp -> left != NULL) {
            if (temp -> left -> val < temp -> val) {
                ret &= solve(temp -> left, mn, temp -> val - 1);
            }
            else return false;
        }
        if (temp -> right != NULL) {
            if (temp -> right -> val > temp -> val) {
                ret &= solve(temp -> right, temp -> val + 1, mx);
            }
            else return false;
        }
        return ret;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, -inf, inf);
    }
};

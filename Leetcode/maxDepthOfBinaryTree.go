/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(x, y int) int {
    if x > y {
        return x
    } 
    return y
}

func solve(root *TreeNode) int {
    if root == nil {
        return 0
    }
    ret := 0
    if root.Left != nil {
        ret = max(ret, solve(root.Left) + 1)
    }
    if root.Right != nil {
        ret = max(ret, solve(root.Right) + 1)
    }
    return ret
}

func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return 1 + solve(root)
}

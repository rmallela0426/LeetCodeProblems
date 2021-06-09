
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 104: Maximum Depth of Binary Tree
 *
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from
 * the root node down to the farthest leaf node.
 *
 * Example 1:
 *                3
 *              /   \
 *             9     20
 *                  /  \
 *                 15   7
 *  Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 * Example 2:
 * Input: root = [1,null,2]
 * Output: 2
 *
 * Example 3:
 * Input: root = []
 * Output: 0
 *
 * Example 4:
 * Input: root = [0]
 * Output: 1
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 104].
 * -100 <= Node.val <= 100
*/
int maxDepth(TreeNode* root) {
    // Checck if root is NULL
    if (!root) {
        // We are children of leaf node, depth is zero
        return 0;
    }

    // calculate the depth of left subtree
    int ldepth = maxDepth(root->left);
    // calculate the depth of right subtree
    int rdepth = maxDepth(root->right);

    // Return the max Depth of the subtree
    // + 1 is for the current node
    return 1 + max(ldepth, rdepth);

}

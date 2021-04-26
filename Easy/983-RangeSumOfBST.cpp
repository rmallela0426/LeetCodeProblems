
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 983: Range Sum of BST
 *
 * Given the root node of a binary search tree, return the sum of values
 * of all nodes with a value in the range [low, high].
 *
 * Example 1:
 * Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
 * Output: 32
 *
 * Example 2:
 * Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * Output: 23
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 2 * 104].
 * 1 <= Node.val <= 105
 * 1 <= low <= high <= 105
 * All Node.val are unique.
*/
/*
 * Approach followed is DFS ie.., recursive approach, where if the current
 * node value is in the range then result is sum of current node value plus
 * left sum, right sum
*/
int rangeSumBST(TreeNode* root, int low, int high) {
    // Check if the node is NULL
    if (root == NULL) {
        // Current node is NULL reached the tail, no values
        // in the range, return NULL
        return NULL;
    }

    // Check if the current node value in range
    if (root->val >= low && root->val <= high) {
        // It is in range, traverse the left and right nodes
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

    // Current value is not in the range, check if the
    // left, right node values are in range.
    return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 110: Balanced Binary Tree
 *
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 *    a binary tree in which the left and right subtrees of every node differ
 *    in height by no more than 1.
 *
 * Example 1:
 *            3
 *          /  \
 *         9   20
 *            /  \ 
 *           15   7
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 * Example 2:
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 * Example 3:
 * Input: root = []
 * Output: true
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 5000].
 * -104 <= Node.val <= 104
*/
/*
 * Balanced BT is a height balanced only when left subtree height & right
 * subtree height absolute difference is <= 1. This should be valid for all
 * subtrees. If in case in any of the subtree is not balanced, then BT is
 * not balanced.
 * Approach to solve this is DFS method, where at root it asks left or right
 * subtrees whether it is balanced and what is the height of it. It should
 * again it children the same and goes on until we reach a leaf node. When
 * we reach a leaf node, it children should return height of 0 as it is
 * NULL.
 *
 * Steps:
 *  . The height at a particular node is max(leftheight, rightheight) + 1
*/
// This function the height of the node and returns -1 if it is not balnaced
int calcHeight(TreeNode* root) {
    // Check if the root node is NULL or not
    if (!root) {
        // Reached the children of leaf node
        return 0;
    }

    // Calculate the height of left subtree
    int lheight = calcHeight(root->left);
    // Calculate the height of right subtree
    int rheight = calcHeight(root->right);

    // Check if the node is not balanced or not
    if (lheight == -1 || rheight == -1 || abs(lheight - rheight) > 1) {
        // Current subtree is not balanced, return -1
        return -1;
    }

    // Return the height of subtree
    return max(lheight, rheight) + 1;
}

bool isBalanced(TreeNode* root) {
    return calcHeight(root) != -1;
}

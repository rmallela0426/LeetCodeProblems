
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 230: Kth Smallest Element In BST
 *
 * Given the root of a binary search tree, and an integer k, return the
 * kth (1-indexed) smallest element in the tree.
 *
 * Example 1:
 *             3
 *           /   \ 
 *          1     4
 *           \
 *            2
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 * Example 2:
 *              5
 *            /   \
 *           3     6
 *         /  \
 *        2    4
 *       /
 *      1
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *
 * Constraints:
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 104
 * 0 <= Node.val <= 104
 * Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need
 * to find the kth smallest frequently, how would you optimize?
*/
/*
 * As we are traversing BST and we need to find the kth Smallest value we can
 * traverse only on the left subtree , will perform inorder traversal
*/
void inorder(TreeNode* node, int& k, int& minValue) {
    // check if the node is NULL
    if (!node) {
        // Reached the children of leaf nodes
        return;
    }

    // Traverse left subtree
    inorder(node->left, k, minValue);

    // Once you reach the leaf, initialize minValue only when
    // we reached kth min element
    if (k-- == 1) {
        minValue = node->val;
    }

    // Traverse the right subtree
    inorder(node->right, k, minValue);
}

int kthSmallest(TreeNode* root, int k) {
    int minValue = 0;
    inorder(root, k, minValue);

    return minValue;
}

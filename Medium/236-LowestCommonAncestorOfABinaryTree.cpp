
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 236: Lowest Common Ancestor Of a Binary Tree
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
 * in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is
 * defined between two nodes p and q as the lowest node in T that has both p and q
 * as descendants (where we allow a node to be a descendant of itself).”
 *
 * Example 1:
 *             3
 *          /    \
 *         5       1
 *       /  \     /  \
 *      6    2   0    8
 *          / \
 *         7   4
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 * Example 2:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
 * according to the LCA definition.
 *
 * Example 3:
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 *
 * Constraints:
 * The number of nodes in the tree is in the range [2, 105].
 * -109 <= Node.val <= 109
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
*/
/*
 * Approach followed is a recursive solution, where we check the root value
 * whether it is equal or not, if equal returns the root else we will search
 * the left subtree and right subtree. If any of it returns true, that means
 * p and q are in the same subtree, we will return the other subtree. If both
 * are not NULL, then the root is an acestor of p and q
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Check whether the tree is NULL or not
    if (!root) {
        // root is NULL, returning
        return NULL;
    }

    // Check if the current node values is equal to any of node values of p and q
    if (root->val == p->val || root->val == q->val) {
        // we found a node, return the root
        return root;
    }

    // Search on the left subtree
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    // Search on the right subtree
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // Check whether left subtree returns NULL or not ie.., both p and q nodes
    // are not found in left subtree
    if (!left) {
        // p and q didn't found in the left subtree
        return right;
    }

    // Check whether the right subtree returns NULL or not ie.., both p and q nodes
    // are not found in right subtree
    if (!right) {
        // p and q didn't found in right subtree
        return left;
    }

    // p and q are found in the left and right subtrees in which case we return the
    // current node ie.., parent of left and right
    return root;
}

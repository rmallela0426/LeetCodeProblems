
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 98: Validate Binary Search Tree
 *
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 *  . The left subtree of a node contains only nodes with keys less than the node's key.
 *  . The right subtree of a node contains only nodes with keys greater than the node's key.
 *  . Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 *         2
 *       /  \
 *      1    3
 *
 * Input: root = [2,1,3]
 * Output: true
 *
 * Example 2:
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 104].
 * -2^31 <= Node.val <= 2^31 - 1
*/
/*
 * BST is such that the left sutree values are less than the node's key
 * and right subtree values are greater than node's key.
 * That means if we maintain min and max values, and if we are processing
 * left subtree that value should be less than or equal to max value ie..,
 * nodes value.
*/
bool isValidBST(TreeNode* root, TreeNode* minNode = NULL, TreeNode* maxNode = NULL) {
    // check if the root is NULL or not
    if (!root) {
        // We are at the children of the leaf nodes
        return true;
    }

    // cureent node values shouldn't be greater than or equal to max
    // and is not <= min
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
        // not a valid value, return false
        return false;
    }

    // Travers through left subtree and right subtree
    // When traversing left, the nodes values should be < the current node value
    // i.e.., max value is the current node val. Simillarly, the current node value
    // is the min value on the right subtree
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

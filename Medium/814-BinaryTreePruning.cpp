
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 814: Binary Tree Pruning
 *
 * Given the root of a binary tree, return the same tree where every subtree
 * (of the given tree) not containing a 1 has been removed.
 *
 * A subtree of a node node is node plus every node that is a descendant of node.
 *
 * Example 1:
 * Input: root = [1,null,0,0,1]
 * Output: [1,null,0,null,1]
 * Explanation:
 * Only the red nodes satisfy the property "every subtree not containing a 1".
 * The diagram on the right represents the answer.
 *
 * Example 2:
 * Input: root = [1,0,1,0,0,0,1]
 * Output: [1,null,1,null,1]
 *
 * Example 3:
 * Input: root = [1,1,0,1,1,0,1,0]
 * Output: [1,1,0,1,1,null,1]
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 200].
 * Node.val is either 0 or 1.
*/
/*
 * Approach followed is a DFS Post Order Traversal solution where
 * for each node we try to find whether it is a leaf node and its
 * value is 0. If so, then remove that subtree
*/
TreeNode* pruneTree(TreeNode* root) {
    // BaseCase: If root is NULL or not
    if (!root) {
        // Current Node is NULL, a Leaf Node return NULL
        return NULL;
    }

    // As Traversal is PostOrder (L-R-R), traverse on the left subtree
    // and update the value of left
    root->left = pruneTree(root->left);
    // Traverse on Right Subtree, update the value of right
    root->right = pruneTree(root->right);
    
    // Check if the current root value is zero and it is a leaf node,
    // then remove this node, return NULL
    if (root->val == 0 && !root->left && !root->right) {
        // Current node is a leaf node and node value is zero, remove
        // this node
        return NULL;
    }

    // Not a leaf node or current root node value is not zero
    return root;
}

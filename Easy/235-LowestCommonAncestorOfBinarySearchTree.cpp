
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 235: Lowest Common Ancestor Of a Binary Search Tree
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA)
 * of two given nodes in the BST.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Example 1:
 *            6
 *         /     \
 *        2       8
 *      /   \   /   \
 *     0    4   7    9
 *        /   \
 *       3     5
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 * Example 2:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 * Example 3:
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 * Constraints:
 * The number of nodes in the tree is in the range [2, 105].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the BST.
*/
/*
 * Approach followed is a recursive solution where the given tree is
 * a Binary search tree ie.., value lower that the root node resides
 * on left subtree and value greater than root node will reside on
 * right subtree. Taking this into advantage, check whether p value
 * q value are greater than current root, if so traverse on the right
 * subtree. If the p & q values are less than current root value then
 * proceed on the left subtree. If one value is at left and one value
 * at right, then root will be become the LCA
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // BaseCase: If root is Null
    if (!root) {
        // Current node is empty there won't be any ancestor.\
        return NULL;
    }

    // Check if both values are greater than current node value
    if (p->val > root->val && q->val > root->val) {
        // Both p & q node values are greater than current node value
        // which means that the LCA is on right subtree
        return lowestCommonAncestor(root->right, p, q);
    }
    // Check if both values are less than current node value
    if (p->val < root->val && q->val < root->val) {
        // Both p & q node values are less than current node values
        // which means that the LCA is on left subtree
        return lowestCommonAncestor(root->left, p, q);
    }

    // If both p & q values aer equal to root node value or if p node
    // value is greater or lesser than root node value or if q node
    // value is lesser or greater than root node value, then current
    // node value is a LCA
    return root;
}

/*
 * Iterative solution where the smallest and largest out of p & q are
 * calculated as smaller and larger. Traverse the list now check if
 * the root node value is less than smaller value, then need to proceed
 * on the right else if current root value is larger than larger value
 * then need to proceed on left subtree. If the root value is equal to
 * smaller and larger then LCA will be current root
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // BaseCase: If root is Null
    if (!root) {
        // Current node is empty there won't be any ancestor.\
        return NULL;
    }

    // Variables to store smallest and largest of p & q
    // Initialize in such a way that q node value is greater than p node
    // value
    int smaller = p->val;
    int larger = q->val;

    // Check if p node value is greater than q node value
    if (p->val > q->val) {
        // q node value is smaller than p node value, update
        smaller = q->val;
        larger = p->val;
    }

    // Traverse the list
    while (root) {
        // Check if the current node value is less than smaller value
        if (root->val < smaller) {
            // Current node value is less than smaller , as larger value
            // is greater than smaller ie.., both values will be on right
            // subtree. Update root to proceed on the right subtree
            root = root->right;
        }
        else if (root->val > larger) {
            // As the current node value is greater than larger ie.., larger
            // value is less than current node value and current value is
            // greater than smaller also, need to traverse on left subtree
            root = root->left;
        }
        else {
            // If current node value, p and q node values are eqaul or either
            // of the above 2 cases
            return root;
        }
    }

    // By default the current node is LCA
    return root;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 897: Increasing Order Search Tree
 *
 * Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost
 * node in the tree is now the root of the tree, and every node has no left child and only one
 * right child.
 *
 * Example 1:
 *           5                1
 *         /   \               \
 *        3     6               2
 *      /  \     \               \
 *     2    4     8               3
 *    /          /  \              \
 *   1          7    9              4
 *                                   \
 *                                    5
 *                                     \
 *                                      6
 *                                       \
 *                                        7
 *                                         \
 *                                          8
 *                                           \
 *                                            9
 *
 * Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 *
 * Example 2:
 * Input: root = [5,1,7]
 * Output: [1,null,5,null,7]
 *
 * Constraints:
 * The number of nodes in the given tree will be in the range [1, 100].
 * 0 <= Node.val <= 1000
*/
/*
 * Approach followed is Inorder traversal
*/
void inOrder(TreeNode* root, TreeNode*& prev, TreeNode*& head) {
    // Check if the root is NULL
    if (!root) {
        // Node is NULL,
        return;
    }

    // As Inorder Traversal is Left, Root, Right
    inOrder(root->left, prev, head);

    // Got the leaf node, and now process root. Copy the head
    if (!prev) {
        // Copy the current root to head
        head = root;
    }
    else {
        // we should have the root, prev will hold the current root
        // copy the currennt node to the right and left to NLL
        prev->right = root;
        root->left = NULL;
    }

    // copy the current root to prev
    prev = root;

    // Traverse the right subtree
    inOrder(root->right, prev, head);
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNode* head = NULL;
    TreeNode* prev = NULL;

    inOrder(root, prev, head);

    return head;
}

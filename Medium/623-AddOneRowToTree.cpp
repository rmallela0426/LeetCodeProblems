
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Given the root of a binary tree, then value v and depth d, you need to add a
 * row of nodes with value v at the given depth d. The root node is at depth 1.
 *
 * The adding rule is: given a positive integer depth d, for each NOT null tree
 * nodes N in depth d-1, create two tree nodes with value v as N's left subtree
 * root and right subtree root. And N's original left subtree should be the left
 * subtree of the new left subtree root, its original right subtree should be the
 * right subtree of the new right subtree root. If depth d is 1 that means there
 * is no depth d-1 at all, then create a tree node with value v as the new root
 * of the whole original tree, and the original tree is the new root's left subtree.
 *
 * Example 1:
 * Input: A binary tree as following:
 *      4
 *    /   \
 *   2     6
 *  / \   /
 * 3   1 5
 *
 * v = 1 d = 2
 * Output:
 *       4
 *      / \
 *     1   1
 *    /     \
 *   2       6
 *  / \     /
 * 3   1   5
 *
 * Example 2:
 * Input: A binary tree as following:
 *     4
 *    /
 *   2
 *  / \
 * 3   1
 *
 * v = 1 d = 3
 * Output:
 *      4
 *     /
 *    2
 *   / \
 *  1   1
 *  /     \
 *  3       1
 * Note:
 * The given d is in range [1, maximum depth of the given tree + 1].
 * The given binary tree has at least one tree node.
*/
// Algorithm followed was DFS
TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
        // Depth is 1 means the root node
        // If depth d is 1 that means there is no depth d-1 at all,
        // then create a tree node with value v as the new root of
        // the whole original tree, and the original tree is the new
        // root's left subtree.
        TreeNode* node = new TreeNode(v);
        node->left = root;
        return node;
    }

    // DFS algorithmm to add a node at the depth
    dfs(root, v, d - 1);

    return root;
}

void dfs(TreeNode* node, int value, int depth) {
    // If the node is NULL, then return
    if (node == NULL)
        return;

    if (depth == 1) {
        // Reached the right depth, insert new nodes here
        TreeNode* tempL = node->left;
        TreeNode* tempR = node->right;

        // create two tree nodes with value v as N's left
        // subtree root and right subtree root
        node->left = new TreeNode(value);
        node->right = new TreeNode(value);

        // And N's original left subtree should be the left
        // subtree of the new left subtree root,
        node->left->left = tempL;

        // its original right subtree should be the right
        // subtree of the new right subtree root.
        node->right->right = tempR;
    }
    else {
        // Decrement the depth and loop until reaches the tail or
        // reached the required depth
        dfs(node->left, value, depth - 1);
        dfs(node->right, value, depth - 1);
    }
}

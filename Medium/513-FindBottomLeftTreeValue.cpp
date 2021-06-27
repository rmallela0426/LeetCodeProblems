
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 513: Find Bottom Left Tree Value
 *
 * Given the root of a binary tree, return the leftmost value in the last row of the tree.
 *
 * Example 1:
 *              2
 *            /    \
 *           1      3
 *
 * Input: root = [2,1,3]
 * Output: 1
 *
 * Example 2:
 *               1
 *            /    \
 *           2      3
 *         /       /  \
 *        4       5    6
 *               /
 *              7
 *
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 104].
 * -231 <= Node.val <= 231 - 1
*/
/*
 * Approach followed is BFS, where traversing at each level, saving the left
 * node
*/
int findBottomLeftValue(TreeNode* root) {
    // Base case if the root is NULL
    if (!root) {
        // Node is NULL
        return NULL;
    }

    // Queue for storing the nodes in each level
    queue<TreeNode*> q;

    // variable to store the value of the left node
    int res = 0;

    // push the root to the queue
    q.push(root);

    // Traverse while queue isn't empty
    while (!q.empty()) {
        // retreive the num of nodes at this level
        int n = q.size();

        // Traverse all the nodes at the level
        for (int i = 0; i < n; i++) {
            // Get the top node from queue
            TreeNode* node = q.front();
            q.pop();

            // Push the left child if it is not NULL
            if (node->left) {
                q.push(node->left);
            }

            // Push the right child if it is not NULL
            if (node->right) {
                q.push(node->right);
            }

            // save the node value if it is a first node at each level
            // i.e.., leftmost node
            if (i == 0) {
                res = node->val;
            }
        }
    }

    return res;
}

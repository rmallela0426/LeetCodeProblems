
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1302: Deepest Leaves Sum
 *
 * Given the root of a binary tree, return the sum of values of its
 * deepest leaves.
 *
 * Example 1:
 * Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * Output: 15
 *
 * Example 2:
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 19
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 104].
 * 1 <= Node.val <= 100
*/
/*
 * Approach followed is the BFS, where at each level the
 * sum is calculated. In order to do that, need to save
 * each level coordinates will be saved in queue.
*/
int deepestLeavesSum(TreeNode* root) {
    if (root == NULL) {
        // Tree is empty return 0 as there are
        // no elements are there
        return 0;
    }

    // variable to store the sum of each level
    int sum = 0;
    // Queue to store each level nodes
    std::queue<TreeNode*> q;

    // push the root node to queue
    q.push(root);

    // Loop until the queue is empty
    while (!q.empty()) {
        // Resetting the sum to zero as the sum is calculated
        // for each level
        sum = 0;

        int size = q.size();
        for (int i = 0; i < size; i++) {
            // Pointer for the first node
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;

            // Push the left node to queue
            if (node->left) {
                q.push(node->left);
            }

            // Push the righ node to queue
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    return sum;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 637 : AverageLevelsInBinaryTree
 * Given a non-empty binary tree, return the average value of the nodes
 * on each level in the form of an array.
 *
 * Example 1:
 * Input:
 *    3
 *   / \
 *  9  20
 *  /   \
 *  15   7
 * Output: [3, 14.5, 11]
 *
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11.
 * Hence return [3, 14.5, 11].
 * Note:
 * The range of node's value is in the range of 32-bit signed integer.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<double> averageOfLevels(TreeNode* root) {
    /* Approach that followed is BFS */

    // Vector to store the result
    vector<double> res;

    if (root == NULL) {
        // If the tree is empty, then return
        return res;
    }

    // Queue to store the left & right childs of a node
    std::queue<TreeNode*> q;

    // Push the root node to queue
    q.push(root);

    // Loop until queue is empty ie.., all childs are processed
    while (!q.empty()) {
        // variables to store sum of the nodes and no of nodes
        long sum = 0;
        long numNodes = 0;

        int size = q.size();

        // Loop until all the nodes are completed
        for (int i = 0; i < size; i++) {
            // retreive and pop the front of hte queue
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;
            numNodes++;

            // Push the left and right children from node
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        double avg = (double)(sum) / numNodes;
        // push the result of average of node values
        res.push_back(avg);
    }
    // return the result
    return res;
}

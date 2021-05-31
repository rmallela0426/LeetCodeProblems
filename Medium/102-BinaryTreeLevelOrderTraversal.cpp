
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 102: Binary Tree Level Order Traversal
 *
 * Given the root of a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
 *
 * Example 1:
 *               3
 *            /    \
 *           9     20
 *                /  \
 *               15   7
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
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
// Ist Solution
vector<vector<int>> levelOrder(TreeNode* root) {
    // Result vector
    vector<vector<int>> res;

    // Check if the node is NULL
    if (root == NULL) {
        // Node is null, return
        return res;
    }

    // In order to traverse level by level, we need a queue
    queue<TreeNode*> q;

    // Push the first level to queue ie.., root
    q.push(root);

    // Push a NULL node to tell the algo that level is completed
    q.push(NULL);

    // Temporary vector to store each level values
    vector<int> level;

    // Loop while the queue is empty
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // Check if the level is completed
        if (curr == NULL) {
            // push the level node values to result vector
            res.push_back(level);

            // check if the queue is empty
            if (q.empty()) {
                // queue is empty i.e.., we are at leaf nodes
                break;
            }

            // clear the temporary vector
            level.clear();

            // Push a NULL node to tell the algo that level is completed
            q.push(NULL);
        }
        else {
            // push the current node values to level vector
            level.push_back(curr->val);

            // push the left and right children to the queue
            if (curr->left) {
                q.push(curr->left);
            }

            if (curr->right) {
                q.push(curr->right);
            }
        }
    }

    return res;
}

// IInd Solution
vector<vector<int>> levelOrder(TreeNode* root) {
    // Result vector
    vector<vector<int>> res;

    // Check if the node is NULL
    if (root == NULL) {
        // Node is null, return
        return res;
    }

    // In order to traverse level by level, we need a queue
    // Holds all nodes in the current level
    queue<TreeNode*> q;

    // Push the first level to queue ie.., root
    q.push(root);

    // Temporary vector to store each level values
    vector<int> level;

    // Loop while the queue is empty
    while (!q.empty()) {
        // Get the size of the current level ie.., num nodes in that level
        int numNodes = q.size();

        while (numNodes-- > 0) {
            // Get the node from the queue
            TreeNode* curr = q.front();
            q.pop();

            // push the current node values to level vector
            level.push_back(curr->val);

            // push the left and right children to the queue
            if (curr->left) {
                q.push(curr->left);
            }

            if (curr->right) {
                q.push(curr->right);
            }
        }

        // push the level node values to result vector
        res.push_back(level);

        // clear the temporary vector
        level.clear();
    }

    return res;
}

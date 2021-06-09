
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 199: Binary Tree Right Side View
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * Example 1:
 *                1
 *             /     \
 *            2       3
 *            \        \
 *             5        4
 * 
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 *
 * Example 2:
 * Input: root = [1,null,3]
 * Output: [1,3]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
*/
/*
 * Approach followed is a BFS solution where at each level we take the last
 * element to the output vector
*/
vector<int> rightSideView(TreeNode* root) {
    // Check if there is a tree or not
    if (!root) {
        // Return an empty vector
        return {};
    }

    // vector to store all visible node values from right side
    vector<int> visible;

    // Approach is BFS so we need a queueue to store the nodes at this level
    queue<TreeNode*> q;

    // Push the root level in queue
    q.push(root);

    // Traverse while the queue is empty
    while (!q.empty()) {
        // retrieve the size of the level
        int n = q.size();

        // Loop all the nodes in this level
        for (int i = 0; i < n; i++) {
            // Remove the top node 
            TreeNode* node = q.front();
            q.pop();

            // Checck if this is a last node in the level, if so then it is
            // visible from right side
            if (i == n - 1) {
                // Push the node value to visible list
                visible.push_back(node->val);
            }

            // Push the children to queue
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    return visible;
}

/*
 * Approach is DFS solution, where we have a temp variable level and wwill
 * traverse first right and then left
*/
void dfs(TreeNode* root, int level, vector<int>& res) {
    // Check if there is a tree or not
    if (!root) {
        // Return an empty vector
        return;
    }

    // Check if level matches the element at result
    if (res.size() == level) {
        res.push_back(root->val);
    }

    // Traverse the right subtree
    dfs(root->right, level + 1, res);
    // Traverse the left subtree
    dfs(root->left, level + 1, res);

    return;
}

vector<int> rightSideView(TreeNode* root) {
    // vector to store all visible node values from right side
    vector<int> visible;

    dfs(root, 0, visible);

    return visible;
}

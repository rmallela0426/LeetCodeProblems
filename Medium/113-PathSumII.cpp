
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 113: Path Sum II
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where each path's sum equals targetSum.
 *
 * A leaf is a node with no children.
 *
 * Example 1:
 *                  5
 *               /     \
 *              4       8
 *            /        /  \
 *           11      13     4
 *          /  \           / \
 *         7    2         5   1
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 *
 * Example 2:
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 *
 * Example 3:
 * Input: root = [1,2], targetSum = 0
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
*/
/*
 * Approach followed is the DFS + Backtracking method
*/
void dfsBacktrack(TreeNode* root, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
    // Check if the root is NULL
    if (!root) {
        // Children of leaf node
        return;
    }

    // Push the current node val to current path array
    currentPath.push_back(root->val);

    // Check if it is a leaf node and current node val is equal to targeSum
    if (!root->left && !root->right && root->val == targetSum) {
        // we are at leaf node and the targetSum is equal to path sum,
        //push the current path to result
        result.push_back(currentPath);
    }
    else {
        // traverse the left subtree and right subtree by reducing the target sum
        dfsBacktrack(root->left, targetSum - root->val, currentPath, result);
        dfsBacktrack(root->right, targetSum - root->val, currentPath, result);
    }

    // backtrack, remove the inserted element
    currentPath.pop_back();

    return;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    // variable to store result
    vector<vector<int>> result;

    // vector to store the current path values
    vector<int> currPath;

    dfsBacktrack(root, targetSum, currPath, result);

    return result;
}

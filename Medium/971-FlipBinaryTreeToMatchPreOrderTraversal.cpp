
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 971: Flip Binary Tree To Match PreOrder Traversal
 *
 * You are given the root of a binary tree with n nodes, where each node is uniquely assigned
 * a value from 1 to n. You are also given a sequence of n values voyage, which is the desired
 * pre-order traversal of the binary tree.
 *
 * Any node in the binary tree can be flipped by swapping its left and right subtrees. For example,
 * flipping node 1 will have the following effect:
 * Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.
 *
 * Return a list of the values of all flipped nodes. You may return the answer in any order. If it
 * is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return
 * the list [-1].
 *
 * Example 1:
 * Input: root = [1,2], voyage = [2,1]
 * Output: [-1]
 * Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.
 *
 * Example 2:
 * Input: root = [1,2,3], voyage = [1,3,2]
 * Output: [1]
 * Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal matches voyage.
 *
 * Example 3:
 * Input: root = [1,2,3], voyage = [1,2,3]
 * Output: []
 * Explanation: The tree's pre-order traversal already matches voyage, so no nodes need to be flipped.
 *
 * Constraints:
 * The number of nodes in the tree is n.
 * n == voyage.length
 * 1 <= n <= 100
 * 1 <= Node.val, voyage[i] <= n
 * All the values in the tree are unique.
 * All the values in voyage are unique.
*/
/*
 * Approach used is DFS.
*/
bool dfs(TreeNode* node, vector<int>& v, int& idx, vector<int>& res) {
    if (node == NULL) {
        // If the node is empty, then return true
        return true;
    }

    if (node->val != v[idx++]) {
        // If the node value is not matching the voyage, then return false
        return false;
    }

    // Check to see whether if nodes need to be flipped ie.., if the left
    // node value is not equal to voyage value
    if (node->left != NULL && node->left->val != v[idx]) {
        res.push_back(node->val);
        return dfs(node->right, v, idx, res) && dfs(node->left, v, idx, res);
    }

    // If the value matches then proceed with regular dfs
    return dfs(node->left, v, idx, res) && dfs(node->right, v, idx, res);
}

vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> result;
    int idx = 0;

    return dfs(root, voyage, idx, result) ? result : vector<int>({ -1 });
}

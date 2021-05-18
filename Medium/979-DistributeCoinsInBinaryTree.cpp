
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 979: Distribute Coins In Binary Tree
 *
 * You are given the root of a binary tree with n nodes where each node in the tree
 * has node.val coins and there are n coins total.
 * In one move, we may choose two adjacent nodes and move one coin from one node to
 * another. (A move may be from parent to child, or from child to parent.)
 * Return the number of moves required to make every node have exactly one coin.
 *
 * Example 1:
 *               3
 *            /    \
 *           /      \
 *          0        0
 *
 * Input: root = [3,0,0]
 * Output: 2
 * Explanation: From the root of the tree, we move one coin to its left child, and one
 * coin to its right child.
 *
 * Example 2:
 *               0
 *            /     \
 *           /       \
 *          3         0
 *
 * Input: root = [0,3,0]
 * Output: 3
 * Explanation: From the left child of the root, we move two coins to the root [taking two
 * moves].  Then, we move one coin from the root of the tree to the right child.
 *
 * Example 3:
 * Input: root = [1,0,2]
 * Output: 2
 *
 * Example 4:
 *               1
 *             /   \
 *            0     0
 *             \
 *              3
 * Input: root = [1,0,0,null,3]
 * Output: 4
 *
 * Constraints:
 * The number of nodes in the tree is n.
 * 1 <= n <= 100
 * 0 <= Node.val <= n
 * The sum of Node.val is n.
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
class Solution {
    /*
     * Approach followed is PostOrder DFS, where the traversal
     * goes from leaf nodes. If the leaf node has 0 coins, then
     * return -1 else number coins -1
     * BaseCase:
     *  . If current node is NULL, then there won't any coins
     *    return 0
    */
    int postOrderDfs(TreeNode* root, int& ans) {
        // Check if the node is NULL
        if (root == NULL) {
            // Node is null there won't be any coins
            return 0;
        }

        // Traverse the left node
        int L = postOrderDfs(root->left, ans);
        // Traverse the right node
        int R = postOrderDfs(root->right, ans);

        // Calculate the number of moves that are required to
        // make every node having one coin
        ans += abs(L) + abs(R);

        // Return the remaining coins by placing 1 coin at the
        // current node
        return root->val + L + R - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;

        postOrderDfs(root, ans);

        return ans;
    }
};

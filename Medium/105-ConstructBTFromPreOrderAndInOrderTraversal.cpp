
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 105: Construct Binary Tree From PreOrder and InOrder Traversal
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal
 * of a binary tree and inorder is the inorder traversal of the same tree, construct and
 * return the binary tree.
 *
 * Example 1:
 *               3
 *            /    \
 *           9     20
 *                /  \
 *               15   7
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 * Example 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 * Constraints:
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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
     * PreOrder Traversal - Root -> Left -> Right - will get the root which is at index 0
     * InOrder Traversal - Left -> Root -> Right - if we know the position of root, then left of
     *                     left of the root index will be left subtree and right will subtree of
     *                     the root
     * Eg: pre - [3, 9, 20, 15, 7]
     *           root
     *      in - [9, 3, 15, 20, 7]
     *           --     ---------
     *        left tree    right tree
     * Approach is go with recursive solution starting from root
    */
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int left, int right) {
        // Check if are we are done with all elements
        if (left > right) {
            return NULL;
        }

        // Create the root node
        TreeNode* node = new TreeNode(preorder[preIndex++]);

        // calculate the position of current root value in inorder array
        int pos = std::find(inorder.begin(), inorder.end(), node->val) - inorder.begin();

        // create the left and right subtree based on index from inorder
        node->left = buildTree(preorder, inorder, preIndex, left, pos - 1);
        node->right = buildTree(preorder, inorder, preIndex, pos + 1, right);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // PreOrder Index from where the root starts
        int preIndex = 0;

        return buildTree(preorder, inorder, preIndex, 0, preorder.size() - 1);

    }
};

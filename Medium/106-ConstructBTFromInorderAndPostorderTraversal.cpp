
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 106: Construct BinaryTree From Inorder and Postorder Traversal arrays
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder traversal
 * of a binary tree and postorder is the postorder traversal of the same tree, construct
 * and return the binary tree.
 *
 * Example 1:
 *               3
 *            /    \
 *           9     20
 *                /  \
 *               15   7
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 *
 * Example 2:
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 *
 * Constraints:
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
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
     * PostOrder Traversal - Left -> Right->Right - will get the root which is at index length - 2
     * InOrder Traversal - Left -> Root -> Right - if we know the position of root, then left of
     *                     left of the root index will be left subtree and right will subtree of
     *                     the root
     * Eg: post - [9, 15, 7, 20, 3]
     *                           root
     *      in - [9, 3, 15, 20, 7]
     *           --     ---------
     *        left tree    right tree
     * Approach is go with recursive solution starting from root
    */
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int left, int right) {
        // Check if are we are done with all elements
        if (left > right) {
            return NULL;
        }

        // Create the root node
        TreeNode* node = new TreeNode(postorder[postIndex--]);

        // calculate the position of current root value in inorder array
        int pos = std::find(inorder.begin(), inorder.end(), node->val) - inorder.begin();

        // create the right and left subtree based on index from inorder
        node->right = buildTree(inorder, postorder, postIndex, pos + 1, right);
        node->left = buildTree(inorder, postorder, postIndex, left, pos - 1);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // PostOrder Index from where the root starts
        int postIndex = postorder.size() - 1;

        return buildTree(inorder, postorder, postIndex, 0, postorder.size() - 1);
    }
};
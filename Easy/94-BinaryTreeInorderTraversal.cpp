
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 94: Binary Tree InOrder Traversal
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 * Input: root = []
 * Output: []
 *
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 *
 * Example 4:
 * Input: root = [1,2]
 * Output: [2,1]
 *
 * Example 5:
 * Input: root = [1,null,2]
 * Output: [1,2]
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
*/
/*
 * Inorder Traversal is Left, Root, Right
 *
 * Recursive Approach where we traverse through the left subtree and
 * once child is reached, print the current node and traverse to right
 *
 * Iterative approach is to use a stack and current variables
*/

// Recursive approach
void inorder_r(TreeNode* root, vector<int>& res) {
    // Check if the root is NULL
    if (root == NULL) {
        return;
    }

    // Traverse Left subtree
    inorder_r(root->left, res);

    // Push the root value to result vector
    res.push_back(root->val);

    // Traverse right subtree
    inorder_r(root->right, res);

    return;
}

// Iterative approach
void inorder_i(TreeNode* root, vector<int>& result) {
    // Check if the root is NULL
    if (root == NULL) {
        return;
    }

    // stack variable to the nodes
    stack<TreeNode*> st;

    // Initialize the curr variable to root
    TreeNode* curr = root;

    while (!st.empty() || curr) {
        // Check if the current is null or not
        if (curr) {
            // Curr is not NULL, push it to stack and
            // move to left subtree
            st.push(curr);
            // Move to left subtree
            curr = curr->left;
        }
        else {
            // Curr is NULL ie.., reached the child of leaf node
            // Retrieve the leaf node from stack
            curr = st.top();
            st.pop();

            // Push the root value to the result
            result.push_back(curr->val);

            // Now procced to right subtree
            curr = curr->right;
        }
    }

    return;
}

vector<int> inorderTraversal(TreeNode* root) {
    // vector to store the result
    vector<int> result;

    //inorder_r(root, result);
    inorder_i(root, result);

    return result;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 114: Flatten Binary Tree To Linked List
 * Given the root of a binary tree, flatten the tree into a "linked list":
 * The "linked list" should use the same TreeNode class where the right
 * child pointer points to the next node in the list and the left child
 * pointer is always null.
 * The "linked list" should be in the same order as a pre-order traversal
 * of the binary tree.
 *
 * Example 1:
 *             1
 *           /   \
 *          2     5      => 1->2->3->4->5->6
 *        /  \     \
 *       3    4     6
 * Input: root = [1,2,5,3,4,null,6]
 * Output: [1,null,2,null,3,null,4,null,5,null,6]
 *
 * Example 2:
 * Input: root = []
 * Output: []
 *
 * Example 3:
 * Input: root = [0]
 * Output: [0]
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 * Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
// Approach followed is using the stack
void flatten(TreeNode* root) {
    // Check if the Binary tree is NULL
    if (root == NULL) {
        // Binary tree is empty, return
        return;
    }

    stack<TreeNode*> st;
    // Push the root to stack
    st.push(root);

    // Loop while the stack is not empty
    while (!st.empty()) {
        // Pop the Top element
        TreeNode* curr = st.top();
        st.pop();

        // Push the right child to stack
        if (curr->right) {
            st.push(curr->right);
        }

        // Push the left child to stack
        if (curr->left) {
            st.push(curr->left);
        }

        if (!st.empty()) {
            curr->right = st.top();
        }

        curr->left = NULL;
    }

    return;
}

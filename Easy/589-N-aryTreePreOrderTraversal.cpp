
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 589: N-ary Tree PreOrder Traversal
 *
 * Given the root of an n-ary tree, return the preorder traversal of
 * its nodes' values.
 * Nary-Tree input serialization is represented in their level order
 * traversal. Each group of children is separated by the null value
 * (See examples)
 *
 * Example 1:
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [1,3,5,6,2,4]
 *
 * Example 2:
 * Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 104].
 * 0 <= Node.val <= 104
 * The height of the n-ary tree is less than or equal to 1000.
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
*/
/*
 * Approach is recursive solution
 * Pre Order Traversal is
 *     Root  Left  Right
*/
void helper(Node* root, vector<int>& res) {
    // Push the current root value to result
    res.push_back(root->val);

    // Loop all childrens of the tree
    for (Node* node : root->children) {
        helper(node, res);
    }
}

vector<int> preorder(Node* root) {
    // Vector to store teh result
    vector<int> res;

    // Check if the root is NULL
    if (!root) {
        // Root is NULL return res
        return res;
    }

    // Helper function that can recursively call
    // traverse the list
    helper(root, res);

    return res;
}
/*
 * Iterative Approach is to use the stack, pushing
 * the top of stack to result and push all the
 * children in reverse order.
*/
vector<int> preorder(Node* root) {
    // Vector to store teh result
    vector<int> res;

    // Check if the root is NULL
    if (!root) {
        // Root is NULL return res
        return res;
    }

    // Stack to store the nodes, childrens
    stack<Node*> st;
    // Push the root node to stack
    st.push(root);

    // Loop while the stack is not empty
    while (!st.empty()) {
        // Retrieve the node at the top of stack
        Node* top = st.top();
        // Remove the node from stack
        st.pop();

        // Push the current node value to result
        res.push_back(top->val);

        // Push all the children in reverse order to stack
        for (auto it = top->children.rbegin(); it != top->children.rend(); it++) {
            st.push(*it);
        }
    }

    return res;
}

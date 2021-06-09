
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 116: Populating Next Pointers In Each Node
 *
 * You are given a perfect binary tree where all leaves are on the same level, and every parent
 * has two children. The binary tree has the following definition:
 *
 * struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no next right node, the
 * next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Follow up:
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not count as extra space
 * for this problem.
 *
 * Example 1:
 *          1                              1
 *       /     \                        /     \
 *      2       3                      2  ->    3
 *    /  \     /  \                  /  \     /   \ 
 *   4    5   6    7                4 -> 5 -> 6 -> 7  
 *
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function should populate each
 * next pointer to point to its next right node, just like in Figure B. The serialized output is in
 * level order as connected by the next pointers, with '#' signifying the end of each level.
*/
/*
 * Approach followed is a DFS solution where at each node,
 * Will try to fill the childrens next pointers
 *
 * Fill the left childs next pointer to right child and for
 * right child next pointer check if the current node next
 * pointer is NULL or not. If NULL assign the right child
 * next pointer to NULL.
 * Else it will point to current node next of left child.
 *  Eg:           10
 *              /    \
 *             2  ->  3
 *            / \    / \
 *           4   5  6   7
 *
 * In above example, if we are at node 10, assign the childs
 * left next ptr to right child
 * and for right child it should be NULL as the node 10 next
 * ptr is NULL.
 * If we are at node 2, the left child(node 4) next ptr points
 * to right child(node 5) and  for right child, as current node
 * next ptr is not NULL, retrieve the left child of node 3 and
 * assign.
*/
void dfs(Node* root) {
    // check if the root is NULL or not
    if (!root) {
        return;
    }

    // Update the next pointers of its children
    if (root->left) {
        // Left child is not NULL and as the BT is perfect, right
        // child will also will be available
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : NULL;
    }

    // Traverse the left binary tree
    dfs(root->left);
    // Traverse the right binary tree
    dfs(root->right);

    return;
}

Node* connect(Node* root) {
    dfs(root);

    return root;
}

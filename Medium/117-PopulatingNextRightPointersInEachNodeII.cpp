
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 117: Populating Next Right Pointers In Each Node II
 *
 * Given a binary tree
 * struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no next right node,
 * the next pointer should be set to NULL.
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
 *    /  \        \                  /  \         \
 *   4    5        7                4 -> 5 ----->  7
 *
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * 
 * Explanation: Given the above binary tree (Figure A), your function should populate each next pointer
 * to point to its next right node, just like in Figure B. The serialized output is in level order as
 * connected by the next pointers, with '#' signifying the end of each level.
 *
 * Constraints:
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
*/
Node* connect(Node* root) {
    // check if the root is NULL or not
    if (!root) {
        return NULL;
    }

    // Queue to store the current level nodes
    queue<Node*> q;
    // Push the root to queue
    q.push(root);

    // Loop until we are done with all nodes
    while (!q.empty()) {
        // Current the size of the current level
        int size = q.size();
        // Stores the prev node in the current level
        Node* prev = NULL;

        // Loop all the nodes in the level
        while (size-- > 0) {
            // Get the latest node from the queue
            Node* curr = q.front();
            q.pop();

            // push the left node to queue, if present
            if (curr->left) {
                q.push(curr->left);
            }

            // push the right node to queue, if present
            if (curr->right) {
                q.push(curr->right);
            }

            // checkk if the prev node is NULL or not
            if (prev) {
                // Assign the current node to prev next
                prev->next = curr;
            }

            // save the curr node to prev
            prev = curr;
        }
    }

    return root;
}

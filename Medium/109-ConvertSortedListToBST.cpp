
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 109: Convert Sorted List To Binary Search Tree
 *
 * Given the head of a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which
 * the depth of the two subtrees of every node never differ by more than 1.
 *
 *  -10 -> -3 -> 0 -> 5 -> 9
 *            |
 *            V
 *            0
 *          /   \
 *        -3     9
 *        /     /
 *     -10     5
 *
 * Example 1:
 * Input: head = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown
 * height balanced BST.
 *
 * Example 2:
 * Input: head = []
 * Output: []
 *
 * Example 3:
 * Input: head = [0]
 * Output: [0]
 *
 * Example 4:
 * Input: head = [1,3]
 * Output: [3,1]
 *
 * Constraints:
 * The number of nodes in head is in the range [0, 2 * 104].
 * -10^5 <= Node.val <= 10^5
*/
/* Approach used is binary search and dfs where the mid is
 * calculated where all the elements to left are smaller
 * than mid and all elements to right are larger than mid.
 * Perform a DFS on the left and right of the elements mid
*/

TreeNode* dfs(vector<int>& nums, int left, int right) {
    // Check whether all elements are done
    if (left > right) {
        // Done with all the elements, return null
        return NULL;
    }

    // Calculate the mid from the left and right
    int mid = left + (right - left) / 2;

    // Generate the head of the node
    TreeNode* head = new TreeNode(nums[mid]);

    // Left side elements of the mid are left children of the
    // balanced tree
    head->left = dfs(nums, left, mid - 1);
    // Right side elements of the mid are right children of the
    // balanced tree
    head->right = dfs(nums, mid + 1, right);

    return head;
}
TreeNode* sortedListToBST(ListNode* head) {
    // Copy the single Linked List to a vector
    vector<int> nums;
    // Loop the linked list and copy all the values to a vector
    for (; head != NULL; head = head->next) {
        nums.push_back(head->val);
    }

    return dfs(nums, 0, nums.size() - 1);
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 108 : Converted Sorted Array To Binary Search Tree
 *
 * Given an integer array nums where the elements are sorted in ascending order,
 * convert it to a height-balanced binary search tree.
 * A height-balanced binary tree is a binary tree in which the depth of the two
 * subtrees of every node never differs by more than one.
 *
 * Example 1:
 * Input: nums = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: [0,-10,5,null,-3,null,9] is also accepted:
 *
 * Example 2:
 * Input: nums = [1,3]
 * Output: [3,1]
 * Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums is sorted in a strictly increasing order.
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

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
}

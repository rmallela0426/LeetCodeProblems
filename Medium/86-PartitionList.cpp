
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 86: Partition List
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example 1:
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 *
 * Example 2:
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 *
 * Constraints:
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
*/
/*
 * Approach is using 2 pointers lower, greater
*/
ListNode* partition(ListNode* head, int x) {
    if (head == NULL) {
        return head;
    }

    // Initialize the lower and greater Nodes to a dummy
    ListNode* lower_head = new ListNode(0);
    ListNode* lower = lower_head;
    ListNode* greater_head = new ListNode(0);
    ListNode* greater = greater_head;

    // Loop until all nodes are done
    while (head != NULL) {
        // Check if the value of current list is less than x
        if (head->val < x) {
            // Value less than x, insert it at next of lower list
            lower->next = head;
            lower = lower->next;
        }
        else {
            // Current node values is >= x, insert it at next of greater list
            greater->next = head;
            greater = greater->next;
        }

        head = head->next;
    }

    // Greater pointer should point to the last node in the list
    greater->next = NULL;

    // Combine both lower and higher to form a single list
    lower->next = greater_head->next;

    return lower_head->next;
}

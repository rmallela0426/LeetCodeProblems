
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 141: Linked List Cycle
 *
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by
 * continuously following the next pointer. Internally, pos is used to denote the index of the node
 * that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 *
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 *
 * Example 1:
 *      3 -> 2 -> 0 -> -4 --
 *           |              |
 *           ----------------
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
 *
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
 *
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *
 * Constraints:
 * The number of the nodes in the list is in the range [0, 104].
 * -105 <= Node.val <= 105
 * pos is -1 or a valid index in the linked-list.
 *
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 * 
*/
/*
 * Approach used is 2 pointer solution where one pointer
 * moves 2 nodes at once ie..., fastptr, another pointer
 * moves 1 node at once i.e..., slowptr. If there is a
 * cycle at some point the fast ptr and slow ptr are equal.
*/
bool hasCycle(ListNode* head) {
    // Check if the list is valid
    if (!head) {
        // The list is NUll,
        return false;
    }

    // 2 pointers initialized to head
    ListNode* fastptr = head;
    ListNode* slowptr = head;

    // Traverse the list
    while (fastptr && fastptr->next) {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;

        // check if fastptr & slowptr are equal
        if (fastptr == slowptr) {
            return true;
        }
    }

    return false;
}

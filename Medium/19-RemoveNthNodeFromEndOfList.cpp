
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 19: Remove Nth Node from End of List
 *
 * Given the head of a linked list, remove the nth node from the end of the
 * list and return its head.
 *
 * Follow up: Could you do this in one pass?
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 * Constraints:
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
*/
/* Approach is to use 2 pointers, on pointers moves delay n steps,
 * so when the first ptr reaches the end, then second  will be at
 * n steps back. Once we get the nth node from last then copy the
 * next node to current and delete the next node
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
        // Head is null, return NULL
        return NULL;
    }

    ListNode* fast_ptr = head;
    // Holds the nth node from last
    ListNode* nthNode = head;
    //int size = 1;

    // Traverse all the nodes, Once it reaches end the
    // nthNode holds the nth node from last
    // Travesing till the last but one node, that will
    // helps to handle the case of deleting the last node
    while (fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next;
        nthNode = n-- > 0 ? nthNode : nthNode->next;
    }

    // If the nthNode is same as head then return the head->next
    if (nthNode != head || n == 0) {
        // Delete the next node
        ListNode* temp = nthNode->next;
        nthNode->next = nthNode->next->next;
        delete temp;
    }
    else {
        // Update head with head->next, delete nthNode
        head = head->next;
        delete nthNode;
    }

    return head;
}

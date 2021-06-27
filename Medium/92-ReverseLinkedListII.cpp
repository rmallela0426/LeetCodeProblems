
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 92: Reverse Linked List II
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 * Example 1:
 *      1 -> 2 -> 3-> 4-> 5
 *             ||
 *              V
 *      1 -> 4 -> 3 -> 2 -> 5
 *
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 * Example 2:
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 * Constraints:
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 * Follow up: Could you do it in one pass?
*/

ListNode* reverseBetween(ListNode* head, int left, int right) {
    // Base case if root is NULL
    if (!head) {
        return NULL;
    }

    // Variable to store the current node
    ListNode* curr = head;
    // variable to store the previous node that helps to link after
    // reversing.
    ListNode* fprev = NULL;

    // Counter that tells depth of the current node that is executing        
    int count = 0;

    // Traverse or skip all the nodes till the left
    while (curr && ++count < left) {
        // save the prev pointer
        fprev = curr;
        // procced to next node
        curr = curr->next;
    }

    // Temp variable to store the curr node that help to link the next
    // node after reversing
    ListNode* temp = curr;
    // Temporary variables in order to perform the revers of the list
    ListNode* prev = NULL;
    ListNode* next;

    // Traverse all the node till right and perform the reverse operation
    while (curr && count <= right) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Link the next pointer with the pev node
    temp->next = next;

    // Update the head or prev accordingly.
    (fprev ? fprev->next : head) = prev;

    // Return head
    return head;
}

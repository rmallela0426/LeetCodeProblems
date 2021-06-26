
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 203: Remove Linked List Elements
 *
 * Given the head of a linked list and an integer val, remove all the nodes of the linked
 * list that has Node.val == val, and return the new head.
 *
 * Example 1:
 *       1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
 *                   ||
 *                    V
 *         1-> 2 -> 3-> 4 -> 5
 *
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
 * Example 2:
 * Input: head = [], val = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *
 * Constraints:
 * The number of nodes in the list is in the range [0, 104].
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
*/
ListNode* removeElements(ListNode* head, int val) {
    // Base case if the head is NULL
    if (!head) {
        // There is not linked list
        return NULL;
    }

    // Check whether the head has the required element
    while (head && head->val == val) {
        // Node that needs to be removed is the head
        // assign the next node to head
        head = head->next;
    }


    // Check if the head is NULL
    if (!head) {
        return NULL;
    }

    // variable to store the curr head
    ListNode* curr = head;

    // Traverse the loop by check the next node
    while (curr->next) {
        // Check if the next node needs to be removed
        if (curr->next->val == val) {
            // current node needs to be deleted
            curr->next = curr->next->next;
        }
        else {
            curr = curr->next;
        }

    }

    // return the head
    return head;
}

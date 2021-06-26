
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 206: Reverse Linked List
 *
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 *
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: [2,1]
 *
 * Example 3:
 * Input: head = []
 * Output: []
 *
 * Constraints:
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 * Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
/*
 * Approach followed is to traverse through the list
 * and while parsing update the list with the prev node
 *
 * Pseudo code:
 *  . Initialize prev and next nodes to NULL, curr pointing to head
 *  . Traverse while we read end of list
 *  . Update the next node with curr->next
 *  . Update the next ptr of Curr to prev
 *  . Update the prev to curr
 *  . Update curr with next
*/
ListNode* reverseList(ListNode* head) {
    // Check whether list is empty
    if (!head) {
        // Empty List, return NULL;
        return NULL;
    }

    // Initialize curr to head
    ListNode* curr = head;
    // Initialize prev and Next to NULL
    ListNode* prev = NULL;
    ListNode* next;

    // Traverse till we reach end of the list
    while (curr) {
        // save the next ptr of the current node next
        next = curr->next;
        // Update next ptr of curr with prev node
        curr->next = prev;
        // Update the prev and curr pointers accordingly
        prev = curr;
        curr = next;
    }

    // As prev holds the node, return that
    return prev;
}

// Recursive Solution
ListNode* reverseList(ListNode* head, ListNode* prev = NULL) {
    // Check if the list is empty
    if (!head) {
        // Empty List, return NULL;
        return NULL;
    }

    // Copy the next pointer and update next with prev
    ListNode* next = head->next;
    head->next = prev;

    // If the current node is last node, then return last node
    // else continue to reverse the nodes
    return next ? reverseList(next, head) : head;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1721: Swapping Nodes in a Linked List
 *
 * You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of
 * the kth node from the beginning and the kth node from the end
 * (the list is 1-indexed).
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [1,4,3,2,5]
 *
 * Example 2:
 * Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * Output: [7,9,6,6,8,7,3,0,9,5]
 *
 * Example 3:
 * Input: head = [1], k = 1
 * Output: [1]
 *
 * Example 4:
 * Input: head = [1,2], k = 1
 * Output: [2,1]
 *
 * Constraints:
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 105
 * 0 <= Node.val <= 100
*/
/*
 * Approach followed is a two pointer approach
 * Move first pointer by k, store the k-1 which is first_k_ptr
 * Now move both the pointers and when the first pointer reaches
 * the end of the list the second pointer will be at the kth node
 * from the end.
 * Swap the contents of first_ptr and second_ptr
*/
ListNode* swapNodes(ListNode* head, int k) {
    if (head == NULL) {
        // If head is NULL, there is no list
        return head;
    }

    ListNode* first_ptr = NULL;
    ListNode* curr_ptr = head;

    // Move the curr_ptr by k and store k-1 node in first_ptr
    while (k > 0) {
        if (--k == 0)
            first_ptr = curr_ptr;
        curr_ptr = curr_ptr->next;
    }

    // Assign the sec_ptr with head
    ListNode* sec_ptr = head;

    // Move the curr_ptr to the end of the list so that the sec_ptr
    // is the kth node
    while (curr_ptr != NULL) {
        curr_ptr = curr_ptr->next;
        sec_ptr = sec_ptr->next;
    }

    if (first_ptr != NULL && sec_ptr != NULL) {
        int temp = first_ptr->val;
        first_ptr->val = sec_ptr->val;
        sec_ptr->val = temp;
    }

    return head;
}


/*
 * LeetCode 445: Add Numbers II
 *
 * You are given two non-empty linked lists representing two non-negative integers. The most
 * significant digit comes first and each of their nodes contains a single digit. Add the two
 * numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 *
 * Example 2:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 *
 * Example 3:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Constraints:
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have leading zeros.
 *
 * Follow up: Could you solve it without reversing the input lists?
*/
/*
 * Approach followed is a DFS and stack where we traverse till end of the
 * list nodes and add accordingly
 *
 * Base case:xt is not NULL, then we are not at leaf node, perform a dfs  till we are
 *     at leaf n
 *   . If l1->neode.
 *   . Once we are at leaf node, then add the element from the current node, stack value
 *     and remove the node value from stack.
*/
int dfs(ListNode* p, stack<int>& st, ListNode*& head) {
    // Initialize the carry
    int sum = 0;

    // Check whether this is not a leaf node
    if (p->next) {
        // perform a dfs
        sum = dfs(p->next, st, head);
    }

    sum = p->val + sum;
    if (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    // Create a new node with sum
    ListNode* node = new ListNode(sum % 10);
    // Update the head
    node->next = head;
    head = node;

    return sum / 10;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Variable to store the head node for result
    ListNode* head = NULL;

    // Stack to store the list l2
    stack<int> st;

    // Push all the values of l2 to stack
    while (l2) {
        st.push(l2->val);
        l2 = l2->next;
    }

    // Call the dfs method which will return carry if any after sum of all nodes
    int carry = dfs(l1, st, head);

    // Check if there is any carry
    while (carry || !st.empty()) {
        if (!st.empty()) {
            carry += st.top();
            st.pop();
        }
        // There is a carry that needs to be added
        ListNode* node = new ListNode(carry % 10);
        // Update the head
        node->next = head;
        head = node;
        carry = carry / 10;
    }

    return head;
}

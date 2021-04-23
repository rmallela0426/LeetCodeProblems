
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1290: Convert Binary Number In a Linked List
 *
 * Given head which is a reference node to a singly-linked list. The value of each node
 * in the linked list is either 0 or 1. The linked list holds the binary representation
 * of a number.
 * Return the decimal value of the number in the linked list.
 *
 * Example 1:
 * Input: head = [1,0,1]
 * Output: 5
 * Explanation: (101) in base 2 = (5) in base 10
 *
 * Example 2:
 * Input: head = [0]
 * Output: 0
 *
 * Example 3:
 * Input: head = [1]
 * Output: 1
 *
 * Example 4:
 * Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
 * Output: 18880
 *
 * Example 5:
 * Input: head = [0,0]
 * Output: 0
 *
 * Constraints:
 *   The Linked List is not empty.
 *   Number of nodes will not exceed 30.
 *   Each node's value is either 0 or 1.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
     * Approach is to traverse the list and use left shift and
     * or operation for getting the decimal number
     *  Eg: 101 => 1*2^2 + 0*2^1 + 1*2^0
    */
    int getDecimalValue(ListNode* head) {
        // decimal number
        int dec = 0;

        // Traverse the loop till it reaches end
        while (head) {
            // Left shift and perform an or operation to get
            // the decimal value
            dec = dec << 1 | head->val;
            head = head->next;
        }

        // return the decimal value
        return dec;
    }
};

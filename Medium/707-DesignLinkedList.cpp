
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 707: Desingn Linked List
 *
 * Design your implementation of the linked list. You can choose to use a singly
 * or doubly linked list.
 * A node in a singly linked list should have two attributes: val and next. val
 * is the value of the current node, and next is a pointer/reference to the next
 * node.
 * If you want to use the doubly linked list, you will need one more attribute
 * prev to indicate the previous node in the linked list. Assume all nodes in the
 * linked list are 0-indexed.
 *
 * Implement the MyLinkedList class:
 * MyLinkedList() -  Initializes the MyLinkedList object.
 * int get(int index) - Get the value of the indexth node in the linked list. If
 * the index is invalid, return -1.
 * void addAtHead(int val) - Add a node of value val before the first element of
 * the linked list. After the insertion, the new node will be the first node of
 * the linked list.
 * void addAtTail(int val) - Append a node of value val as the last element of the
 * linked list.
 * void addAtIndex(int index, int val) - Add a node of value val before the indexth
 * node in the linked list. If index equals the length of the linked list, the node
 * will be appended to the end of the linked list. If index is greater than the
 * length, the node will not be inserted.
 * void deleteAtIndex(int index) - Delete the indexth node in the linked list, if
 * the index is valid.
 *
 * Example 1:
 * Input
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * Output
 * [null, null, null, null, 2, null, 3]
 *
 * Explanation
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
 * myLinkedList.get(1);              // return 2
 * myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
 * myLinkedList.get(1);              // return 3
 *
 * Constraints:
 * 0 <= index, val <= 1000
 * Please do not use the built-in LinkedList library.
 * At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/

class MyLinkedList {
private:
    // Struct that is a linked list
    struct TreeNode {
        int val;
        TreeNode* next;

        TreeNode(int value)
            : val(value)
            , next(NULL) {
        }
    };

    // Pointers that stores the head and tail of the
    // single linked list
    TreeNode* head;
    TreeNode* tail;

    // count to know the number of nodes available
    int nextNodeIdx;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        nextNodeIdx = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // Check if the nodes are available
        if (nextNodeIdx <= index) {
            // There are less nodes than the index
            return -1;
        }

        TreeNode* temp = head;
        while (index-- > 0) {
            temp = temp->next;
        }

        return temp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        TreeNode* node = new TreeNode(val);

        node->next = head;
        head = node;
        nextNodeIdx += 1;

        if (tail == NULL) {
            tail = head;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        TreeNode* node = new TreeNode(val);

        if (tail != NULL) {
            tail->next = node;
        }

        tail = node;
        head = head == NULL ? node : head;
        nextNodeIdx += 1;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (nextNodeIdx < index) {
            return;
        }

        TreeNode* node = new TreeNode(val);

        if (index == 0) {
            node->next = head;
            head = node;
            tail = tail == NULL ? node : tail;
        }
        else if (nextNodeIdx == index) {
            tail->next = node;
            tail = node;
        }
        else {
            TreeNode* temp = head;
            while (--index > 0) {
                temp = temp->next;
            }

            node->next = temp->next;
            temp->next = node;
        }

        nextNodeIdx += 1;

        return;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (nextNodeIdx <= index) {
            return;
        }

        if (index == 0) {
            TreeNode* temp = head->next;

            tail = tail == head ? temp : tail;
            delete head;
            head = temp;
        }
        else {
            TreeNode* temp = head;
            while (--index > 0) {
                temp = temp->next;
            }

            TreeNode* del = temp->next;
            temp->next = del->next;

            if (tail == del) {
                tail = temp;
            }

            delete del;
        }
        nextNodeIdx -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

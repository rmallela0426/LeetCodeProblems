

/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 155: Min Stack
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * Implement the MinStack class:
 *  . MinStack() initializes the stack object.
 *  . void push(val) pushes the element val onto the stack.
 *  . void pop() removes the element on the top of the stack.
 *  . int top() gets the top element of the stack.
 *  . int getMin() retrieves the minimum element in the stack.
 *
 * Example 1:
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * Output
 * [null,null,null,null,-3,null,0,-2]
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 *
 * Constraints:
 * -2^31 <= val <= 2^31 - 1
 * Methods pop, top and getMin operations will always be called on non-empty stacks.
 * At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
class MinStack {
    // Node structure
    struct Node {
        // Holds the value
        int val;
        // Holds the min value till this node
        int minval;
        // Link that store the connection to next node
        Node* link;
    };

    // Pointer that holds the top of the stack
    Node* root;

public:
    /** initialize your data structure here. */
    MinStack() {
        // Initialize the top to NULL and minValue to Integer Max
        root = NULL;
    }

    void push(int val) {
        // Create a temp node and update the top
        Node* temp = new Node();
        // Check if the created node is NULL or not
        if (!temp) {
            // Memory is full or the stack is full.... return NULL
            return;
        }

        // Update the value, link and top
        temp->val = val;
        // Update the min value till the current node
        temp->minval = min(val, root ? root->minval : INT_MAX);
        temp->link = root;
        root = temp;

        return;
    }

    void pop() {
        // Check whether the top is NULL or not
        if (!root) {
            // Stack is empty
            return;
        }

        // Retrieve the top element from stack
        Node* temp = root;
        root = temp->link;

        // Delete the node
        delete temp;
        temp = NULL;

        return;
    }

    int top() {
        // As this method will always be called on non-empty stacks
        // return the top val
        return root->val;
    }

    int getMin() {
        // Return the min element
        return root->minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

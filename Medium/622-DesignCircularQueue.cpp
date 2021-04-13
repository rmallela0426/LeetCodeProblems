
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 622: Design Circular Queue
 *
 * Design your implementation of the circular queue. The circular queue is a
 * linear data structure in which the operations are performed based on FIFO
 * (First In First Out) principle and the last position is connected back to
 * the first position to make a circle. It is also called "Ring Buffer".
 *
 * One of the benefits of the circular queue is that we can make use of the
 * spaces in front of the queue. In a normal queue, once the queue becomes full,
 * we cannot insert the next element even if there is a space in front of the
 * queue. But using the circular queue, we can use the space to store new values.
 *
 * Implementation the MyCircularQueue class:
 * . MyCircularQueue(k) Initializes the object with the size of the queue to be k.
 * . int Front() Gets the front item from the queue. If queue is empty, return -1.
 * . int Rear() Gets the last item from the queue. If queue is empty, return -1.
 * . boolean enQueue(int value) Inserts an element into the circular queue. Return
 *   true if the operation is successful.
 * . boolean deQueue() Deletes an element from the circular queue. Return true if
 *   the operation is successful.
 * . boolean isEmpty() Checks whether the circular queue is empty or not.
 * . boolean isFull() Checks whether the circular queue is full or not.
 *
 * Example 1:
 * Input
 * ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull",
 *  "deQueue", "enQueue", "Rear"]
 * [[3], [1], [2], [3], [4], [], [], [], [4], []]
 * Output
 *  [null, true, true, true, false, 3, true, true, true, 4]
 *
 * Explanation
 * MyCircularQueue myCircularQueue = new MyCircularQueue(3);
 * myCircularQueue.enQueue(1); // return True
 * myCircularQueue.enQueue(2); // return True
 * myCircularQueue.enQueue(3); // return True
 * myCircularQueue.enQueue(4); // return False
 * myCircularQueue.Rear();     // return 3
 * myCircularQueue.isFull();   // return True
 * myCircularQueue.deQueue();  // return True
 * myCircularQueue.enQueue(4); // return True
 * myCircularQueue.Rear();     // return 4
 *
 * Constraints:
 * 1 <= k <= 1000
 * 0 <= value <= 1000
 * At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull. 
*/
class MyCircularQueue {
private:
    // vector to store the data
    vector<int> queue;

    // 2 pointers that points to head and tail
    int head;
    int tail;
    // variable to store the size of the queue
    int size;

public:
    MyCircularQueue(int k) {
        // Resizing the queue with input size
        // and update the size
        queue.resize(k);
        size = k;

        // Initialize head and tail which points to
        // head and tail of hte queue
        head = -1;
        tail = -1;
    }

    // Inserts an item to the queue if there is a space in
    // the queue
    bool enQueue(int value) {
        if (isFull()) {
            // Queue is full, can't insert any item to queue
            return false;
        }

        // Queue is not empty, inset item at tail
        tail = (tail + 1) % size;
        // Insery the data at tail
        queue[tail] = value;

        // Update head if it is empty
        head = head == -1 ? 0 : head;

        return true;
    }

    // Remove the element from the front of the queue
    bool deQueue() {
        // Check if the queue is empty
        if (head == -1) {
            // Queue is empty return -1
            return false;
        }

        // Queue is not empty, if there is only one element
        // then update the head and tail, else update the head
        head = head == tail ? tail = -1 : (head + 1) % size;

        return true;
    }

    // Returns the item at front of the queue
    int Front() {
        // Check if the queue is empty
        if (head == -1) {
            // Queue is empty return -1
            return -1;
        }

        // Queue is not rempty, return the item at front
        return queue[head];
    }

    // Returns the last item from the Queue
    int Rear() {
        // Check if the queue is empty
        if (head == -1) {
            // Queue is empty return -1
            return -1;
        }

        // Queue is not rempty, return the last item
        return queue[tail];
    }

    // Check whether the queue is empty or not
    bool isEmpty() {
        // Head is default, then the queue is empty
        return head == -1;
    }

    // Returns whether the queue is full or not
    bool isFull() {
        // If it is full, then tail should be points to the firs
        return ((tail + 1) % size) == head;
    }
};

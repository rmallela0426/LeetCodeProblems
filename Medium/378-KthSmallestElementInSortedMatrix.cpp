
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 378: Kth Smallest Element In Sorted Matrix
 *
 * Given an n x n matrix where each of the rows and columns are sorted in ascending order,
 * return the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest
 * number is 13
 *
 * Example 2:
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 *
 * Constraints:
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 300
 * -109 <= matrix[i][j] <= 109
 * All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
 * 1 <= k <= n2
*/
/*
 * Idea is to use the Priority Queue which is used as a maximum
 * heap where the elements are stored in decreasing order ie..,
 * maximum element on top.
 * Copy the matrix elements to the priority Queue.
 * Pop out the elements from queue until the size of queue becomes
 * equal to k.
 * Once done, the top element is the kth min element
*/
int kthSmallest(vector<vector<int>>& matrix, int k) {
    // Base case: If the size of the matrix is >= k or not
    if (matrix.size() * matrix.size() < k) {
        // There are no enought elements to find the kth smallest
        return 0;
    }

    // Max heap Priority Queue where this is a container that will
    // sort and put the elements in descending order.
    // Priority Queue holds k elements
    priority_queue<int> pq;

    // Initialize the row and col variables
    int row = 0;
    int col = 0;

    // Fill the K elements in the Queue
    for (int i = 0; i < k; i++) {
        // Push the matrix element to priority queue
        pq.push(matrix[row][col++]);

        // Reset col once first row is done
        if (col == matrix[0].size()) {
            row++;
            col = 0;
        }
    }

    // Remove the elements from queue if the size is greater than k
    while (row < matrix.size()) {
        while (col < matrix[0].size()) {
            // As we are using the max heap, max value will be on the top.
            // Need to remove the top value of heap only when current value
            // is smaller than the top value
            if (matrix[row][col] < pq.top()) {
                // Current value is smaller than k
                // Remove the top element from queue
                pq.pop();

                // Push the current value to the queue
                pq.push(matrix[row][col]);
            }
            col++;
        }
        // Reset the col
        col = 0;
        row++;
    }

    // The top element is the kth smallest element from matrix
    return pq.top();
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 119: Pascal's Triangle II
 *
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
 * Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 *
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 *
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 *
 * Constraints:
 * 0 <= rowIndex <= 33
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
 */
vector<int> getRow(int rowIndex) {
    // Check if the num of rows is zero
    if (rowIndex == 0) {
        // numRows is zero
        return { 1 };
    }

    // vector to store the required row. As we can see that
    // for 0th row there is 1 element and 1st row 2 elements
    // for kth row there will be k + 1 elements
    vector<int> res(rowIndex + 1, 0);

    // Push the 0th row to result
    res[0] = 1;

    // Traverse the loop from 1 to rowIndex
    for (int i = 1; i <= rowIndex; i++) {
        // Traverse the loop from right to left, and add the current
        // and previous elements of previous row to get the current
        // element
        for (int j = i; j > 0; j--) {
            // Inorder to get the current value in this row, add the
            // current index and previous index values
            res[j] += res[j - 1];
        }
    }

    return res;
}

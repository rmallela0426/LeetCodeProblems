
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 363: Max Sum of Rectange no larger than K
 *
 * Given an m x n matrix matrix and an integer k, return the max sum of a rectangle
 * in the matrix such that its sum is no larger than k.
 * It is guaranteed that there will be a rectangle with a sum no larger than k.
 *
 * Example 1:
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2
 * Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2
 *              is the max number no larger than k (k = 2).
 *
 * Example 2:
 * Input: matrix = [[2,2,-1]], k = 3
 * Output: 3
 *
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -100 <= matrix[i][j] <= 100
 * -105 <= k <= 105
 *
 * Follow up: What if the number of rows is much larger than the number of columns?
*/
/*
 * Approach followed is a prefix method. In order to understand better, first we need
 * to understand the approach that needs to be followed for a single dimensional array.
 *
*/
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    // Retrieve num of rows in the matrix
    int n = matrix.size();
    // Retrieve the row length
    int m = matrix[0].size();

    // Calculate the prefix sum for each row
    for (int row = 0; row < n; row++) {
        for (int col = 1; col < m; col++) {
            // evaluate the prefix sum ie.., sum of current and previous values
            matrix[row][col] += matrix[row][col - 1];
        }
    }

    // Variable to store the max sum
    int maxSum = INT_MIN;

    // Try every possible width of subarray
    for (int left = 0; left < m; left++) {
        for (int right = left; right < m; right++) {
            // Now that we got a subarray of columns, apply dp that performs a
            // binary search on that column to find the sum that is no larger than
            // k
            // set to store the prefix sum
            set<int> s = { 0 };

            // subarray sum
            int sum = 0;

            // Traverse all the rows of the column
            for (int row = 0; row < n; row++) {
                // Retrieving the sum of elements in that left and right
                sum += (left == 0 ? matrix[row][right] : matrix[row][right] - matrix[row][left - 1]);

                // Binary search of the value greter than or equal to (sum - k)
                auto it = s.lower_bound(sum - k);

                // Check whether greater element is present or ot
                if (it != s.end()) {
                    // There is a sum for this subarry, update the maxSum
                    maxSum = max(maxSum, sum - *it);
                }

                // push the sum to set
                s.insert(sum);
            }
        }
    }

    return maxSum;
}

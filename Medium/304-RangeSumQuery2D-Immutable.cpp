
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 304: Range Sum Query 2D Immutable
 *
 * Given a 2D matrix matrix, handle multiple queries of the following type:
 * Calculate the sum of the elements of matrix inside the rectangle defined
 * by its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 * Implement the NumMatrix class:
 *    NumMatrix(int[][] matrix) Initializes the object with the integer matrix.
 *    int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of
 *    the elements of matrix inside the rectangle defined by its upper left
 *    corner (row1, col1) and lower right corner (row2, col2).
 *
 * Example 1:
 * Input
 * ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
 * [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7],
 *    [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
 * Output
 * [null, 8, 11, 12]
 *
 * Explanation
 * NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
 *
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -105 <= matrix[i][j] <= 105
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * At most 104 calls will be made to sumRegion.
*/
class NumMatrix {
public:
    /*
     * As the input vector is immutable i.e.., it won't change,
     * will calculate the running sum and store in a vector.
     * Each row running sum is calculated and stored. Once sum
     * Region is called, then evaluate the sum of all the rows
     * and return
    */
    NumMatrix(vector<vector<int>>& matrix) {
        sums.resize(matrix.size());

        // Running sum calculation
        for (int row = 0; row < matrix.size(); row++) {
            // Reserve the size for current row
            sums[row].resize(matrix[row].size());

            sums[row][0] = matrix[row][0];

            // Calculate the running sum for each row
            for (int col = 1; col < matrix[row].size(); col++) {
                sums[row][col] = sums[row][col - 1] + matrix[row][col];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // As the running sum for each row is calculated, sum of all values
        // at [row1][col2] ... [row2][col2] is the result
        int sum = 0;

        for (int row = row1; row <= row2; row++) {
            sum += (col1 == 0 ? sums[row][col2] : sums[row][col2] - sums[row][col1 - 1]);
        }

        return sum;
    }
private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

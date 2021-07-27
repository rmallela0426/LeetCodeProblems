
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 566: Reshape The Matrix
 *
 * In MATLAB, there is a handy function called reshape which can reshape an m x n matrix
 * into a new one with a different size r x c keeping its original data.
 * You are given an m x n matrix mat and two integers r and c representing the row number
 * and column number of the wanted reshaped matrix.
 * The reshaped matrix should be filled with all the elements of the original matrix in the
 * same row-traversing order as they were.
 * If the reshape operation with given parameters is possible and legal, output the new
 * reshaped matrix; Otherwise, output the original matrix.
 *
 * Example 1:
 *    1  2
 *    3  4    =>  1 2 3 4
 * Input: mat = [[1,2],[3,4]], r = 1, c = 4
 * Output: [[1,2,3,4]]
 *
 * Example 2:
 * Input: mat = [[1,2],[3,4]], r = 2, c = 4
 * Output: [[1,2],[3,4]]
 *
 * Constraints:
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * -1000 <= mat[i][j] <= 1000
 * 1 <= r, c <= 300
*/
/*
 * Need to reshape the matrix from mxn to rxc. In order to do that mxn == rxc
 * then only we can perform matrix reshaping. Initialize the result vector with
 * size of r and c. Traversing the entire 2d array, update resultant vector at
 * each rowIdx and colIdx. If the colIdx == c, then increment to next row and
 * colIdx = 0.
*/
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    // Retrieve the dimensions of input matrix
    int m = mat.size();
    int n = mat[0].size();

    // Check if the all the elements of the input array are required or not
    if (m * n != r * c) {
        // Not all the elements are required, return the input array
        return mat;
    }

    // output vector of dimensions r and c
    vector<vector<int>> res(r, vector<int>(c, 0));

    // Initializing output indices to zero
    int rIdx = 0;
    int cIdx = 0;

    // Traverse the input matrix
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            // place the current value to output vector
            res[rIdx][cIdx++] = mat[row][col];

            // check if we are done with all columns in current row
            if (cIdx == c) {
                // reset the column inde
                cIdx = 0;
                // Proceed to next row
                rIdx++;
            }
        }
    }

    return res;
}
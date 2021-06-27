
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 576: Out Of Boundary Paths
 *
 * There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn].
 * You are allowed to move the ball to one of the four adjacent four cells in the grid (possibly out
 * of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
 *
 * Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move
 * the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
 *
 * Example 1:
 * Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
 * Output: 6
 *
 * Example 2:
 * Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
 * Output: 12
 *
 * Constraints:
 * 1 <= m, n <= 50
 * 0 <= maxMove <= 50
 * 0 <= startRow <= m
 * 0 <= startColumn <= n
*/

/*
 * Approach followed is a dynamic programming technique
 * Recursive solution:
 *
 * The ball can move in 4 directions, left, right, top, bottom. If at any
 * move if reached maxMoves then it can't be procced further. If the ball
 * cross the boundary, then we have one path
 *
 * Base Cases:
 *  . If the maxMoves <= 0, no further moves and the path is invalid
 *  . If the current row, col is <= 0 or row == m & col == n, then the ball
 *    is out of the grid we have one path
 */

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // Base Case: check if the ball is out of the grid
    if (startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n) {
        // Ball is out of grid boundary, valid path
        return 1;
    }

    // Base case: If we are done with maxMoves
    if (maxMove <= 0) {
        // Done with the maxMoves, can't move the ball further in this path
        return 0;
    }

    // Move the ball in all four directions
    return findPaths(m, n, maxMove - 1, startRow - 1, startColumn)
        + findPaths(m, n, maxMove - 1, startRow + 1, startColumn)
        + findPaths(m, n, maxMove - 1, startRow, startColumn - 1)
        + findPaths(m, n, maxMove - 1, startRow, startColumn + 1);
}

/*
 *
 * TopDown + Memonization
 *
 * As we can see the ball can move in all four directions, there will be many
 * duplicate problems. so will use memonization technique where the intermediate
 * results are stored in a dp array
*/
int mod = (1e9 + 7);
int findPaths_memo(int m, int n, int moves, int row, int col, vector<vector<vector<int>>>& dp) {
    // Base Case: check if the ball is out of the grid
    if (row < 0 || col < 0 || row >= m || col >= n) {
        // Ball is out of grid boundary, valid path
        return 1;
    }

    // Base case: If we are done with moves
    if (moves <= 0) {
        // Done with the moves, can't move the ball further in this path
        return 0;
    }

    // check if this solution is already evaluated
    if (dp[row][col][moves] != -1) {
        // This problem is already evaluated
        return dp[row][col][moves];
    }

    int top = findPaths_memo(m, n, moves - 1, row - 1, col, dp);
    int bottom = findPaths_memo(m, n, moves - 1, row + 1, col, dp);
    int left = findPaths_memo(m, n, moves - 1, row, col - 1, dp);
    int right = findPaths_memo(m, n, moves - 1, row, col + 1, dp);

    // Move the ball in all four directions
    return dp[row][col][moves] = ((top + bottom) % mod + (left + right) % mod) % mod;
}

int findPaths(int m, int n, int moves, int row, int col) {
    // dp table for storing the intermediate results which stores the number
    // paths to reach that particular grid
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(moves + 1, -1)));

    return findPaths_memo(m, n, moves, row, col, dp);
}

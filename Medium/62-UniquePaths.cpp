
/*
 *  Author: Raghavendra Mallela
*/

/*
 * LeetCode 62: Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid
 * (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid
 * (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 * Example 1:
 * Input: m = 3, n = 7
 * Output: 28
 *
 * Example 2:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 * Constraints:
 * 1 <= m, n <= 100
 * It's guaranteed that the answer will be less than or equal to 2 * 109.
*/
/*
 * TopDown Approach or Recursive Solution
 *
 * only two ways to go from top to botomm either right or down, there will
 * 2 subproblems for each problem
 *
 * ie.., For Eg1 : (minPathSum(row+1, col) + minPathSum(row, col+1)
 *
 * Base cases:
 * If the row and column reaches tails, then this is a unique path, return 1.
 * If the row reaches the tail, then needs to move to right
 * If the col reaches the tail, then needs to move to down
 *
 */
int uniquePaths(int m, int n, int row, int col) {
    if (row == m - 1 && col == n - 1) {
        // Robot reached the destination from starting point, this is one path
        return 1;
    }

    if (row == m - 1) {
        // If robot is done moving down ie., reached tail, move right
        return uniquePaths(m, n, row, col + 1);
    }

    if (col == n - 1) {
        // If robot is done moving right ie..., reached tail, move down
        return uniquePaths(m, n, row + 1, col);
    }

    // Robot has two ways to move right or down, the result of solution is sum of 2
    // subproblems one moving right other moving down
    return uniquePaths(m, n, row + 1, col) + uniquePaths(m, n, row, col + 1);
}

int uniquePaths(int m, int n) {
    return uniquePaths(m, n, 0, 0);
}

/*
 * UniquePaths BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main problem
 * can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find bottom solutions first to yield the top solution i.e.., solution of
 * the problem
 *
 * The DP table at i, j holds the distance that needs to traverse from 0,0
 * Base cases:
 * If robot and start at 0,0 then there is 1 way ie.., 1
 *
 * If the row is at 0 then only possible way is to move right, only one way
 *    dp[i][j] = dp[i][j-1]
 *
 * If the column is at 0, only possible way is to move down, only one way
 *    dp[i][j] = dp[i-1][j]
 *
 * else there are 2 possible ways right or down, then result of the subproblem
 * is sum of previous row, current column and current row, previous column
 *    dp[i][j] = dp[i-1][j] + dp[i][j-1]
 */
int uniquePaths_BU(int m, int n) {
    // dp array to store intermediate solutions of the subproblem
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (row == 0 && col == 0) {
                // If the robot and end point are at 0,0 then there will be only one way
                dp[row][col] = 1;
            }
            else if (row == 0 || col == 0) {
                // If the row is 0, then robot can be moved only right
                // If the col is 0, then robot can be moved only down
                dp[row][col] = row == 0 ? dp[row][col - 1] : dp[row - 1][col];
            }
            else {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
    }

    // Solution to the problem is at end of the array
    return dp[m - 1][n - 1];
}

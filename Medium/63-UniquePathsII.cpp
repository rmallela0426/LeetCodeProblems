
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 63: Unique Paths II
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to
 * reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and space is marked as 1 and 0 respectively in the grid.
 *
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
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
 * If there is an obstracle then the path is invalid, return 0;
 * If the row and column reaches tails, then this is a unique path, return 1.
 * If the row reaches the tail, then needs to move to right
 * If the col reaches the tail, then needs to move to down
 *
 */
int uniquePathsII(vector<vector<int>>& obstacles, int row, int col) {
    if (obstacles[row][col] == 1) {
        // As the solution goes from 0,0 to m-1, n-1 no need to check wheather
        // row and col are valid
        // There is an obstracle and path is ended here and not valid, return 0
        return 0;
    }
    if (row == obstacles.size() - 1 && col == obstacles[0].size() - 1) {
        // Robot reached the destination from starting point, this is one path
        return 1;
    }

    if (row == obstacles.size() - 1) {
        // If robot is done moving down ie., reached tail, move right
        return uniquePathsII(obstacles, row, col + 1);
    }

    if (col == obstacles[row].size() - 1) {
        // If robot is done moving right ie..., reached tail, move down
        return uniquePathsII(obstacles, row + 1, col);
    }

    // Robot has two ways to move right or down, the result of solution is sum of 2
    // subproblems one moving right other moving down
    return uniquePathsII(obstacles, row + 1, col) + uniquePathsII(obstacles, row, col + 1);
}

int uniquePaths(int m, int n) {
    return uniquePaths(m, n, 0, 0);
}

/*
 * UniquePathsII BottomUp solution
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
 * If at any i, j there is an obstacle, then the path is ended and zero is placed
 *    dp[i][j] = 0
 *
 * If the row is at 0 then only possible way is to move right, only one way
 *    dp[i][j] = dp[i][j-1]
 *
 * If the column is at 0, only possible way is to move down, only one way
 *    dp[i][j] = dp[i-1][j]
 *
 * There will be no ways for robot to trasverse if any obstacles is encountered in the
 * path of first row or column
 *
 * else there are 2 possible ways right or down, then result of the subproblem
 * is sum of previous row, current column and current row, previous column
 *    dp[i][j] = dp[i-1][j] + dp[i][j-1]
 */
int uniquePathsII_BU(vector<vector<int>>& obstacles) {
    if (obstacles[0][0] == 1) {
        // There is an obstacle in the start point of Robot, there will be no unique paths
        return 0;
    }

    int m = obstacles.size();
    int n = obstacles[0].size();

    // dp array to store intermediate solutions of the subproblem
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // If the robot and end point are at 0,0 then there will be only one way
    dp[0][0] = 1;

    // Fill all the initial row ie.., row = 0, robot can move only one way ie.., right
    // If there is any obstacle, then place zero
    for (int col = 1; col < n; col++) {
        dp[0][col] = obstacles[0][col] == 1 ? 0 : dp[0][col - 1];
    }

    // Fill all the initial col ie.., col = 0, robot can move only one way ie.., down
    // If there is any obstacle, then place zero
    for (int row = 1; row < m; row++) {
        dp[row][0] = obstacles[row][0] == 1 ? 0 : dp[row - 1][0];
    }

    // Fill the remaining dp array
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            // check if there is any obstracle, if not there will be 2 possibliites tha
            // robot can move one down & one right
            if (obstacles[row][col] == 0)
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
        }
    }

    // Solution to the problem is at end of the array
    return dp[m - 1][n - 1];
}

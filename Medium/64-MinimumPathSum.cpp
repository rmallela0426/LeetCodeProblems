/*
 *  Author: Raghavendra Mallela
*/

/*
 * LeetCode 64: Mininumu Path Sum
 * Given a m x n grid filled with non-negative numbers, find a path from
 * top left to bottom right, which minimizes the sum of all numbers along
 * its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example 1:
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1->3->1->1->1 minimizes the sum.
 *
 * Example 2:
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 *
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
*/
/*
 * TopDown Approach or Recursive Solution
 *
 * only two ways to go from top to botomm either right or down, there will
 * 2 subproblems for each problem
 *
 * ie.., For Eg1 : grid[row][col] + min(minPathSum(row+1, col), minPathSum(row, col+1)
 *
 * Base cases:
 * If the row and column reaches tails, then the result will be current num.
 * If the row reaches the tail, then needs to move to right
 * If the col reaches the tail, then needs to move to down
 *
 */
int minPathSum(vector<vector<int>>& grid, int row, int col) {
    if (row == grid.size() - 1 && col == grid[row].size() - 1) {
        // If both row and col reaches the tails, then return curr no.
        return grid[row][col];
    }

    if (row == grid.size() - 1) {
        // If the row reaches the tail, then move right
        return grid[row][col] + minPathSum(grid, row, col + 1);
    }

    if (col == grid[0].size() - 1) {
        // If the col reaches the tail, then move down
        return grid[row][col] + minPathSum(grid, row + 1, col);
    }

    return grid[row][col] + std::min(minPathSum(grid, row + 1, col), minPathSum(grid, row, col + 1));
}

int minPathSum(vector<vector<int>>& grid) {
    return minPathSum(grid, 0, 0);
}

/*
 * isInterleave BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main problem
 * can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find bottom solutions first to yield the top solution i.e.., solution of
 * the problem
 *
 * The DP table at i, j holds the min that needs to traverse from 0,0
 */

int minPathSum_BU(vector<vector<int>>& grid) {
    if (grid.empty()) {
        // If the grid is empty, return zero
        return 0;
    }

    // dp array to store the cummulative sum of each subproblem
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

    // Fill the dp table by evaluating each subproblem
    for (int row = 0; row < dp.size(); row++) {
        for (int col = 0; col < dp[0].size(); col++) {
            dp[row][col] += grid[row][col];

            if (row > 0 && col > 0) {
                dp[row][col] += std::min(dp[row - 1][col], dp[row][col - 1]);
            }
            else if (row > 0 || col > 0) {
                dp[row][col] += row > 0 ? dp[row - 1][col] : dp[row][col - 1];
            }

        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}

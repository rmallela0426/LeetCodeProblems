
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 120: Triangle
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 *
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 *
 * Example 1:
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 *
 * Example 2:
 * Input: triangle = [[-10]]
 * Output: -10
 *
 * Constraints:
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -104 <= triangle[i][j] <= 104
 * Follow up: Could you do this using only O(n) extra space, where n is the total number
 * of rows in the triangle?
*/

/*
 * TopDown Approach or Recursive Solution
 *
 * There will be 2 subproblems for each problem i.e.., one can move to either index i or
 * index i+1 in the next row, so the solution will be like
 *       std::min(triangle[row][idx] + minTotal(triangle, row+1, idx),
 *                triangle[row][idx+1] + minTotal(triangle, row+1, idx+1));
 *
 * For eg:
 *    [[-1],[2,3],[1,-1,-3]]  -  Row 0 has only one element
 *
 *                           -1
 *                            |
 *                  -------------------------
 *                 |                         |
 *             -1 + 2         ||          -1 + 3
 *                |                          |
 *          -------------           --------------------
 *         |     ||      |          |        ||          |
 *    -1 + 2 + 1    -1 + 2 -1    -1 + 3 -1           -1 + 3 -3
 *
 * Base cases:
 * If the row == 0, then only one index
 * If the row >= length, then there are no more row, return 0
 *
 */
int minimumTotal(vector<vector<int>>& triangle, int row, int idx) {
    if (row >= triangle.size()) {
        // No amount left to add as there are no rows in
        // array remaining, return 0
        return 0;
    }

    // Calculate the left, right node in treee shown in the comments
    int left = triangle[row][idx] + minimumTotal(triangle, row + 1, idx);
    int right = triangle[row][idx + 1] + minimumTotal(triangle, row + 1, idx + 1);

    return std::min(left, right);
}

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) {
        return 0;
    }

    return triangle[0][0] + minimumTotal(triangle, 1, 0);
}

/*
 * minimumTotal BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main problem
 * can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find bottom solutions first to yield the top solution i.e.., solution of
 * the problem
 *
 * As there are 2 subproblems for each problem i.e.., one can move to either index i or
 * index i+1 in the next row. the solution from row = triangle.length() - 2 ie.., last
 * but one row and calculate the minimum Total for each column in that row
 *
 *   dp[col] =  triangle[row][col]  +  std::min(dp[row+1][col], dp[row+1][col+1])
 * Base Case:
 *   . When the input is empty, then minTotal will be zero
 *
 */
int minimumTotal_BU(vector<vector<int>>& triangle) {
    if (triangle.empty()) {
        return 0;
    }

    // Dp table that store the min total of each column and store the values
    // of last row
    vector<int> dp(triangle[triangle.size() - 1]);

    // Loop all the rows starting from last but one row
    for (int row = triangle.size() - 2; row >= 0; row--) {
        for (int col = 0; col < triangle[row].size(); col++) {
            dp[col] = triangle[row][col] + std::min(dp[col], dp[col + 1]);
        }
    }

    return dp[0];
}

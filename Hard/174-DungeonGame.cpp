
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 174: Dungeon Game
 *
 * The demons had captured the princess and imprisoned her in the bottom - right corner
 * of a dungeon.The dungeon consists of m x n rooms laid out in a 2D grid.Our valiant
 * knight was initially positioned in the top - left room and must fight his way through
 * dungeon to rescue the princess.
 * The knight has an initial health point represented by a positive integer.If at any
 * point his health point drops to 0 or below, he dies immediately.
 *
 * Some of the rooms are guarded by demons(represented by negative integers), so the knight
 * loses health upon entering these rooms; other rooms are either empty(represented as 0) or
 * contain magic orbs that increase the knight's health (represented by positive integers).
 *
 * To reach the princess as quickly as possible, the knight decides to move only rightward
 * or downward in each step.
 *
 * Return the knight's minimum initial health so that he can rescue the princess.
 *
 * Note that any room can contain threats or power - ups, even the first room the knight
 * enters and the bottom - right room where the princess is imprisoned.
 *
 * Example 1:
 * Input: dungeon = [[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]
 * Output : 7
 * Explanation : The initial health of the knight must be at least 7 if he follows the optimal
 * path : RIGHT->RIGHT->DOWN->DOWN.
 *
 * Example 2 :
 * Input : dungeon = [[0]]
 * Output : 1
 *
 * Constraints :
 * m == dungeon.length
 * n == dungeon[i].length
 * 1 <= m, n <= 200
 * - 1000 <= dungeon[i][j] <= 1000
*/

/*
 * TopDown Approach or Recursive Solution
 *
 * The solution is to find the minimum health that is required by knight to save Queen
 * If incase the kinight and Queen at the same point in the dungeon, then to save Queen
 * the knight requires
 * For Eg: [[-3]] or [[3]] ie.., Knight and Queen are same point
 *     . If there is a demons, then the health required is min 4, so that Knight can fight
 *        with daemon and save the queen i.e.., 4 - 3 = 1
 *     . If there a magic orbs, then health is required is min 1 bcz knight should be alive
 *       to save the queen.
 *
 *  From above it is clear that min health needed is 1 and in case of dameon it is
 *             1 + abs(dameon health) => 1 -(dameon health)
 *
 *  In general health = std::max(1, 1-value at gird) if both queen and Knigth at same position

 * The Knight can only have two ways to go from top to botomm either right or down ie.., there
 * will 2 subproblems for each problem.
 * Starting at index 0,0 to m-1, n-1
 *
 *                     (0,0)
 *                       |
 *            ------------------------
 *           |                        |
 *         (1,0)                     (0,1)
 *           |
 *     -------------
 *    |             |
 *  (2,0)          (1,1)
 *
 * ie..,
 * std::max(1, min(calcminHealth(row+1, col), calcminHealth(row, col+1)) - grid[row][col])
 *
 * Base cases:
 * If the row and column reaches queen, then the result will be -current + 1 if there is a
 * demon else 1.
 * If the row reaches the tail, then knight can only move right
 * If the col reaches the tail, then knight can only move down
 *
 */
int calculateMinHP(vector<vector<int>>& d, int row, int col) {
    if (row >= d.size() - 1 && col >= d[row].size() - 1) {
        // Both Knight and Queen are at same position, then min health required is
        // 1 -(dameon health) or 1 if dameon or magic orb is present at that grid
        return d[row][col] < 0 ? 1 - d[row][col] : 1;
    }

    if (col == d[row].size() - 1) {
        // knight reaches end of the columns in a row, it can move only down
        return std::max(1, calculateMinHP(d, row + 1, col) - d[row][col]);
    }

    if (row == d.size() - 1) {
        // Knight reaches the end of the row in column, it can only move right
        return std::max(1, calculateMinHP(d, row, col + 1) - d[row][col]);
    }

    // Else Knight can move either down or right
    return std::max(1, std::min(calculateMinHP(d, row + 1, col),
        calculateMinHP(d, row, col + 1)) - d[row][col]);
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    return calculateMinHP(dungeon, 0, 0);
}

/*
 * Top Down with Memonization
 *
 * As there are many duplicate subproblems problems, results can intermediately stored
 * in dp array.
 * Conditions are similar to Recursive Solution
*/
int calculateMinHP_memo(vector<vector<int>>& d, int row, int col, vector<vector<int>>& dp) {
    if (row >= d.size() - 1 && col >= d[row].size() - 1) {
        // Both Knight and Queen are at same position, then min health required is
        // 1 -(dameon health) or 1 if dameon or magic orb is present at that grid
        return d[row][col] < 0 ? 1 - d[row][col] : 1;
    }

    // Check if the subproblem is already evaluated
    if (dp[row][col] != 0) {
        // Solution for this subproblem is already evaluated
        return dp[row][col];
    }

    if (col == d[row].size() - 1) {
        // knight reaches end of the columns in a row, it can move only down
        return dp[row][col] = std::max(1, calculateMinHP_memo(d, row + 1, col, dp) - d[row][col]);
    }

    if (row == d.size() - 1) {
        // Knight reaches the end of the row in column, it can only move right
        return dp[row][col] = std::max(1, calculateMinHP_memo(d, row, col + 1, dp) - d[row][col]);
    }

    // Else Knight can move either down or right
    return dp[row][col] = std::max(1, std::min(calculateMinHP_memo(d, row + 1, col, dp),
        calculateMinHP_memo(d, row, col + 1, dp)) - d[row][col]);
}

int calculateMinimumHP_memo(vector<vector<int>>& dungeon) {
    vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
    return calculateMinHP_memo(dungeon, 0, 0, dp);
}

/*
 * CalculateMinHealth BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main
 * problem can ba attained if there are solutions for suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate
 * results are stored in a dp table. Bottom up is to find bottom solutions first to yield the top
 * solution i.e.., solution of the problem
 *
 * As there are 2 subproblems for each problem i.e.., one can move to either Right or Bottom
 *  the solution from row & col is
 *    dp[row][col] = max(1, min(dp[row-1][col], dp[row][col-1]) - d[row][col])
 *
 * If the Knight and Queen are at end, then
 *    dp[m-1][n-1] = d[m-1][n-1] > 0 ? 1 : 1 - d[m-1][n-1]
 *
 */
int calculateMinimumHP_BU(vector<vector<int>>& dungeon) {
    if (dungeon.empty()) {
        // If the dungeon is empty, return zero
        return 0;
    }

    int m = dungeon.size();
    int n = dungeon[0].size();
    // dp array to store the cummulative sum of each subproblem
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // If the knight and Queen are at the end ie.., last cell
    dp[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0 ? 1 : 1 - dungeon[m - 1][n - 1];

    // fill last column cell only
    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = std::max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
    }

    // fill last row cell only
    for (int j = n - 2; j >= 0; j--) {
        dp[m - 1][j] = std::max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
    }

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = std::max(1,
                std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }

    return dp[0][0];
}

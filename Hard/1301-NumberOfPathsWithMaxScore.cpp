
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1301: Number of Paths with Max Score
 *
 * You are given a square board of characters. You can move on the board starting
 * at the bottom right square marked with the character 'S'.
 * You need to reach the top left square marked with the character 'E'. The rest of
 * the squares are labeled either with a numeric character 1, 2, ..., 9 or with an
 * obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if
 * there is no obstacle there.
 *
 * Return a list of two integers: the first integer is the maximum sum of numeric
 * characters you can collect, and the second is the number of such paths that you
 * can take to get that maximum sum, taken modulo 10^9 + 7.
 *
 * In case there is no path, return [0, 0].
 *
 * Example 1:
 * Input: board = ["E23","2X2","12S"]
 * Output: [7,1]
 *
 * Example 2:
 * Input: board = ["E12","1X1","21S"]
 * Output: [4,2]
 *
 * Example 3:
 * Input: board = ["E11","XXX","11S"]
 * Output: [0,0]
 *
 * Constraints:
 * 2 <= board.length == board[i].length <= 100
*/
/*
 * Solution is to find the max sum of numeric characters that can be collected and no of
 * such paths that yield to max sum when we move from bottom right("S") to top left("E").
 *
 * There are 3 ways to move from a point either left, upl, up-left. If there is an
 * obstacle ('X) at any square, then there is no way to move in that path.
 *
 * For Eg: [E, 2].[2, S]
 * We move from 1, 1 we have 3 ways to go
 *
 *                  (1,1)
 *                   2|
 *           ----------------------
 *         2 |      0 |         2 |
 *       0+(0,1)    0+(0,0)     0+(1,0)
 *          2 |        |            2|
 *         2+(0,0)     0          2+(0,0)
 *             |                     |
 *             0                     0
 *
 * From above it is seen that there are 2 paths with the max same sum 2. So, the result will
 * be [2,2]
 * If we reached the first column, then there will be only one way to traverse ie., up
 * If we reached the first row, then there will be only way traverse is left
 * If we reached the destination, then return 0
 * If there is any obstacle, then there is no way to traverse return 0
*/
int pathsWithMaxScore(vector<string>& board, int row, int col, int& numMaxPaths) {
    if (row == 0 && col == 0) {
        // Reached the starting point
        // Increment the maxpath
        numMaxPaths += 1;
        return 0;
    }

    if (board[row][col] == 'X') {
        // There is an obstacles in the current square, no need to proceed further
        return 0;
    }

    int current = (board[row][col] == 'S' ? 0 : board[row][col] - '0');
    if (row == 0) {
        // reached the first row, we can traverse only on left
        return current + pathsWithMaxScore(board, row, col - 1, numMaxPaths);
    }

    if (col == 0) {
        // reached the first col, we can traverse only upwards
        return current + pathsWithMaxScore(board, row - 1, col, numMaxPaths);
    }

    // Move in upward direction
    int uppath = 0;
    int up = pathsWithMaxScore(board, row - 1, col, uppath);

    // Move in left direction
    int leftpath = 0;
    int left = pathsWithMaxScore(board, row, col - 1, leftpath);

    // Move in diagnol
    int diagpath = 0;
    int diag = pathsWithMaxScore(board, row - 1, col - 1, diagpath);

    // Calculate the maximum sum
    int res = max(max(up, left), diag);

    // Check and add the noOfMaxPaths
    numMaxPaths += res == up ? uppath : 0;
    numMaxPaths += res == left ? leftpath : 0;
    numMaxPaths += res == diag ? diagpath : 0;

    int mod = 1e9 + 7;
    numMaxPaths = numMaxPaths % mod;

    return current + res;
}

vector<int> pathsWithMaxScore(vector<string>& board) {
    int numMaxPaths = 0;

    int maxSum = pathsWithMaxScore(board, board.size() - 1, board[0].size() - 1, numMaxPaths);

    // Check to see if we reached the starting point. If not then discard the sum as there
    // is an obstacle in between
    maxSum = numMaxPaths == 0 ? 0 : maxSum;
    return vector<int>{maxSum, numMaxPaths};
}

/*
 * PathWithMaxScore BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the
 * main problem can ba attained if we have solutions of suproblems, Dynamic Programming can be
 * applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate
 * results are stored in a dp table. Bottom up is to find bottom solutions first to yield the top
 * solution i.e.., solution of the problem
 *
 * dp table will be of length [row+1][col+1], +1 is to store when the strings are empty
 * dp[row][col] holds the current sum that is needed to traverse till row and col
 *
 * As there are only 3 ways to traverse, left, up, upleft, as we are traversing from bottom, the
 * dp consider will be right, bottom, right-bottom
 *
 *    dp[row][col] = board[row][col] + max(dp[row][col+1], dp[row+1][col], dp[row+1][col+1])
 *                                when board[row][col] != 'X'
 *
 * In order to calculate num of paths with max amount, at each point in the square, Calculate the
 * max value and increment the value
 */
vector<int> pathsWithMaxScore_BU(vector<string>& board) {
    int n = board[0].size();

    int mod = 1e9 + 7;

    // Create dp array length+1 to stoere the empty string
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> count(n + 1, vector<int>(n + 1, 0));

    // Fill the end and start of the board with 0
    board[0][0] = board[n - 1][n - 1] = '0';

    // Fill the count of end to 1
    count[n - 1][n - 1] = 1;

    // Start filling the dp array
    for (int row = n - 1; row >= 0; row--) {
        for (int col = n - 1; col >= 0; col--) {
            if (board[row][col] != 'X') {
                // Current square is not obstacle, need to calculate the max sum
                int mx = max(dp[row][col + 1], max(dp[row + 1][col], dp[row + 1][col + 1]));

                dp[row][col] = (board[row][col] - '0') + mx;

                if (dp[row][col + 1] == mx) {
                    count[row][col] = (count[row][col] + count[row][col + 1]) % mod;
                }
                if (dp[row + 1][col] == mx) {
                    count[row][col] = (count[row][col] + count[row + 1][col]) % mod;
                }
                if (dp[row + 1][col + 1] == mx) {
                    count[row][col] = (count[row][col] + count[row + 1][col + 1]) % mod;
                }
            }
        }
    }

    return vector<int>{count[0][0] == 0 ? 0 : dp[0][0], count[0][0]};
}

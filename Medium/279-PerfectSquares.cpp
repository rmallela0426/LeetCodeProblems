
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 279: Perfect Squares
 *
 * Given an integer n, return the least number of perfect square numbers that sum to n.
 * A perfect square is an integer that is the square of an integer; in other words, it
 * is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect
 * squares while 3 and 11 are not.
 *
 * Example 1:
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 *
 * Constraints:
 * 1 <= n <= 104
*/
/*
 * TopDown Approach or Recursive Solution
 *
 * There will be n subproblems for each problem i.e.., for each remainder amount, each perfect square
 * will be substracted and it goes on until the remainder is 0 or 1 or 2 or 3, the loop can be run
 * till i * i < n
 * Eg:
 *  1 -> 1^2 => only one perfect square is needed in order to make the sum 1
 *  2 -> 1^2 + 1^2  => only 2 perfect squares are needed in order to make the sum 2
 *  3 -> 1^2 + 1^2 + 1^2 => only 3 perfect squares are needed to make the sum 3
 *
 * Eg: n = 12, we can see that i can only go from 1 ... 3, bcz 4*4 > 12, no need to check for it
 *                                        12
 *                                        |
 *                       ------------------------------------
 *                      |                  |                 |
 *                  11(12-1^2)        8(12-2^2)           3(12-3^2)
 *                     |
 *             -------------------------
 *            |           |             |
 *        10(11-1^2)   7(11-2^2)      2(11-3^2)
 *
 * From above it is clear that for each iteration, there will n loop where n is no of numbers where
 * i * i < n
 *
 *    for (int i = 1; i * i < n; i++) {
 *       minNumber = min(minNumber, 1+ numSquares(n - i*i));
 *    }
 *
 * Base cases:
 * If n is <= 3 then we have solution for that problem, return n
 *
 */
int numSquares(int n) {
    // Check if n is lessthan or equal to 3
    if (n <= 3) {
        return n;
    }

    // Value to store the result. As min value is needed, intialize with INT_MAX
    int minNo = INT_MAX;

    // Loop for all elements whose squares are less than n
    for (int i = 1; i * i < n; i++) {
        minNo = min(minNo, 1 + numSquares(n - i * i));
    }

    return minNo;
}

/*
 * TopDown with Memonization
 *
 * As there are many duplicate subproblems and the solution to the problem can be
 * achieved if we have the solution to subproblems, dynamic programming can be
 * applied where intermediate solutions for the subproblems are stored in a map.
 * map points to num of perfect squares required that sum to n
*/
std::vector<int> mp;
int numSquares_memo(int n) {
    // Check if n is lessthan or equal to 3
    if (n <= 3) {
        return n;
    }

    // check if this subproblem is already evaluated
    if (mp[n] != -1) {
        // Subproblem is already evaluated, return the solution of it
        return mp[n];
    }

    // Value to store the result. As min value is needed, intialize with INT_MAX
    int minNo = INT_MAX;

    // Loop for all elements whose squares are less than n
    for (int i = 1; i * i <= n; i++) {
        minNo = min(minNo, 1 + numSquares_memo(n - i * i));
    }

    mp[n] = minNo;
    return mp[n];
}

int numSquares_m(int n) {
    mp.resize(n + 1, -1);

    return numSquares_memo(n);
}

/*
 * PerfectSquare BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main
 * problem can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate
 * results are stored in a dp table. Bottom up is to find bottom solutions first to yield the top
 * solution i.e.., solution of the problem
 *
 * The Dp table is of lenght amount + 1 where +1 is for to have the case when n is zero, and each
 * index i hods the min number of perfect squares that sum to i
  *
 * As the min no of perfect squares required to make up the remainder amount, initialize the dp
 * array with a maximum value i.e.., INT_MAX or n + 1
 *
 * Eg: n = 12;
 *   Loop for each value of i ranges from 4 ... n
 *    Loop for each value of j ranges from 1 to j*j <= i
 *       dp[i] = std::min (dp[i] - dp[j*j] + 1) only when i >= coins[j]

 * Base cases:
 * When n is <=3
 */
int numSquares(int n) {
    // dp array to store the intermediate solutions
    vector<int> dp(n + 1, INT_MAX);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], 1 + dp[j * j]);
        }
    }

    return dp[n];
}


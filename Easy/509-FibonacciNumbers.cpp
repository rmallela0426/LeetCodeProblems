
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 509: Fibonacci Numbers
 *
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called
 * the Fibonacci sequence, such that each number is the sum of the two
 * preceding ones, starting from 0 and 1. That is,
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * Given n, calculate F(n).
 *
 * Example 1:
 * Input: n = 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 *
 * Example 2:
 * Input: n = 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 *
 * Example 3:
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 *
 * Constraints:
 * 0 <= n <= 30
*/
/*
 * Approach followed is Dynamic Programming BottomUp Approach
 * where the result of subproblems are stored in an dp array.
 * DP array hold fibonacci numbers for every index i-> 0 to N
*/
int fib(int n) {
    if (n == 0) {
        return 0;
    }

    // DP array to hold the fibonnaci numbers for that
    // index. +1 is for having the value of 0 included
    int dp[n + 1];

    // As fibonacci numbers for 0 & 1 are known fill it
    dp[0] = 0;
    dp[1] = 1;

    // Loop for all value for 2...n
    for (int i = 2; i <= n; i++) {
        // Current fibonacci number is sum of previous 2 values
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the fibonacci number for N
    return dp[n];
}

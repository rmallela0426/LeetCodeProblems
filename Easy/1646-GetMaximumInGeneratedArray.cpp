
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1646: Get Maximum Generated Array
 *
 * You are given an integer n. An array nums of length n + 1 is
 * generated in the following way:
 *   . nums[0] = 0
 *   . nums[1] = 1
 *   . nums[2 * i] = nums[i] when 2 <= 2 * i <= n
 *   . nums[2 * i + 1] = nums[i] + nums[i + 1] when
 *                                           2 <= 2 * i + 1 <= n
 *
 * Return the maximum integer in the array nums​​​.
 *
 * Example 1:
 * Input: n = 7
 * Output: 3
 * Explanation: According to the given rules:
 *    nums[0] = 0
 *    nums[1] = 1
 *    nums[(1 * 2) = 2] = nums[1] = 1
 *    nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
 *    nums[(2 * 2) = 4] = nums[2] = 1
 *    nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
 *    nums[(3 * 2) = 6] = nums[3] = 2
 *    nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
 * Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is 3.
 *
 * Example 2:
 * Input: n = 2
 * Output: 1
 * Explanation: According to the given rules, the maximum between
 * nums[0], nums[1], and nums[2] is 1.
 *
 * Example 3:
 * Input: n = 3
 * Output: 2
 * Explanation: According to the given rules, the maximum between
 * nums[0], nums[1], nums[2], and nums[3] is 2.
 *
 * Constraints:
 * 0 <= n <= 100
*/
/*
 * Recursive Solution:
 * we are given n, we traverse recursively from n to 0 and
 * calculate the solutions for that subproblems. If n is even,
 * then the solution for the problem will be same as that of
 * n/2. If n is odd, then solution for this subproblem is
 * sum of n/2 and n/2 + 1.
 *
 *  (n % 2 == 0) => return max(max, getMaxGenerated(n/2))
 *  If n is odd => return max(max, getMaxGenerated(n/2) +
 *                                 getMaxGenerated(n/2 + 1))
 *
 * As there are many duplicate subproblems if we draw a tree
 * from the recursive solution and also solution for subproblem
 * can be obtained from the previously calculated subproblmes
 * we can use dynamic programming.
 *
 * BottomUp Solution:
 * A DP table to store the values for that current n.
 * If n is even, then
 *      dp[i] = dp[i/2]
 * else
 *      dp[i] = dp[i/2] + dp[i/2 + 1]
 * At each iteration try to find the maxInteger
*/
int getMaximumGenerated(int n) {
    // Basecase: If n <= 1
    if (n <= 1) {
        // n is either 0 or 1
        return n;
    }

    // DP table to store the current integers at n
    // size is n+1 to store the n = 0
    int dp[n+1];

    // Store when n = 0 and n = 1
    dp[0] = 0;
    dp[1] = 1;

    // maxInteger intialized to 1 as dp[1]
    int maxInt = 1;

    // Traverse the loop from 2 to n
    for (int i = 2; i <= n; i++) {
        // Calculate the integer at this current n based on whether
        // i is even or odd
        dp[i] = dp[i / 2];

        if (i % 2) {
            // current index is odd
            dp[i] += dp[i/2 + 1];
        }

        // Calculate the max integer in the array.
        maxInt = max(maxInt, dp[i]);
    }

    return maxInt;
}

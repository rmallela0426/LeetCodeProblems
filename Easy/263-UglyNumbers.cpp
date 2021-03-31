
/*
 *  Author: Raghavendra Mallela
 */
/*
 * Leetcode 263: Ugly Numbers
 *
 * Ugly number is a positive number whose prime factors only include 2, 3, and/or 5.
 *
 * Example 1:
 * Input: n = 6
 * Output: true
 * Explanation: 6 = 2 × 3
 *
 * Example 2:
 * Input: n = 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 *
 * Example 3:
 * Input: n = 14
 * Output: false
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 *
 * Example 4:
 * Input: n = 1
 * Output: true
 * Explanation: 1 is typically treated as an ugly number.
 *
 * Constraints:
 * -231 <= n <= 231 - 1
*/
/* An ugly number is the one whose prime factors
 *  are in the set of {2, 3, 5}
 * Eg: 6 = 2x3 => true
 *    14 = 7x2 => false, as 7 is not in out set
 *
 * TimeComplexity: O(NLogN)
 * Space Complexity: O(1)
*/
bool isUgly(int n) {
    if (n == 0) {
        // 0 is not a ugly number
        return false;
    }

    if (n == 1) {
        // 1 is always ugly number
        return true;
    }

    // Check if the number is divisible by 2, 3, 5
    // If so the result will be 1 where 1 is always
    // an ugly number
    for (int factor : {2, 3, 5}) {
        while (n % factor == 0) {
            n = n / factor;
        }
    }

    return n == 1;
}

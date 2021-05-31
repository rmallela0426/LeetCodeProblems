
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 829: Consecutive Numbers Sum
 *
 * Given a positive integer n, how many ways can we write it as a sum
 * of consecutive positive integers?
 *
 * Example 1:
 * Input: n = 5
 * Output: 2
 * Explanation: 5 = 5 = 2 + 3
 *
 * Example 2:
 * Input: n = 9
 * Output: 3
 * Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
 *
 * Example 3:
 * Input: n = 15
 * Output: 4
 * Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 * Note: 1 <= n <= 10 ^ 9.
*/
/*
 * Solution is to find the Consecutive positive integers that sums
 * up to n ie..,
 *   a, a + 1, a + 2, ......
 *
 * The summation of above numbers should be equal to n
 *
 *  a + a + 1 + a + 2 + ....... + a + k-1  = n
 * => a + a + .... + 1 + 2 + 3 + .... + k - 1 = n
 *
 * From above it is seen that, a + a + ....  = ka
 * the 2nd half 1 + 2 + 3 + .... k - 1, sum of first k natural numbers is
 *    k(k + 1) / 2  but it needs till k - 1 => (k - 1) * (k - 1 + 1) / 2
 *  => k(k - 1) / 2
 *
 * so equation a + a + .... + 1 + 2 .... + k - 1 = n
 *        =>  ka + k(k - 1) / 2 = n, solution is to find a
 *    as only positive integers are needed, k = 1... x(will find it)
 *
 *       => ka = n - k(k - 1) / 2
 *       => a = (n - k(k - 1)/2) % k where k = 1 ..... x (x needs to be find)
 *
 * So we need to evaluate above equation to find a for different values of k
 *
 * As a is +ve integers   n - k(k-1)/2 > 0
 *                     => n > k(k - 1) /2
 *                     => k(k - 1) < 2n
 *                     => k^2 < 2n
 * so loop will travers from  k = 1 ....... sqrt(2n)
 *
 * For eg: n = 5
 *      a = (n - k(k - 1) / 2) % k  k = 1 , 2, 3 as k * k < 2n
 *    k = 1 => a = (5 - 1 * (1 - 1) / 2) % 1 = 5
 *    k = 2 => a = (5 - 2 * (2 - 1) / 2) % 2 = 0
*/
int consecutiveNumbersSum(int n) {
    // variable to store the num ways that the n can be generated
    // When k = 1 it evaluates to n, so it is a way.
    int numWays = 1;

    // Travers the loop for every k value from 2 ... k * k < 2n
    for (int k = 2; k * k < (n << 1); k++) {
        // Evaluate the expression for the current value of k
        // and check if result is zero
        if ((n - k * (k - 1) / 2) % k == 0) {
            // we have a solution , increment the way.
            numWays++;
        }
    }

    return numWays;
}

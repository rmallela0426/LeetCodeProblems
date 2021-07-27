
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1137: Nth Tribonacci Number
 *
 * The Tribonacci sequence Tn is defined as follows:
 *    T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * Given n, return the value of Tn.
 *
 * Example 1:
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 *
 * Example 2:
 * Input: n = 25
 * Output: 1389537
 *
 * Constraints:
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/
/*
 * Approach followed is a Recursive solution where n is the sum
 * previous 3 values.
 * basecase is when n < 3
 * As there are many duplicate subproblems in recursive solution
 * and the solution for subproblem can be attained from previously
 * solved subproblem, dynamic programming is used.
 * Algorithm followed below is a bottomUp solution where 3 previous
 * values are stored and will be used to generate the Nth tribonacci
 * number.
*/
int tribonacci(int n) {
    // BaseCase: when n is less than 3
    if (n < 3) {
        // n  is less than 3, check if the n value is 2 or not. If
        // it is 2, then return 1 else return i
        return n == 2 ? 1 : n;
    }

    // Variables to store the previous 3 subproblem solutions initially
    // these are the three base cases ie.., n = 0, n = 1, n = 2
    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 1;

    // varible to store teh current number
    int curr = 0;

    // Iterate over the n values from 3 to n
    for (int i = 3; i <= n; i++) {
        // Calculate the curren tribonacci number
        curr = prev1 + prev2 + prev3;

        // Update the previous 3 tribonacci bumbers
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

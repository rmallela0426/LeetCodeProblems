
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1281: Subtract Product And Sum of Digits in an Integer
 *
 * Given an integer number n, return the difference between the product of
 * its digits and the sum of its digits.
 *
 * Example 1:
 * Input: n = 234
 * Output: 15 
 * Explanation: 
 * Product of digits = 2 * 3 * 4 = 24 
 * Sum of digits = 2 + 3 + 4 = 9 
 * Result = 24 - 9 = 15
 *
 * Example 2:
 * Input: n = 4421
 * Output: 21
 * Explanation: 
 * Product of digits = 4 * 4 * 2 * 1 = 32 
 * Sum of digits = 4 + 4 + 2 + 1 = 11 
 * Result = 32 - 11 = 21
 *
 * Constraints:
 * 1 <= n <= 10^5
*/
/*
 * Approach is to use %, / operators in order
 * get, remove the last digit
*/
int subtractProductAndSum(int n) {
    // Variables to store the result of multiplication
    // and sum of the digits of the input num.
    int mul = 1;
    int sum = 0;

    // Loop until all digits are evaluated
    while (n > 0) {
        // Get the last digit using the modulo operater
        // and evaluate the sum and multiply
        mul *= (n % 10);
        sum += (n % 10);
        // Remove the last digit
        n /= 10;
    }

    // return the difference
    return mul - sum;
}

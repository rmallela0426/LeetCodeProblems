
/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 507: Perfect Number
 *
 * A perfect number is a positive integer that is equal to the sum of its
 * positive divisors, excluding the number itself. A divisor of an integer
 * x is an integer that can divide x evenly.
 *
 * Given an integer n, return true if n is a perfect number, otherwise
 * return false.
 *
 * Example 1:
 * Input: num = 28
 * Output: true
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 1, 2, 4, 7, and 14 are all divisors of 28.
 *
 * Example 2:
 * Input: num = 6
 * Output: true
 *
 * Example 3:
 * Input: num = 496
 * Output: true
 *
 * Example 4:
 * Input: num = 8128
 * Output: true
 *
 * Example 5:
 * Input: num = 2
 * Output: false
 *
 * Constraints:
 * 1 <= num <= 108
*/
/*
 * Solution is to find sum of divisors which can divide
 * num evenly. A divisor x can divide the num evenly only
 * when x is <= num / 2. After that there is no way that
 * x can be a divisor. Taking this into consideration, the
 * loop will run till x is <= num /2. For each iteration,
 * check if current x is a divisor if so add it to sum.
*/
bool checkPerfectNumber(int num) {
    // variable to store result
    int sum = 0;

    // Iterate loop till x is <= num/2
    for (int i = 1; i <= (num >> 1); i++) {
        // Check if is a divisor
        if (num % i == 0) {
            // Its a divisor of num, add it to current sum
            sum += i;
        }
    }

    // Return true if sum of divisors are equal to num
    return sum == num;
}

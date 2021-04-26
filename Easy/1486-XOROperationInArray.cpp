
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1486: XOR Operation in a Array
 *
 * Given an integer n and an integer start.
 * Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.
 * Return the bitwise XOR of all elements of nums.
 *
 * Example 1:
 * Input: n = 5, start = 0
 * Output: 8
 * Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
 * Where "^" corresponds to bitwise XOR operator.
 *
 * Example 2:
 * Input: n = 4, start = 3
 * Output: 8
 * Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.
 *
 * Constraints:
 * 1 <= n <= 1000
 * 0 <= start <= 1000
 * n == nums.length
*/
/*
 * Solution is to find XOR of all elements from 0 to n,
 * where each element is start + 2 * i.
 *
 * If i = 0, then res = start. Loop from 1 to n and do
 * an XOR operation
*/
int xorOperation(int n, int start) {
    // n  = 0 =>  start + 2*0 = start
    int res = start;

    // Loop from 1...n
    for (int k = 1; k < n; k++) {
        // XOR the element
        res ^= (start + (k << 1));
    }
    // return the result
    return res;
}

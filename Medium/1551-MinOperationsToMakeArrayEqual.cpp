
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1551: Min Operations To Make Array Equal
 *
 * You have an array arr of length n where arr[i] = (2 * i) + 1 for all
 * valid values of i (i.e. 0 <= i < n).
 * In one operation, you can select two indices x and y where 0 <= x, y < n
 * and subtract 1 from arr[x] and add 1 to arr[y] (i.e. perform arr[x] -=1
 * and arr[y] += 1). The goal is to make all the elements of the array equal.
 * It is guaranteed that all the elements of the array can be made equal using
 * some operations.
 * Given an integer n, the length of the array. Return the minimum number of
 * operations needed to make all the elements of arr equal.
 *
 * Example 1:
 * Input: n = 3
 * Output: 2
 * Explanation: arr = [1, 3, 5]
 * First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
 * In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
 *
 * Example 2:
 * Input: n = 6
 * Output: 9
 *
 * Constraints:
 * 1 <= n <= 10^4
*/

/* Approach followed is to generate array with formula
 * (2 * i) + 1 and by defining a target = sum(arr) /n
 * The min no of operations required to make the array
 * equal is sum of absolute difference of target and
 * arr[i] where i = 0 to n/2
 * Few Common points are
 * . The consecutive elemnents will have a difference of 2
 * . The sum of the elements in the array will be n * n and
 *   target will be n*n/n => n itself
 * . The absolute difference will be in descending order and
 *   reaches 0(odd no of elem) & 1(even no of elem), so inorder
 *   to get the min operations we can only run loop n/2 times
 *
 * Eg: When n is even n = 6
 *     arr => [1, 3, 5, 7, 9, 11], sum = 36 (1+3+5+7+9+11)
 *     target = sum / n => 36 /6 => 6
 *
 *     absldiff => abs[6-1, 6-3, 6-5, 6-7, 6-9, 6-11]
 *              =>    [5, 3, 1, 1, 3, 5]
 * From above, it is seen that the operations required are
 * repeating at n/2 elements, so
 *     minOps = 5 + 3 + 1 => 9
 *
 */
int minOperations(int n) {
    // First element will be always 1
    int elem = 1;

    // Minimum operations required
    int minOps = 0;

    // Loop for half the elements in the array, the elements
    // will be generated on the fly
    for (int i = 0; i < n / 2; i++) {
        minOps += n - elem;
        // Adding 2 as there consecutive elements have difference 2
        elem = elem + 2;
    }

    return minOps;
}

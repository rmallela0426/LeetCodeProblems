
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 667: Beautiful Arrangment II
 *
 * Given two integers n and k, you need to construct a list which contains n
 * different positive integers ranging from 1 to n and obeys the following
 * requirement:
 * Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|,
 * |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
 *
 * If there are multiple answers, print any of them.
 *
 * Example 1:
 * Input: n = 3, k = 1
 * Output: [1, 2, 3]
 * Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to
 * 3, and the [1, 1] has exactly 1 distinct integer: 1.
 *
 * Example 2:
 * Input: n = 3, k = 2
 * Output: [1, 3, 2]
 * Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3,
 * and the [2, 1] has exactly 2 distinct integers: 1 and 2.
 *
 * Note:
 * The n and k are in the range 1 <= k < n <= 104.
*/
/*
 * Solution is to find an array of positive integers upto n where
 * difference between consecutive elements is exactly k distinct
 * integers
 * Eg: n = 8
 * k = 1 => 1, 2, 3, 4, 5, 6, 7, 8
 * k = 2 => 1, 3, 2, 4, 5, 6, 7, 8
 * k = 3 => 1, 4, 2, 3, 5, 6, 7, 8
 * k = 4 => 1, 5, 2, 4, 3, 6, 7, 8
 * k = 5 => 1, 6, 2, 5, 3, 4, 7, 8
 * k = 6 => 1, 7, 2, 6, 3, 5, 4, 8
 * k = 7 => 1, 8, 2, 7, 3, 6, 4, 5
 *
 * From above, a pattern is clearly seen where for all the elements
 * till k + 1, the numbers are low & hight ie.., low = 1, high = k+1
 * ie..., low, high+1, low+1, high, low+2, high-1,......
*/

vector<int> constructArray(int n, int k) {
    // Vector to store the result of n different positive integers
    vector<int> res(n, 0);

    // Low and high variables as the list goes from 1...n
    int low = 1;
    int high = k + 1;

    // Loop till k + 1 values
    for (int i = 0; i < k + 1; i++) {
        res[i] = i % 2 == 0 ? low++ : high--;
    }

    // Fill the remaining elements till n
    for (int i = k + 1; i < n; i++) {
        // As the list starts with 1, adding 1 to i
        res[i] = i + 1;
    }

    // return the result
    return res;
}

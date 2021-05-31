
/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 402: Remove K Digits
 *
 * Given string num representing a non-negative integer num, and an integer k,
 * return the smallest possible integer after removing k digits from num.
 *
 * Example 1:
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 *
 * Example 2:
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the output
 * must not contain leading zeroes.
 *
 * Example 3:
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing
 * which is 0.
 *
 * Constraints:
 * 1 <= k <= num.length <= 105
 * num consists of only digits.
 * num does not have any leading zeros except for the zero itself.
*/
/*
 * Solution is to find the smallest number after removing
 * k digits from num.
 * For Eg: "1432219", draw in in peak diagram
 *
 *        4
 *      /  \
 *     1    3
 *           \
 *            2 - 2
 *                 \   9
 *                  1 /
 *
 * From above we can clearly see that there was a dip from 4, 3 so
 * the first number to be removed is 4 and to make the curve flat.
 * If we have the numbers in ascending order, then we can have the
 * smallest number
*/
string removeKdigits(string num, int k) {
    // Check if the string length and no of items to remove is same
    if (num.length() == k) {
        // All the digits need to be removed, return "0"
        return "0";
    }

    // Variable to store the result
    string res = "";

    // Iterate over eacch digit in the input num
    for (char& ch : num) {
        // Check whether the current digit is less than the previous
        // pushed digit, if so pop it from result
        while (!res.empty() && k > 0 && res.back() > ch) {
            // current char is less than the previous pushed element
            res.pop_back();
            // As a digit is removed, decrement the K
            --k;
        }

        // Check if the curr char is not 0. The result shouldn't have
        // leading zeros
        if (!res.empty() || ch != '0') {
            // Push the current char to result
            res.push_back(ch);
        }
    }

    // Remove the K elements if there are any from the result
    // For Eg: i/p = "123" k = 2
    // Above loop won't remove any digits as the input itself is in
    // increasing order
    while (!res.empty() && k-- > 0) {
        // Discard the last element
        res.pop_back();
    }

    // Return "0" if the result is empty
    return res.empty() ? "0" : res;
}


/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 1689: Partiotioning Into Min No of Deci-Binary Numbers
 *
 * A decimal number is called deci-binary if each of its digits is either 0 or 1 without
 * any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
 *
 * Given a string n that represents a positive decimal integer, return the minimum number
 * of positive deci-binary numbers needed so that they sum up to n.
 *
 * Example 1:
 * Input: n = "32"
 * Output: 3
 * Explanation: 10 + 11 + 11 = 32
 *
 * Example 2:
 * Input: n = "82734"
 * Output: 8
 *
 * Example 3:
 * Input: n = "27346209830709182346"
 * Output: 9
 *
 * Constraints:
 * 1 <= n.length <= 105
 * n consists of only digits.
 * n does not contain any leading zeros and represents a positive integer.
*/
/*
 * First finding the pattern in the output where for single digit,
 * result is the digit itself(sum of ones)
 * Eg: 1 -> 1
 *     2 -> 1 + 1 = 2 numbers
 *     3 -> 1 + 1 + 1 = 3 numbers
 *     9 -> 9 numbers
 *     12 -> 11 + 1 = 2 numbers
 *     23 -> 11 + 11 + 1 = 3 numbers
 *     32 -> 11 + 11 + 10 = 3 numbers
 *
 * From above, we can see that result is max digit in the input string
 * Taking this into consideration, approach is to find the max number
 * in the input and return the result
*/
int minPartitions(string n) {
    // variable to store max no of Positive deci-binary nos
    int maxDecBin = 0;

    // Loop all chars in input string, find the max no
    for (char& ch : n) {
        // Find the max digit
        maxDecBin = max(maxDecBin, ch - '0');

        // If current char is 9, then this will  be maximum and there
        // wont be any char greater than 9, no need to further proceed
        if (maxDecBin == 9) {
            break;
        }
    }

    return maxDecBin;
}

int minPartitions(string n) {
    // find the max values using std library and 
    // return. max_element returns the iterator
    return *max_element(n.begin(), n.end()) - '0';
}

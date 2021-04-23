
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leecode 1221: Split String In Balanced Strings
 *
 * Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
 * Given a balanced string s, split it in the maximum amount of balanced strings.
 *
 * Return the maximum amount of split balanced strings.
 *
 * Example 1:
 * Input: s = "RLRRLLRLRL"
 * Output: 4
 * Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains
 *              same number of 'L' and 'R'.
 *
 * Example 2:
 * Input: s = "RLLLLRRRLR"
 * Output: 3
 * Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same
 *              number of 'L' and 'R'.
 *
 * Example 3:
 * Input: s = "LLLLRRRR"
 * Output: 1
 * Explanation: s can be split into "LLLLRRRR".
 *
 * Example 4:
 * Input: s = "RLRRRLLRLL"
 * Output: 2
 * Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an
 * equal number of 'L' and 'R'
 *
 * Constraints:
 * 1 <= s.length <= 1000
 * s[i] is either 'L' or 'R'.
 * s is a balanced string.
*/
/*
 * Approach is to find num of balanced substrings where the R and
 * L are of equal quantity. For this loop all the characters of
 * the input string, count num L count, num R count and can be split
 * when there are equal quantity of L and R.
*/
int balancedStringSplit(string s) {
    // Variable to store the num of L & R chars
    int lCount = 0, rCount = 0;
    // Variable to store the num of balanced substrings that can be
    // formed with equal L & R chars
    int numSubStrings = 0;

    // Loop all characters of the input string
    for (char& ch : s) {
        // Increment the respective count
        ch == 'L' ? ++lCount : ++rCount;

        if (lCount == rCount) {
            // Found a balanced substring, increment the numSubstring
            numSubStrings++;
        }
    }

    // Return the susbstring count
    return numSubStrings;
}

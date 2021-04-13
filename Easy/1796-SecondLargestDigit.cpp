
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1796: Second Largest Digit in a String
 *
 * Given an alphanumeric string s, return the second largest numerical digit that
 * appears in s, or -1 if it does not exist.
 * An alphanumeric string is a string consisting of lowercase English letters and
 * digits.
 *
 * Example 1:
 * Input: s = "dfa12321afd"
 * Output: 2
 * Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
 *
 * Example 2:
 * Input: s = "abc1111"
 * Output: -1
 * Explanation: The digits that appear in s are [1]. There is no second largest digit.
 *
 * Constraints:
 * 1 <= s.length <= 500
 * s consists of only lowercase English letters and/or digits.
*/
/*
 * Approach is to have 2 variables, max and 2ndmax. Loop
 * each char of the string and if it is digit check with
 * max. If this max then update the max and 2ndmax.
 *
*/
int secondHighest(string s) {
    int max = -1;
    int max2 = -1;

    // Loop for all chars of input string
    for (char ch : s) {
        if (isdigit(ch)) {
            // Current char is a digit
            int current = ch - '0';
            if (current > max) {
                max2 = max;
                max = current;
            }
            else if (current != max && current > max2) {
                max2 = current;
            }
        }
    }

    return max2;
}

/*
 * Approach is to use the associative property of the data structer
 * std::set. Loop through all the chars in the string and push if it
 * is a digit. All the digits are in increasing order. Access the
 * second last which is the 2nd largest  number.
*/
int secondHighest(string s) {
    std::set<int> digits;

    for (char ch : s) {
        if (isdigit(ch)) {
            digits.insert(ch - '0');
        }
    }

    return *(++(digits.rbegin()));
}

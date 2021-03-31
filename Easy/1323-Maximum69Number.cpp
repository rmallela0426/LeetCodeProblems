
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1323: Maximum 69 Number
 *
 * Given a positive integer num consisting only of digits 6 and 9.
 * Return the maximum number you can get by changing at most one digit
 * (6 becomes 9, and 9 becomes 6).
 *
 * Example 1:
 * Input: num = 9669
 * Output: 9969
 * Explanation: 
 * Changing the first digit results in 6669.
 * Changing the second digit results in 9969.
 * Changing the third digit results in 9699.
 * Changing the fourth digit results in 9666. 
 * The maximum number is 9969.
 *
 * Example 2:
 * Input: num = 9996
 * Output: 9999
 * Explanation: Changing the last digit 6 to 9 results in the maximum number.
 *
 * Example 3:
 * Input: num = 9999
 * Output: 9999
 * Explanation: It is better not to apply any change.
 *
 * Constraints:
 * 1 <= num <= 10^4
 * num's digits are 6 or 9.
*/
/*
 * Solution is to find the maximum no by changing atmost one digit
 * 6 to 9 i.e.., replacing the first six from left to 9 will make
 * the number highest. If there is no 6 ie.., the input itself is
 * maximum number
*/

int maximum69Number(int num) {
    // Converting the input to a string
    string input = to_string(num);

    // Loop for all characters of input  string
    for (int i = 0; i < input.length(); i++) {
        // check if the  current char is 6, if so
        // replace with 9 and this will become the
        // maximum number
        if (input[i] == '6') {
            input[i] = '9';
            return stoi(input);
        }
    }

    // If there is no 6 atall, then the input itself
    // is a maximum number
    return num;
}

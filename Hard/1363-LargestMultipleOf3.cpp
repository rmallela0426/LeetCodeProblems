
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1363: Largest Multiple of Three
 * Given an integer array of digits, return the largest multiple of three that can
 * be formed by concatenating some of the given digits in any order.
 *
 * Since the answer may not fit in an integer data type, return the answer as a string.
 * If there is no answer return an empty string.
 *
 * Example 1:
 * Input: digits = [8,1,9]
 * Output: "981"
 *
 * Example 2:
 * Input: digits = [8,6,7,1,0]
 * Output: "8760"
 *
 * Example 3:
 * Input: digits = [1]
 * Output: ""
 *
 * Example 4:
 * Input: digits = [0,0,0,0,0,0]
 * Output: "0"
 *
 * Constraints:
 * 1 <= digits.length <= 10^4
 * 0 <= digits[i] <= 9
 * The returning answer must not contain unnecessary leading zeros
*/
/*
 * A number is a multiple of three if and only if its sum of digits is a multiple of three.
 * Eg: 555 is divisible by 3 because the sum of digits is divisible by 3 i.e.., 5+5+5 = 15
 *
 * If the number is not divisible by 3, then the max remainder will be either 1 or 2.
 * If remainder is either 1 or 2, then max 2 digits needs to be removed from the input
 * string so that the number is divisible by 3
 *
 * If the remainder is 1, then remove the smallest number that has remainder 1 or 2 digits
 * that has remainder 2 (eg: 2 + 2 = 4%3 =1)
 * If the remainder is 2, then remove the smallest number that has remainder 2 or 2 digits
 * that has remainder 1 (eg: 1 + 1 = 3%3 = 1)
*/
string largestMultipleOfThree(vector<int>& digits) {
    if (digits.empty()) {
        // If there are no digits then
        return "";
    }

    // Sort the numbers in the vector so that smallest number will be in the starting
    // index
    std::sort(digits.begin(), digits.end());

    // variable to hold the result
    string res = "";

    int sum = 0;
    // Find the sum of the digits
    // Also store the number in the string for attaining the result
    for (int digit : digits) {
        sum += digit;
        res += '0' + digit;
    }

    // Calculate the remainder of the sum by divinding with 3
    int remainder = sum % 3;

    if (remainder == 0) {
        // If the remainder 0 ie.., the number is divisible by 3, return the number
        std::reverse(res.begin(), res.end());

        return res[0] == '0' ? "0" : res;
    }

    // Remainder is either 1 or 2, remove one digit which equals the remainder or
    // removing 2 digits whose remainder equals 1 if ip remainder is 2 or remove 2
    // digits whose remainder equals 2 if ip remainder is 1

    // variables to store the index of the 2 digits that need to be removed
    int index[2] = { -1, -1 };

    // Loop for all digits and try to remove the digits
    for (int i = 0; i < res.length(); i++) {
        if (res[i] % 3 == remainder) {
            // Smallest number whose remainder is equals the input remainder
            // Remove the digit from the result and return
            res.erase(i, 1);
            std::reverse(res.begin(), res.end());
            return res;
        }

        if (res[i] % 3 == (remainder == 1 ? 2 : 1)) {
            (index[0] == -1 ? index[0] : index[1]) = i;
        }
    }

    if (index[0] != -1 && index[1] != -1) {
        // Got the 2 numbers that need to be removed
        // Remove from the result and return
        res.erase(index[1], 1);
        res.erase(index[0], 1);
        std::reverse(res.begin(), res.end());
    }

    return res;
}

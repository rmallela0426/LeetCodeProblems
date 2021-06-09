
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 816: Ambiguous Coordinates
 *
 * We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we removed
 * all commas, decimal points, and spaces and ended up with the string s.
 *
 * For example, "(1, 3)" becomes s = "(13)" and "(2, 0.5)" becomes s = "(205)".
 * Return a list of strings representing all possibilities for what our original coordinates
 * could have been.
 *
 * Our original representation never had extraneous zeroes, so we never started with numbers
 * like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented
 * with fewer digits. Also, a decimal point within a number never occurs without at least one
 * digit occurring before it, so we never started with numbers like ".1".
 *
 * The final answer list can be returned in any order. All coordinates in the final answer
 * have exactly one space between them (occurring after the comma.)
 *
 * Example 1:
 * Input: s = "(123)"
 * Output: ["(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"]
 *
 * Example 2:
 * Input: s = "(0123)"
 * Output: ["(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12, 3)"]
 * Explanation: 0.0, 00, 0001 or 00.01 are not allowed.
 *
 * Example 3:
 * Input: s = "(00011)"
 * Output: ["(0, 0.011)","(0.001, 1)"]
 *
 * Example 4:
 * Input: s = "(100)"
 * Output: ["(10, 0)"]
 * Explanation: 1.0 is not allowed.
 *
 * Constraints:
 * 4 <= s.length <= 12
 * s[0] == '(' and s[s.length - 1] == ')'.
 * The rest of s are digits.
*/
/*
 * input: "(123)"
 * First we will assign commas
 *               123
 *                |
 *            ----------
 *           |          |
 *         1, 23       12, 3
 *
 * Now we have 2 pairs after putting comma. Now try tp put the
 * decimal point
 *
 *         1, 2.3       1.2, 3
 * So there are total 4 combinations (1, 23), (1, 2.3), (12, 3), (1.2, 3)
 * While applying decimal point, we need to exclude the nos that are "00"
 * "0.0", "0.00", "1.0", "001", "00.01", ".1"
*/

//Function that will generate all nos (including decimal)
void generateNumbers(string s, vector<string>& out) {
    // If the string has only one character then there won't be any
    // decimal point, so pushing the num and returning
    if (s.length() == 1) {
        out.push_back(s);
        return;
    }

    // Check if the first char is zero or not
    if (s[0] != '0') {
        // The first char is not zero, so we have a valid number and one
        // combination, push it to res
        // Eg: s = 12 for input 123, then 12 is one combination of input.
        out.push_back(s);
    }
    else {
        // First char is zero, check if the last char is zero, if so the
        // number had extraneous zeros which is not valid. If last char is
        // not zero then we add a decimal point after the first char and
        // return from the function
        // Eg: s = "01230" return empty vecctor
        //     s = "01234" return 0.1234
        if (s.back() != '0') {
            out.push_back("0." + s.substr(1));
        }

        return;
    }

    // Check if the last char is 0, if so return
    // Eg: s = "10" skip as 1.0 not allowed
    if (s.back() == '0') {
        return;
    }

    // Now that we have valid numbers, loop all characters and find the
    // decimal combinations.
    for (int i = 1; i < s.length(); i++) {
        out.push_back(s.substr(0, i) + "." + s.substr(i));
    }

    return;
}

vector<string> ambiguousCoordinates(string s) {
    // Generate a string by excluding open and close
    // brackets
    string s2 = s.substr(1, s.length() - 2);

    // Variable to store the length of input
    int n = s2.length();

    // Vector to store result
    vector<string> res;
    // Left and right vectors are for storing the number combinations for
    // left and right values
    vector<string> left;
    vector<string> right;

    // Traverse each char in string starting from 1 as we need
    // at least one char
    for (int i = 1; i < n; i++) {
        // Generate the left half and right half ie.., if input is 123
        // below logic will generate it as 1 and 23
        // Send it to generate numbers function to get the decimal nos
        // out of it
        generateNumbers(s2.substr(0, i), left);
        generateNumbers(s2.substr(i), right);

        // Now that we have all combinations for this number, put it in
        // result by adding space between nos and open and close brackets
        for (string& lnum : left) {
            for (string& rnum : right) {
                res.push_back("(" + lnum + ", " + rnum + ")");
            }
        }
        // Clear the vectors for the next set of generated nums
        left.clear();
        right.clear();
    }

    // return the result
    return res;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1047: Remove All Adjacent Duplicates In String
 *
 * You are given a string s consisting of lowercase English letters. A duplicate removal
 * consists of choosing two adjacent and equal letters and removing them.
 *
 * We repeatedly make duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made. It can be
 * proven that the answer is unique.
 *
 * Example 1:
 * Input: s = "abbaca"
 * Output: "ca"
 * Explanation:
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal,
 * and this is the only possible move.  The result of this move is that the string is "aaca",
 * of which only "aa" is possible, so the final string is "ca".
 *
 * Example 2:
 * Input: s = "azxxzy"
 * Output: "ay"
 *
 * Constraints:
 * 1 <= s.length <= 105
 * s consists of lowercase English letters.
*/
/*
 * Approach followed is a greedy solution, where we traverse
 * each character of the input string. Check whether current
 * char is last char in the resultant string if so, pop the
 * last char from string. If not, then push it to resultant
 * string.
*/
string removeDuplicates(string s) {
    // string to store the result
    string res = "";

    // Traverse all characters in input string
    for (char& ch : s) {
        // Check if current char is the last char in res
        if (ch == res.back()) {
            // Char is same as previous char, remove previous
            // char from res
            res.pop_back();
        }
        else {
            // Previous, current char are different and push it
            // result
            res += ch;
        }
    }

    return res;
}

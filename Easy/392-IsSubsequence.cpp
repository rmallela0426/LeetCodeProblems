
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 392: Is Subsequence
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string that is formed from the original string by
 * deleting some (can be none) of the characters without disturbing the relative positions
 * of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 *
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 * Constraints:
 * 0 <= s.length <= 100
 * 0 <= t.length <= 104
 * s and t consist only of lowercase English letters.
 *
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and
 * you want to check one by one to see if t has its subsequence. In this scenario, how would
 * you change your code?
*/
/*
 * Approach followed is greedy algorithm where an idx initalized
 * to 0 of string s.
 * Traverse all the characters in t, increment the idx only if
 * the curren char of t matches with the char at idx in S. once
 * all the chars of s are found we can return true saysing s is a
 * subsequence of t. Incase if all the chars of t are elapsed, then
 * s is not a subsequence of t.
 *
*/
bool isSubsequence(string s, string t) {
    // check if s is empty or not
    if (s.empty()) {
        // s is empty, empty string is always a subsequence of t
        return true;
    }

    // check if t is empty or not
    if (t.empty()) {
        // t is empty, s is not a subsequence of t
        return false;
    }

    // Initialize an idx to size of string s
    int idx = 0;

    // Traverse all chars of t
    for (char& ch : t) {
        // Check if the current char matches with char at idx in s
        if (ch == s[idx]) {
            // current char matches, moves to next char in s
            idx++;

            // Check if we are done with all chars in s
            if (idx == s.size()) {
                // we are done with all chars in s ie.., s is a subsequence
                // of t
                return true;
            }
        }
    }

    return false;

}

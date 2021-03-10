
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 459: Repeated Substring Pattern
 *
 * Given a string s, check if it can be constructed by taking a substring
 * of it and appending multiple copies of the substring together.
 *
 * Example 1:
 * Input: s = "abab"
 * Output: true
 * Explanation: It is the substring "ab" twice.
 *
 * Example 2:
 * Input: s = "aba"
 * Output: false
 *
 * Example 3:
 * Input: s = "abcabcabcabc"
 * Output: true
 * Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 *
 * Constraints:
 * 1 <= s.length <= 104
 * s consists of lowercase English letters.
*/


bool repeatedSubstringPattern(string s) {
    // Used KMP algorithm. Basically finding the largest suffix which is also prefix
    // To find that KMP lookup table needs to be generated
    int lookup[s.length()];

    // Generate the kMP loop table that calculates the longest suffix that is also a prefix
    int i = 0;
    // There won't be any proper suffix at index 0, so
    lookup[0] = 0;

    // As index 0 is done, proceed to generate the table form index 1
    for (int j = 1; j < s.length(); ) {
        if (s[i] == s[j]) {
            // If chars at i and j are matching, then there is a prefix that matching the suffix
            // store the i + 1 at j and procced further
            lookup[j] = ++i;
            j++;
        }
        else {
            // If the char doesn't match, then if i > 0, then contents at i -1 will be i and
            // should compare with contents of s[j]
            i > 0 ? (i = lookup[i - 1]) : (lookup[j++] = 0);
        }
    }

    int length = lookup[s.length() - 1];
    // If there exist a suffix which is also prefix AND Length of the remaining substring
    // divides total length, then str[0..n-len-1] is the substring that repeats n/(n-len) times
    return length > 0 && s.length() % (s.length() - length) == 0;
}

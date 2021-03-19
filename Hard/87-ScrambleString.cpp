
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 87: Scramble String
 *
 * We can scramble a string s to get a string t using the following algorithm:
 *   . If the length of the string is 1, stop.
 *   . If the length of the string is > 1, do the following:
 *   . Split the string into two non-empty substrings at a random index, i.e.,
 *     if the string is s, divide it to x and y where s = x + y.
 *   . Randomly decide to swap the two substrings or to keep them in the same order.
 *     i.e., after this step, s may become s = x + y or s = y + x.
 *   . Apply step 1 recursively on each of the two substrings x and y.
 *
 * Given two strings s1 and s2 of the same length, return true if s2 is a scrambled
 * string of s1, otherwise, return false.
 *
 * Example 1:
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * Explanation: One possible scenario applied on s1 is:
 * "great" --> "gr/eat" // divide at random index.
 * "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep
 *                          them in order.
 * "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings.
 *                              divide at ranom index each of them.
 * "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and
 *                                  to keep the second substring in the same order.
 * "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at"
 *                                    to "a/t".
 * "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the
 *                                      same order.
 * The algorithm stops now and the result string is "rgeat" which is s2.
 * As there is one possible scenario that led s1 to be scrambled to s2, we return true.
 *
 * Example 2:
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 *
 * Example 3:
 * Input: s1 = "a", s2 = "a"
 * Output: true
 *
 * Constraints:
 * s1.length == s2.length
 * 1 <= s1.length <= 30
 * s1 and s2 consist of lower-case English letters.
*/
/*
 * Recursive Approach or TopDown Approach
 *
 * There are n-1 ways to split the string into 2 parts L, R where L is the length of s1
 * For Eg:
 *   s1 = "XY"   s2 = "YX"
 *
 * Partition s1 at 1
 *            XY
 *             |
 *          ---------
 *         |         |
 *         X         Y
 * 2 ways to merge the stirng
 *       . without swaping - XY
 *       . with swapping - YX
 *  It is seen from above that s1 and s2 are scrambled.
 *
 * Pseudo Code:
 * Partition the strings(s1, s2) into 2 parts to form x and y
 *        s1(0...j), s1(j+1...n)
 *        s2(0...j), s2(j+1...n)   where j = 1.. n-1
 *
 *  Both the stirng are scramble only if
 *        s1(0..j) & s2(0..j) are equal and s1(j+1...n) & s2(j+1...n) are equal
 *                               or (swap is allowed)
 *        s1(0..j) & s2(j+1...n) are equal and s1(j+1...n) & s2(0...j) are equal
 *
 * As there are many duplicate subproblems, implementing dynamic programming with
 * memorization
*/
// DP table to store the result of subproblems ie.., whether the subproblems
// s2 is scramble string of s1 or not.
std::unordered_map<string, bool> dp;

bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) {
        // Both are different sizes, then s2 can't be scramble of s1
        return false;
    }
    // Check if both the strings are equal
    if (s1 == s2) {
        // Both strings are equal i.e.., s2 is a scramble stirng of s1
        return true;
    }
    // Initializing the key key with s1 and s2 with * as differentiator
    string key = s1 + "*" + s2;
    // Check if the subproblem is already evaluated
    if (dp.count(key) == 1) {
        // Subproblem is already evaluated
        return dp[key];
    }

    int n = s1.length();
    int res = false;

    // Partition the string, As both the strings of equal length
    for (int i = 1; i < s1.length(); i++) {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) {
            res = true;
            break;
        }
        if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) &&
            isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) {
            res = true;
            break;
        }
    }

    dp[key] = res;
    return res;
}

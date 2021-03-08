/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 115: Distinct Subsequences
 *
 * Given two strings s and t, return the number of distinct subsequences of
 * s which equals t.
 * A string's subsequence is a new string formed from the original string by
 * deleting some (can be none) of the characters without disturbing the remaining
 * characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while
 * "AEC" is not).
 *
 * It is guaranteed the answer fits on a 32-bit signed integer.
 *
 * Example 1:
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * rabbbit
 * rabbbit
 * rabbbit
 *
 * Constraints:
 * 0 <= s.length, t.length <= 1000
 * s and t consist of English letters.
*/
/*
 * Recursive Approach or TopDown Approach
 *
 * If the last char of s1 matches the last char of t, then there are 2 possibilites
 * or 2 sub problems, one  excluding the last char from s1 and second is excluding
 * the last char from s1 and t
 * case 1: There may cases where the last char of t can occur multiple times in s1,
 *         so excluding the last char in s1.
 * case 2: Find whether whole string of t matches the s1 i.e.., excluding the last
 *         chars of s1 and t
 * Eg:
 * s1 - "abcdd" s2 - "abcd" => numDistinct("abcd", "abcd") +
 *                             numDistinct("abcd", "abc")
 *
 * If the last char of s1 doesn't matches last char of t, then evaluate subproblem
 * by removing the last char of s1 to check whether t is a subsequence of s1
 * Eg:
 * s1 - "abcd" s2- "abde" => numDistinct("abcd", "abde")
 *
 * Base Cases:
 * . If both s1 and t are empty then there will be 1 subsequence of s1 which equals t
 * . If string s1 is empty and t is not empty then t willn't subsequence of s, result is 0
 * . If string t is empty and s is not empty, then t will be subsequence of s i.e...,
 *   "" is always a substring/subsequence of s
*/
int numDistinct(string s, string t) {
    if (s.empty() && t.empty()) {
        // Both the strings are empty, then t is subsequence of s
        return 1;
    }

    if (s.empty() || t.empty()) {
        // If s is empty and t is not empty, then t is not a subsequence of s
        // If t is empty and s is not empty, then t is a subsequence of s ie..,
        //  "" is always a substring/subsequence of s
        return t.empty();
    }

    string sWithOutLastChar = s.substr(0, s.length() - 1);
    string tWithOutLastChar = t.substr(0, t.length() - 1);

    if (s[s.length() - 1] == t[t.length() - 1]) {
        // If both last chars are matching, need to evaluate the subproblems by excluding
        // the last char from s and other subproblem by excluding both the last chars from
        // s and t
        return numDistinct(sWithOutLastChar, t) + numDistinct(sWithOutLastChar, tWithOutLastChar);
    }

    // If last chars doesn't match then subsequence should be found in excluding last char of s
    return numDistinct(sWithOutLastChar, t);
}

/*
 * numDistinct BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main problem
 * can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find bottom solutions first to yield the top solution i.e.., solution of
 * the problem
 *
 * problem is to find whether t can be a distinct subsequence of string S. Need to find num of distinct subsequences
 * by deleting none or more characters
 * string S on rows and string t on colums in dp table
 * i-> index of s, j-> index of t
 *
 * dp table will be of length [i+1][j+1], +1 is to store when the strings are empty
 *
 * Cases:
 * . If both the strings are empty, then t is subsequence of s, so add 1
 *                      dp[0][0] = 1
 * . If the input string s is empty, t is not empty then t will not be a subsequence of s
 *                      dp[0][j] = 0  1 <= j < t.length()
 * . If the string t is empty, s is not then "" will always be a substring or subsequence of s
 *                      dp[i][0] = 1  1 <= i < s.length()
 * . If the characters of s and t at i, j are equal then there will 2 subproblems one was to exclude the characters to
 *   check whether all other characters matching or not, the other subproblem is to just exclude last character of s
 *                       dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
 * . If the characters of s and t at i, j are not equal, then there will be only one subproblem where to exclude the
 *   last character of s as to see whether t is subsequence of s
 *                       dp[i][j] = dp[i-1][j]
 */
int numDistinct_BU(string s, string t) {
    //dp array to store the intermediate results of subproblems
    vector<vector<long long>> dp(s.length() + 1, vector<long long>(t.length() + 1, 0));

    // Empty substrings, t is always subsequence of s
    dp[0][0] = 1;

    // Fill the first row and first colume i.e.., either S is empty or t is empty
    for (int col = 1; col <= t.length(); col++) {
        dp[0][col] = 0;
    }

    for (int row = 1; row <= s.length(); row++) {
        dp[row][0] = dp[row - 1][0];
    }

    for (int row = 1; row <= s.length(); row++) {
        for (int col = 1; col <= t.length(); col++) {
            dp[row][col] = dp[row - 1][col];
            if (s[row - 1] == t[col - 1]) {
                dp[row][col] += dp[row - 1][col - 1];
            }
        }
    }
    return dp[s.length()][t.length()];
}

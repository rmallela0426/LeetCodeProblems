
/*
*  Author: Raghavendra Mallela
*/

/*
Problem Statement:
Leetcode 44. WildCard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input: s = "acdcb", p = "a*c?b"
Output: false
*/

/* TopDown or recursive approach
 * if the pattern is empty, return true only when the i/p str is empty
 * If the ip str is empty, solution is true if the pattern has all '*', other wise false
 *
 * If the last character is matching, then there is a solution, needs to evaluate other subproblems by
 * excluding the last characters.
 *
 * If the last character in pattern is '?' i.e.., it matches any single char in ip str, then there is a
 * solution, needs to evaluate other subproblems by excluding the last characters.
 * Eg: s = "ab" p = "b"  or   s =  "ab" p = "a?"
 *   isMatch("a", ""); or isMatch("a", "a");
 *
 * If the last characters doesn't match, then return false as no point to evaluate other sub problems
 *
 * If the last character of pattern is '*' then there can be possibility of excluding the '*' as it can
 * be an empty char or excluding the last char of ip str as
 * Eg: "ab" p = "a*"
 *     isMatch("ab", "a") || ("a", "a*")
*/
bool isMatch(string s, string p) {
    if (p.empty()) {
        // Pattern is empty that means there will be match if input string is empty.
        return s.empty();
    }

    if (s.empty()) {
        // If ip is empty, then the pattern should have all '*' wild char other wise return false
        for (char& ch : p) {
            if (ch != '*')
                return false;
        }
        return true;
    }

    string sWithOutLastChar = s.substr(0, s.length() - 1);
    string pWithOutLastChar = p.substr(0, p.length() - 1);

    if (s[s.length() - 1] == p[p.length() - 1] || p[p.length() - 1] == '?') {
        // If last char matches or if last char in pattern is '?', then  there is a solution for this subproblem,
        // need to evaluate for other subproblems
        return isMatch(sWithOutLastChar, pWithOutLastChar);
    }

    if (p[p.length() - 1] == '*') {
        // If the last char in pattern is '*' where '*' Matches any sequence of characters (including the empty sequence).
        // Then the solution should be result of including and excluding the last chars of the strings
        return isMatch(s, pWithOutLastChar) || isMatch(sWithOutLastChar, p);
    }

    // If the last chars doesn't match, then return false
    return false;
}

/*
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find botto solutions first to yield the top solution i.e.., solution of
 * the problem
*/
bool isMatch_BU(string s, string p) {
    // DP Table to store the intermediate results and +1 to store the results for empty string
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, false));

    // if both ip str and pattern is empty
    dp[0][0] = true;
    for (int col = 0; col <= p.length() && p[col] == '*'; col++)
    {
        dp[0][col + 1] = true;
    }

    // If pattern is empty, then true if ip str is empty
    for (int row = 0; row < s.length(); ++row) {
        dp[row + 1][0] = false;
    }

    /*
    * follow the conditions of top down where if the characters are matching or if pattern char is '?',
    * then  solution  = dp [n-1][m-1]
    * If the pattern char is '*' then solution is
    *    solution = dp[n][m-1] || dp[n-1][m]
    * If the last char doesn't match, then it should be false
    */
    for (int row = 1; row <= s.length(); row++) {
        for (int col = 1; col <= p.length(); col++) {
            if (s[row - 1] == p[col - 1] || p[col - 1] == '?') {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else if (p[col - 1] == '*') {
                dp[row][col] = dp[row - 1][col] || dp[row][col - 1];
            }
            // Chars doesn't match need to keep false, but the dp is initialized with false;
        }
    }

    return dp[s.length()][p.length()];
}

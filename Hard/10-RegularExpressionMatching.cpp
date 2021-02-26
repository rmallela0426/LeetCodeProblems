
/*
*  Author: Raghavendra Mallela
*/

/*
Problem Statement:
LeetCode 10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
Input: s = "mississippi", p = "mis*is*p*."
Output: false

Constraints:
0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

/* TopDown or recursive approach
 * if the pattern is empty, return true only when the i/p str is empty
 * If the ip str is empty, solution is true if the pattern has '*', other wise false
 *
 * If the last character is matching, then there is a solution, needs to evaluate other subproblems by
 * excluding the last characters.
 *
 * If the last character in pattern is '.' i.e.., it matches any single char in ip str, then there is a
 * solution, needs to evaluate other subproblems by excluding the last characters.
 * Eg: s = "ab" p = "b"  or   s =  "ab" p = "a."
 *   isMatch_regex("a", ""); or isMatch_regex("a", "a");
 *
 * If the last character of pattern is '*' then the last before char of p should match with last char of S,
 * if so exclude that char and proceed further
 * Eg: "ab" p = "b*"
 *     isMatch_regex("a", "b*") || ("ab", "")
*/

bool isMatch_regex(string& s, string& p, int idxS, int idxP) {
    if (idxP < 0) {
        // pattern is empty, true if string is empty else false
        return idxS < 0;
    }
    if (idxS < 0) {
        // If ip string is empty, need to check if the if pattern has characters in it
        int numChars = 0;
        for (int i = 0; i <= idxP; i++) {
            numChars++;
            if (p[i] == '*')
                numChars = 0;
            else if (numChars > 1)
                return false;
        }
        return numChars == 0;
    }

    // If the last char matches, or pattern has '.', then there is
    // solution for this subproblem, need to evaluate for other
    // subproblems.
    if (s[idxS] == p[idxP] || p[idxP] == '.') {
        return isMatch_regex(s, p, idxS - 1, idxP - 1);
    }

    bool answer = false;
    if (p[idxP] == '*') {
        // If the last char is '*', then the last before char of p should match with last char of S,
        // if so exclude that char and proceed further
        if (s[idxS] == p[idxP - 1] || p[idxP - 1] == '.') {
            answer = isMatch_regex(s, p, idxS - 1, idxP);
        }

        answer = answer || isMatch_regex(s, p, idxS, idxP - 2);
    }

    return answer;
}

/*
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find botto solutions first to yield the top solution i.e.., solution of
 * the problem
*/
bool isMatch_regex_BU(string s, string p) {
    // DP Table to store the intermediate results and +1 to store the results for empty string
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, false));

    // if both ip str and pattern is empty
    dp[0][0] = true;

    // If pattern is empty, then all rows for which the chars are not empty are false
    for (int row = 0; row < s.length(); row++) {
        dp[row + 1][0] = false;
    }

    // If the ip string is rempty
    for (int col = 0; col < p.length(); col++)
    {
        dp[0][col + 1] = p[col] == '*' ? dp[0][col - 2 + 1] : false;
    }

    /*
    * follow the conditions of top down where if the characters are matching or if pattern char is '.',
    * then  solution  = dp [n-1][m-1]
    * If the pattern char is '*' then
    * check s[idxS] == p[idxP - 1] || p[idxP - 1] == '.' then
    *       solution  = dp[n-1][m] || dp[n][m-2]
    * else
    *       solution = dp[n][m-2]
    * If the last char doesn't match, then it should be false
    */
    for (int row = 1; row <= s.length(); row++) {
        for (int col = 1; col <= p.length(); col++) {
            // Chars doesn't match need to keep false
            bool answer = false;
            if (s[row - 1] == p[col - 1] || p[col - 1] == '.') {
                answer = dp[row - 1][col - 1];
            }
            else if (p[col - 1] == '*') {
                if (s[row - 1] == p[col - 2] || p[col - 2] == '.') {
                    answer = dp[row - 1][col];
                }
                answer = answer || dp[row][col - 2];
            }
            dp[row][col] = answer;
        }
    }
    return dp[s.length()][p.length()];
}
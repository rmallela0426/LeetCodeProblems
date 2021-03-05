
/*
 *  Author: Raghavendra Mallela
*/

/*
 * LeetCode 97: Interleaving String
 *
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
 * An interleaving of two strings s and t is a configuration where they are divided into
 * non-empty substrings such that:
 *
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
 * Note: a + b is the concatenation of strings a and b.
 *
 * Example1:
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 *
 * Example 2:
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 *
 * Example 3:
 * Input: s1 = "", s2 = "", s3 = ""
 * Output: true
 *
 * Constraints:
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1, s2, and s3 consist of lower-case English letters.
*/
/*
 * Recursive Approach
 * check char by char starting from the last from s3 and compare with s1, s2
 *
 * If the last char of s3 matches the last char of s1 and last char of s2, then there will
 * be 2 sub problems, one  excluding the last char from s1 and second is excluding the last
 * char from s2
 * Eg:
 * s1 - "aeb" s2 - "dcb" s3 - "adecbb" => isInterleave("aeb", "dc", "adecb") ||
 *                                        isInterleave("ae", "dcb", "adecb")
 *
 * If the last char of s3 matches last char of s2, then there is a solution for this subproblem
 * need to evaluate for the remaining subproblems
 * Eg:
 * s1 - "aeb" s2- "dcg" s3 - "adecbg" => isInterleave("aeb", "dc", "adecb")
 *
 * If the last char of s3 matches last char of s1, then there is a solution for this subproblem
 * need to evaluate for the remaining subproblems
 * Eg:
 * s1 - "aeb" s2- "dcg" s3 - "dacegb" => isInterleave("ae", "dcg", "daceg")
 *
 * Base Cases:
 * If both s1, s2 are empty and s3 is also empty then return true
 * The interleaved string should be of length s3
 * If either of the strings are empty, then s3 should be same as s1 or s2
 *
*/

bool isInterleave(string s1, string s2, string s3) {
    if (s1.empty() && s2.empty()) {
        // If both the input strings are empty, then return true only if
        // s3 is empty
        return s3.empty();
    }
    if (s1.length() + s2.length() != s3.length()) {
        // The interleaved string should have all the characters of s1 and s2,
        // the length of interleaved string should match with s3, if not
        // return false
        return false;
    }

    if (s1.empty() || s2.empty()) {
        // If the either of s1 or s2 is empty, then the other string should be
        // compared with s3. If equal then true other wise false
        return s3.compare(s1.empty() ? s2 : s1) == 0;
    }

    string s1WithOutLastChar = s1.substr(0, s1.length() - 1);
    string s2WithOutLastChar = s2.substr(0, s2.length() - 1);
    string s3WithOutLastChar = s3.substr(0, s3.length() - 1);

    if (s1[s1.length() - 1] == s3[s3.length() - 1] &&
        s2[s2.length() - 1] == s3[s3.length() - 1]) {
        // If the last char matches both the last chars of both the strings, then
        // evaluate the subproblems by excluding the last char of either of input
        // strings
        return isInterleave(s1, s2WithOutLastChar, s3WithOutLastChar) ||
            isInterleave(s1WithOutLastChar, s2, s3WithOutLastChar);
    }
    else if (s1[s1.length() - 1] == s3[s3.length() - 1]) {
        // IF the last char of s3 matches last char of s1, then there is a solution
        // and needs to evaluate exclude the last char of s1
        return isInterleave(s1WithOutLastChar, s2, s3WithOutLastChar);
    }
    else if (s2[s2.length() - 1] == s3[s3.length() - 1]) {
        // IF the last char of s3 matches last char of s2, then there is a solution
        // and needs to evaluate exclude the last char of s2
        return isInterleave(s1, s2WithOutLastChar, s3WithOutLastChar);
    }

    return false;
}

/*
 * isInterleave BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main problem
 * can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find bottom solutions first to yield the top solution i.e.., solution of
 * the problem
 *
 * string s1 on x-axis and s2 on Y-axis
 * i-> index of s1, j-> index of s2
 *
 * If the i+j-1 char of s3 matches char of s1 at index i and char of s2 at index j, then there will
 * be 2 sub problems, one  excluding the last char from s1 and second is excluding the last
 * char from s2
 * Eg:
 * s1 - "aeb" s2 - "dcb" s3 - "adecbb" => dp[i-1][j] || dp[i][j-1]
 *
 * If the i+j-1 char of s3 matches char of s2 at index j, then there is a solution for this
 * subproblem need to evaluate for the remaining subproblems
 * Eg:
 * s1 - "aeb" s2- "dcg" s3 - "adecbg" => dp[i][j]  = dp[i][j-1]
 *
 * If the i+j-1 char of s3 matches char of s1 at index i, then there is a solution for this
 * subproblem need to evaluate for the remaining subproblems
 * Eg:
 * s1 - "aeb" s2- "dcg" s3 - "dacegb" => dp[i-1][j]
*/
bool isInterleave_BU(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
        // The interleaved string should have all the characters of s1 and s2,
        // the length of interleaved string should match with s3, if not
        // return false
        return false;
    }

    // DP table to store the solutions of subproblems. Length of dp array
    // is length of s1 + 1 and length of s2 + 1. +1 is for storing the
    // result of subproblem if s1 or s2 empty
    // s1 is on x-axis ie.. rows and s2 is on y-axis ie... cols
    vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));

    // when both the stirngs are empty, ie.., at row and col is zero 
    dp[0][0] = true;
    // Fill the initial col ie..., col = 0
    for (int row = 1; row <= s1.length(); row++) {
        if (s1[row - 1] == s3[row - 1])
            dp[row][0] = dp[row - 1][0];
    }

    // Fill the initial row ie..., row = 0
    for (int col = 1; col <= s2.length(); col++) {
        if (s2[col - 1] == s3[col - 1])
            dp[0][col] = dp[0][col - 1];
    }

    // Loop to fill the dp table based on the conditions mentioned above
    for (int row = 1; row <= s1.length(); row++) {
        for (int col = 1; col <= s2.length(); col++) {
            if (s3[row + col - 1] == s1[row - 1] && s3[row + col - 1] == s2[col - 1]) {
                // The char at i, j location in s3 is matching with both chars of s1 and s2
                dp[row][col] = dp[row - 1][col] || dp[row][col - 1];
            }
            else if (s3[row + col - 1] == s2[col - 1]) {
                dp[row][col] = dp[row][col - 1];
            }
            else if (s3[row + col - 1] == s1[row - 1]) {
                dp[row][col] = dp[row - 1][col];
            }
            // else false as the vector is initalized with false no need of else case
        }
    }
    return dp[s1.length()][s2.length()];
}


/*
*  Author: Raghavendra Mallela
*/

/*
LeetCode 72: Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

/*
 * TopDown Approach or Recursive approach
 *
 * If the last character matches, then we have a solution and we can remove the last characters
 * and find the solution for the subproblem
 * i.e.., for Eg("sea", "tea")  ->   editDistance("se", "te");
 *
 * If the last character doesn't match, then it should be 1 (operation of insert, replace, delete)
                    + min return value of either of the remaining subproblems
 * for Ex: b, ba  or ba, bu or ba, b
 * n is the length of string s1
 * m is the length of string s2
 *
 * In Eg 1 s1-> b s2->ba, inorder to transform s1 to s2 we need to add a to s1 so that it is equal
 * to s2. By adding a character to s1, then length becomes s1.length() + 1, remaining subproblems
 * needs to be evaluated to get the final distance ie..,
 *          1(operation of inserting) + editDistance("b", "b") => 1 + editDistance(n, m-1)
 *
 * In Eg 2 s1->ba s2->bu, replace the end character 'a' in s1 to 'u' so that s1 can be transformed
 * to s2, now the remaining subproblems(characters) needs to be evaluated to get final distance to
 * transform s1 to s2 i.e..,
 *          1(operation of replacing) + editDistance("b", "b") => 1 + editDistance(n-1, m-1)
 *
 * In Eg 3 s1-> ba s2->b, delete the end character 'a' in s1 so that s1 can be transformed to s2,
 * now remaining subproblems needs to be evaluated to get the final disatance ie..,
 *          1(operation of deletion) + editDistance("b", "b") => 1 + editDistance(n-1, m)
 *
 * If both strings are equal, then there result is zero.
 * If either of the string is empty, then the result is length of other string,
*/
int editDistance(string word1, string word2) {
    if (word1 == word2) {
        // Both the words are equal, no operation is required
        // to transform word1 to word2
        return 0;
    }

    if (word1.empty()) {
        // If string s1 is empty, in order to transform s1 to s2 then all characters needs to be
        // added from s2 to s1 
        return word2.empty();
    }

    if (word2.empty()) {
        // If string s2 is empty, in order to transform s1 to s2, then all characters from s1 needs
        // to be deleted
        return word1.length();
    }

    string word1WithOutLastChar = word1.substr(0, word1.length() - 1);
    string word2WithOutLastChar = word2.substr(0, word2.length() - 1);

    if (word1[word1.length() - 1] == word2[word2.length() - 1]) {
        // Last character is same, solution for the problem is solution for the remaining suproblems
        return editDistance(word1WithOutLastChar, word2WithOutLastChar);
    }

    // If the last character doesn't match, then it should be 1 (operation of insert, replace, delete)
    // + min return value of either of the remaining subproblems
    int smallest = std::min(editDistance(word1, word2WithOutLastChar), editDistance(word1WithOutLastChar, word2WithOutLastChar));
    return 1 + std::min(smallest, editDistance(word1WithOutLastChar, word2));
}

/*
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find botto solutions first to yield the top solution i.e.., solution of
 * the problem
*/
int editDistance_BU(string word1, string word2) {
    // DP table to store the intermediate results and the length is word1.length() +1 and word2 + 1
    // x axis  is word1, y axis is word2
    vector<vector<int>> dp(word2.length() + 1, vector<int>(word1.length() + 1, 0));

    /*
     * follow the conditions of top down where if the last characters are matching, then
     *    solution  = dp [n-1][m-1]
     * If the last char doesn't match, then it should be 1 + min of subproblems
     *    solution = 1 + min(dp[n][m-1], dp[n-1][m-1], dp[n-1][m]
    */
    for (int row = 0; row <= word2.length(); row++) {
        for (int col = 0; col <= word1.length(); col++) {
            if (row == 0 || col == 0) {
                dp[row][col] = row == 0 ? col : row;
            }
            else if (word1[col - 1] == word2[row - 1]) {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else {
                int smallest = std::min(dp[row][col - 1], dp[row - 1][col - 1]);
                dp[row][col] = 1 + std::min(smallest, dp[row - 1][col]);
            }
        }
    }
    return dp[word2.length()][word1.length()];
}

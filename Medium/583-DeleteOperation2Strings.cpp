/*
*  Author: Raghavendra Mallela
*/

/*
LeetCode 583: Delete Operation for Two Strings

Given two words word1 and word2, find the minimum number of steps required to make
word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/
/*
 * TopDown Approach or Recursive approach
 *
 * If the last character matches, then we have a solution and we can remove the last characters
 * and find the solution for the subproblem
 * i.e.., for Eg("sea", "tea")  ->   minDistance("se", "te");
 *
 * If the last character doesn't match, then it should be min return value of eithe the solution
 * min(minDistance("sea", "te") + 1 , minDistance("se", "tea") + 1);
 *
 * If either of the string is empty, then the result is length of other string,
*/
int minDistance(string word1, string word2) {
	// if both strings are empty return 0
	if (word1.empty() && word2.empty())
		return 0;

	// If either of the strings are empty, then result is to remove all characters from the other stirng
	if (word1.empty() || word2.empty()) {
		return word1.empty() ? word2.length() : word1.length();
	}

	string s1WithOutLastChar = word1.substr(0, word1.length() - 1);
	string s2WithOutLastChar = word2.substr(0, word2.length() - 1);

	char s1LastChar = word1[word1.length() - 1];
	char s2LastChar = word2[word2.length() - 1];

	if (s1LastChar == s2LastChar) {
		/* Both the last characters are matched i.e..., there is a solution
		 * for this subproblem and need to calculate for other problems
		*/
		return minDistance(s1WithOutLastChar, s2WithOutLastChar);
	}

	/* Last char is not match then Compete the subproblems whoever have the result
	 * will have the solution for this problem.
	*/
	return std::min(1 + minDistance(word1, s2WithOutLastChar), 1 + minDistance(s1WithOutLastChar, word2));
}

/*
 * Bottomup Approach
 *
 * Creating an 2 dimensional array of dimensions lenghts1+1, lengths2+1, which holds all the
 * results of the subproblem, same as topdown approach
 *
 */
int minDistance_BU(string s1, string s2) {
	/* DP Cache table to hold subproblems
	 * s2 will be on rows & s1 will be on columns
	 * +1 to hold the solution for an "" string */
	int** dp = new int *[s2.length() + 1];
	for (int i = 0; i < s2.length() + 1; i++) {
		dp[i] = new int[s1.length() + 1];
	}

	for (int s2row = 0; s2row <= s2.length(); s2row++) {
		for (int s1col = 0; s1col <= s1.length(); s1col++) {
			// If either of are zero then the min required is to remove alll the characters in the string  
			if (s2row == 0 || s1col == 0)
				dp[s2row][s1col] = s2row + s1col;
			else if (s1[s1col - 1] == s2[s2row - 1]) {
				/* there is match */
				dp[s2row][s1col] = dp[s2row - 1][s1col - 1];
			}
			else {
				dp[s2row][s1col] = std::min(1 + dp[s2row - 1][s1col], 1 + dp[s2row][s1col - 1]);
			}

		}
	}
	int ans = dp[s2.length()][s1.length()];

	for (int i = 0; i < s2.length() + 1; i++) {
		delete[] dp[i];
	}
	delete[] dp;

	return ans;
}

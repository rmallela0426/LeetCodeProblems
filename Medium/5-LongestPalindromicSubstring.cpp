
/*
*  Author: Raghavendra Mallela
*/

/*
 * LeetCode 5: Longest Palindromic Substring
 * Given a string s, return the longest palindromic substring in s.
 *
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 *
 * Example 3:
 * Input: s = "a"
 * Output: "a"
 *
 * Example 4:
 *
 * Input: s = "ac"
 * Output: "a"
 *
 * Constraints:
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters (lower-case and/or upper-case),
*/

/* TopDown or recursive approach
 * if the pattern is empty, return true only when the i/p str is empty
 * If the ip str is empty, solution is true if the pattern has all '*', other wise false
 *
 * If the last character is matching, then there is a solution, needs to evaluate other subproblems by
 * excluding the last characters and if the subproblems also are palidrome, then lenght is
 *   eg: "abba"   ->  2 + longestPalindromeString("bb")
 *
 * If the last characters doesn't match, then longest palindrome can be max of subproblems excluding
 * either of the characters
 *   eg: "abbac"  -> max(longestPalindromeString("abba"), longestPalindromeString("bbac");
*/

int longestPalindromeString(string& s, int start, int end, int& ssidx, int& sslength) {
    // If the start is greater than end, then we are done
    // with the string. return 0
    if (start > end)
        return 0;

    // If start and end are same ie.., pointing to same char and single
    // char is always palindrome
    if (start == end) {
        if (sslength < 1) {
            sslength = 1;
            ssidx = start;
        }
        return 1;
    }

    if (s[start] == s[end]) {
        // Last characters match, then the remaining substring need to be checked if
        // palidrome or not.
        int remainingLength = end - start - 1;
        if (remainingLength == longestPalindromeString(s, start + 1, end - 1, ssidx, sslength)) {
            // Substring is palindrome, so calculate the length of the substring
            // and update the idx. +2 is last chars match.
            remainingLength += 2;
            // If the substring length is greater than current length, then update
            if (remainingLength > sslength) {
                // Update the substring idx and length.
                ssidx = start;
                sslength = remainingLength;
            }
            return remainingLength;
        }
    }

    return std::max(longestPalindromeString(s, start, end - 1, ssidx, sslength), longestPalindromeString(s, start + 1, end, ssidx, sslength));
}

string longestPalindrome_recursive(string s) {
    if (s.empty())
        return "";

    // ssIdx corresponds to start index of longest Palidrome
    // sslength corresponds to length of palindrome string
    // default it is 1 as each char is palindrome
    int ssidx = 0;
    int sslength = 1;

    // Recursive function to get the longest palindrome substring
    longestPalindromeString(s, 0, s.length() - 1, ssidx, sslength);

    return s.substr(ssidx, sslength);
}

/*
 * Longest palindromic Substring BottomUp solution
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find botto solutions first to yield the top solution i.e.., solution of
 * the problem
 * If the last chars are matching then we need to see remaining substring excluding both chars are also palindrome
 * If so, calcluate the length.
*/
string longestPalindrome_BU(string s) {
    // Base cases where the string is empty or string length is 1
    if (s.empty() || s.length() == 1)
        return s;

    // dp array to store the whether the substring is palindrome or not
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

    // ssIdx corresponds to start index of longest Palidrome
    // sslength corresponds to length of palindrome string
    // default it is 1 as each char is palindrome
    int ssidx = 0;
    int sslength = 1;

    // Fill the dp table with the diagnols first so that it will be same character
    for (int i = 0; i < s.length(); i++)
        dp[i][i] = 1;

    // Logic is that if the first and last chars match, then we need to see whether
    // substring excluding is also palindrome eg: abda -> we need to check bd whether
    // it is palindrome or not.
    // so the dp table is filled from the last
    for (int row = s.length() - 2; row >= 0; --row) {
        for (int col = row + 1; col < s.length(); col++) {
            if (s[row] == s[col]) {
                // Last chars are matching need to check whether the row+1, col -1 substring
                // also palindrome. As the dp table is filled only upper half(from diagnol),
                // condition col - row = 1 to handle the cornor case of having 2 adjacent chars
                // together ie.., abb
                if (dp[row + 1][col - 1] || col - row == 1) {
                    // substring is also palindrome
                    dp[row][col] = true;
                    if (col - row + 1 > sslength) {
                        sslength = col - row + 1;
                        ssidx = row;
                    }
                }
            }
        }
    }
    return s.substr(ssidx, sslength);
}


int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s) {
    if (s.empty())
        return "";
    int start = 0, length = 0;

    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = std::max(len1, len2);
        if (len > length) {
            start = i - (len - 1) / 2;
            length = len;
        }
    }
    return s.substr(start, length);
}

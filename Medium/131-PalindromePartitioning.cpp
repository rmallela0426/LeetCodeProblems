
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 131: Palindrome Partiotining
 *
 * Given a string s, partition s such that every substring of the partition
 * is a palindrome. Return all possible palindrome partitioning of s.
 * A palindrome string is a string that reads the same backward as forward.
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 *
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * Constraints:
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
*/
/*
 * Approach followed is partition at specific intervaland check if each
 * substring is palindrome or not. If the length of string is S, then
 * there are n-1 partition.
 * For eg: s = "aab"
 *             aab
 *              |
 *          -----------
 * part = 1|           | part = 2
 *       a, ab        aa, b
 *
 * Check if left substring "a" is palindrome or not. If palindrome then
 * right substring can be partitioned and and see whether it is palindrome
 * or not.
*/
bool isPalindrome(string s) {
    int r = s.length();
    for (int l = 0; l < r >> 1; l++) {
        if (s[l] != s[r - 1 - l]) {
            return false;
        }
    }
    return true;
}

void helper(string s, vector<string>& current, vector<vector<string>> &res) {
    // If the stirng is empty there are no palindromes then 
    // return the current to result
    if (s.empty()) {
        res.push_back(current);
        return;
    }

    // Partition starting from 1
    for (int i = 1; i <= s.length(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (isPalindrome(left)) {
            current.push_back(left);
            helper(right, current, res);
            // current result is pushed to res vector, popping the contents from
            // current to store the next set of palindromes.
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> current;

    helper(s, current, res);

    return res;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leecode 696: Count Binary SubStrings
 *
 * Give a string s, count the number of non-empty (contiguous) substrings that
 * have the same number of 0's and 1's, and all the 0's and all the 1's in these
 * substrings are grouped consecutively.
 * Substrings that occur multiple times are counted the number of times they occur.
 *
 * Example 1:
 * Input: "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive 1's and
 * 0's: "0011", "01", "1100", "10", "0011", and "01".
 *
 * Notice that some of these substrings repeat and are counted the number of times they
 * occur.
 * Also, "00110011" is not a valid substring because all 0's (and 1's) are not grouped
 * together.
 *
 * Example 2:
 * Input: "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of
 * consecutive 1's and 0's.
 *
 * Note:
 * s.length will be between 1 and 50,000.
 * s will only consist of "0" or "1" characters.
*/
int countBinarySubstrings(string s) {
    int res = 0;
    // curr is 1 this is for the char at idx 0
    int prev = 0, curr = 1;

    int i = 1;
    while (i < s.length()) {
        if (s[i] == s[i - 1]) {
            curr++;
        }
        else {
            res += min(prev, curr);
            prev = curr;
            curr = 1;
        }
        i++;
    }
    return res += min(prev, curr);
}

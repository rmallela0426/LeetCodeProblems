

/*
 *  Author: Raghavendra Mallela
*/

/*
 * LeetCode 686: Repeated string Match
 *
 * Given two strings a and b, return the minimum number of times you should
 * repeat string a so that string b is a substring of it. If it is impossible
 * for b​​​​​​ to be a substring of a after repeating it, return -1.
 *
 * Notice: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and
 * repeated 2 times is "abcabc".
 *
 * Example 1:
 * Input: a = "abcd", b = "cdabcdab"
 * Output: 3
 * Explanation: We return 3 because by repeating a three times "abcdabcdabcd",
 *              b is a substring of it.
 *
 * Example 2:
 * Input: a = "a", b = "aa"
 * Output: 2
 *
 * Constraints:
 * 1 <= a.length <= 104
 * 1 <= b.length <= 104
 * a and b consist of lower-case English letters.
*/

/*
 * Algorithm used is KMP, where
 * Find the largest suffix which is prefix
 * Return len + 1
*/
int repeatedStringMatch(string a, string b) {
    if (a == b) {
        // If both the strings are equal then there will be one time to repeat the
        // a sothat b become substring of a
        return 1;
    }

    // Used KMP algorithm. Basically finding the largest suffix which is also prefix
    // To find that KMP lookup table needs to be generated
    int lookup[b.length() + 1]; // +1 to avoid extra 

    // Generate the kMP loop table that calculates the longest suffix that is also a prefix
    int i = 0;
    // There won't be any proper suffix at index 0, so
    lookup[0] = 0;
    lookup[1] = 0;

    // As index 0 is done, proceed to generate the table form index 1
    for (int j = 1; j < b.length(); ) {
        if (b[i] == b[j]) {
            // If chars at i and j are matching, then there is a prefix that matching the suffix
            // store the i + 1 at j and procced further
            lookup[++j] = ++i;
        }
        else {
            // If the char doesn't match, then if i > 0, then contents at i -1 will be i and
            // should compare with contents of s[j]
            i > 0 ? (i = lookup[i]) : (lookup[++j] = 0);
        }
    }

    for (int i = 0, j = 0; i < a.length(); i += max(1, j - lookup[j]), j = lookup[j]) {
        while (j < b.size() && a[(i + j) % a.size()] == b[j]) ++j;
        if (j == b.size()) {
            return (i + j - 1) / a.size() + 1;
        }
    }
    return -1;
}

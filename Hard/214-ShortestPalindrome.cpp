
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 214 Shortest Palindrome
 * Given a string s, you can convert it to a palindrome by adding characters
 * in front of it. Find and return the shortest palindrome you can find by
 * performing this transformation.
 *
 * Example 1:
 * Input: s = "aacecaaa"
 * Output: "aaacecaaa"
 *
 * Example 2:
 * Input: s = "abcd"
 * Output: "dcbabcd"
 *
 * Constraints:
 * 0 <= s.length <= 5 * 104
 * s consists of lowercase English letters only.
 *
*/

/*
 * Algorithm used is KMP - knath, Morris, Pratt algorithm
 * Eg: abab  -> rev is baba
 *   add it at end such that it becomes ababbaba, this is palindrome but the solution should
 *   be smallest, so need to find the proper suffix in reverse string that matches the
 *   proper suffix of input string and needs to be evaluated from the reverse string and
 *   insert remaining at the front of ip string.
 *
 * proper suffix or proper prefix of a string is not equal to the string itself
 * proper suffixes of reverse string baba are -    a,   ba,  aba,
 * proper prefixes of iput string abab are - a   , ab  , aba ,
 * From above it is clearly seen that longest proper suffix that matches prefix are aba,
 * so the result is
 *   removal of the length of the common prefix sufix substring + ip string ie...
 *       b + abab => babab
 *
 * In short it goes in following steps
 * 1. generate reverse of ip string
 * 2. s + rev_s
 * 3. Find the longest suffix of the appended string that is also prefix of the appended string
 * 4. (rev_s - largest suffix) + ip string
 *
 * For step 3, KMP lookup table needs to be generated, in order to generate the KMP lookup the
 * string shouldn't overlap so step 2 becomes s + '#' + rev_s  # is used in order for the strings
 * not to overlap. Without #, the stirngs could mix eachother and produce wrong results.
 * for eg: if ip is aaaa, then rev string also aaaa and appended string is aaaaaa. The longest
 * would be of length 7 which is wrong, so a delimetter is added in between.
*/
string shortestPalindrome(string s) {
    // Base case - If string is empty return
    if (s.empty())
        return s;

    // step 1: generate reverse of ip string
    string rev_s(s.rbegin(), s.rend());

    // step 2: Append the ip and reverse strings
    // # delimiter is used for the string not to overlap and not to produce wrong results
    string a_s = s + '#' + rev_s;

    // step 3: Find the longest suffix that is also a prefix.
    // array to store the longest suffix
    std::vector<int> lookup(a_s.length());

    // Generate the kMP loop table that calculates the longest suffix that is also a prefix
    int i = 0;
    // There won't be any proper suffix at index 0, so
    lookup[0] = 0;

    // As index 0 is done, proceed to generate the table form index 1
    for (int j = 1; j < a_s.length();) {
        if (a_s[i] == a_s[j]) {
            // If chars at i and j are matching, then there is a prefix that matching the suffix
            // store the i + 1 at j and procced further
            lookup[j] = ++i;
            j++;
        }
        else {
            // If the char doesn't match, then if i > 0, then contents at i -1 will be i and
            // should compare with contents of s[j]
            i > 0 ? (i = lookup[i - 1]) : (lookup[j++] = 0);
        }
    }

    // step 4: generate the shortest palindrome
    return rev_s.substr(0, rev_s.length() - lookup.back());
}

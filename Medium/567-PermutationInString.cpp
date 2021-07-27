
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 567: Permutation In String
 *
 * Given two strings s1 and s2, return true if s2 contains the permutation of s1.
 * In other words, one of s1's permutations is the substring of s2.
 *
 * Example 1:
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 * Example 2:
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 * Constraints:
 * 1 <= s1.length, s2.length <= 104
 * s1 and s2 consist of lowercase English letters.
*/
/*
 * Approach followed is a sliding window technique
 *  . freq array is generated for all characters in s1
 *  . As we need to check whether s1 is a permutation of s2, the
 *    max window size will be size of s1. Let the length of s1
 *    is k.
 *  . Generate a freq map for the first k characters of s2 as the
 *    window size of k
 *  . Initialize the window variables wstart and wstart to 0 and
 *    s1.length().
 *  . Traverse the loop while wEnd reaches the end of s2.
 *  . Check if the freqs of s1 and s2 are equal, if so there is a
 *    permutation of s1 in s2. If not, update the frequencies of
 *    characters at wstart and wend in s2.
*/
bool checkInclusion(string s1, string s2) {
    // Base case: When either of the strings are empty or size of
    // s2 is less than size of s1
    if (s1.empty() || s2.empty() || s2.length() < s1.length()) {
        // Either of the strings are empty or length of s2 is smaller
        // than length of s1, in which case it should return false.

        return s1.empty() && s2.empty();
    }

    // vector to store the frequencies of chars in s1
    // As the input string contains only lower case letters
    vector<int> s1freq(26, 0);
    // vector to store the frequencies of chars in s2 for the first k
    // chars of s2 where k is the length of s1
    vector<int> s2freq(26, 0);


    // Fill the frequencies of all the chars in s1
    // Fill the freq of s2 ie.. max of k chars
    for (int i = 0; i < s1.length(); i++) {
        s1freq[s1[i] - 'a']++;
        s2freq[s2[i] - 'a']++;
    }

    // Initialize the Window variables, window size is s1.length
    int wStart = 0;
    int wEnd = s1.length();

    // Traverse the window while all chars of s2 are done
    while (wEnd < s2.length()) {
        // Check the frequencies of s1 and the curr windows of s2 are equal
        if (s1freq == s2freq) {
            // A permutation of s1 is availale in s2, returning true
            return true;
        }

        // Update the freq of the chars at wstart and wend
        s2freq[s2[wEnd] - 'a']++;
        s2freq[s2[wStart] - 'a']--;

        // Move the window
        wStart++;
        wEnd++;
    }

    // Cornor case when the permutation of s1 is available at the end of s2,
    // check the frequencies of s1 and s2
    return s1freq == s2freq;
}

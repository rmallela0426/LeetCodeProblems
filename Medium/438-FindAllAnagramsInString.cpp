
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 438: Find All Anagrams in String
 *
 * Given two strings s and p, return an array of all the start indices of p's anagrams
 * in s. You may return the answer in any order.
 *
 * Example 1:
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 * Example 2:
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 * Constraints:
 * 1 <= s.length, p.length <= 3 * 104
 * s and p consist of lowercase English letters.
*/
/*
 * Approach followed is a sliding window technique
 *  . freq array is generated for all characters in input string p
 *  . As we need to find all start indices of anagrams of p in string s
 *    the max window size will be size of p. Let the length of string p
 *    is k.
 *  . Generate a freq map for the first k characters of string s as the
 *    window size is of k
 *  . Initialize the window variables wstart and wstart to 0 and p.length()
 *  . Traverse the loop while wEnd reaches the end of string s.
 *  . Check if the freqs of s1 and s2 are equal, if so then there exists a
 *    anagram of p in s, push the index to result.
*/
vector<int> findAnagrams(string s, string p) {
    // Base case: When either of the strings are empty or size of s is less
    // than size of p
    if (p.empty() || s.empty() || s.length() < p.length()) {
        // Either of the strings are empty or length of s2 is smaller
        // than length of s1, in which case it should return false.

        return {};
    }

    // vector to store the frequencies of chars in string p
    // As the input string contains only lower case letters, the size of the
    // vector is 26
    vector<int> pfreq(26, 0);
    // vector to store the frequencies of chars in s for the first k chars of
    // p where k is the length of s1
    vector<int> sfreq(26, 0);


    // Fill the frequencies of all the chars in p and freq of string s ie..
    // max of k chars
    for (int i = 0; i < p.length(); i++) {
        pfreq[p[i] - 'a']++;
        sfreq[s[i] - 'a']++;
    }

    // vector to store the result
    vector<int> res;

    // Initialize the window variables, window size is length of string p
    int wStart = 0;
    int wEnd = p.length();

    // Traverse the window while all chars of s2 are done
    while (wEnd < s.length()) {
        // Check the frequencies of p and s are equal
        if (pfreq == sfreq) {
            // An angram of p is availale in s
            res.push_back(wStart);
        }

        // Update the freq of the chars at wstart and wend
        sfreq[s[wEnd] - 'a']++;
        sfreq[s[wStart] - 'a']--;

        // Move the window
        wStart++;
        wEnd++;
    }

    // Cornor case where the anagram is present at the end of the input string s
    if (pfreq == sfreq) {
        // An angram of p is availale in s
        res.push_back(wStart);
    }

    return res;
}

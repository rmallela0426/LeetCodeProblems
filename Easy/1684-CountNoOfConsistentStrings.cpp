
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetode 1684: Count Number Of Consistent strings
 *
 * You are given a string allowed consisting of distinct characters and an
 * array of strings words. A string is consistent if all characters in the
 * string appear in the string allowed.
 *
 * Return the number of consistent strings in the array words.
 *
 * Example 1:
 * Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
 * Output: 2
 * Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
 *
 * Example 2:
 * Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
 * Output: 7
 * Explanation: All strings are consistent.
 *
 * Example 3:
 * Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
 * Output: 4
 * Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 *
 * Constraints:
 * 1 <= words.length <= 104
 * 1 <= allowed.length <= 26
 * 1 <= words[i].length <= 10
 * The characters in allowed are distinct.
 * words[i] and allowed contain only lowercase English letters.
*/
int countConsistentStrings(string allowed, vector<string>& words) {
    // Calculate the frequencies of the allowed string
    // As there are only 26 lower case letters and the
    // constraint said only 26 letters
    bool freq[26];
    // fill it with false
    memset(freq, 0, sizeof(freq));

    // fill the freq array
    for (char& ch : allowed) {
        // Char is available initialize true for that
        // index which specifies that the char is present
        // in string allowed
        freq[ch - 'a'] = true;
    }

    // Variable to store num of consistent strings
    int numConsistentStrings = 0;

    // Loop all word
    for (string& word : words) {
        // Tells whether the word is consistent or not
        bool isConsistent = true;

        // check whether the chars in the current word are
        // allowed or not.
        for (char& ch : word) {
            if (!freq[ch - 'a']) {
                // char is not allowed, current string is not
                // consistent, no need to check other chars in
                // the string
                isConsistent = false;
                break;
            }
        }

        // Increment if the current string is consistent i.e..,
        // all the chars in the current string are formed with
        // chars in allowed.
        numConsistentStrings += isConsistent;
    }

    // Return the total no of consistent strings
    return numConsistentStrings;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1832: Check if hte sentence Is Pangram
 *
 * A pangram is a sentence where every letter of the English alphabet appears
 * at least once.
 * Given a string sentence containing only lowercase English letters, return
 * true if sentence is a pangram, or false otherwise.
 *
 * Example 1:
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
 * Output: true
 * Explanation: sentence contains at least one of every letter of the English alphabet.
 *
 * Example 2:
 * Input: sentence = "leetcode"
 * Output: false
 *
 * Constraints:
 * 1 <= sentence.length <= 1000
 * sentence consists of lowercase English letters.
*/
bool checkIfPangram(string sentence) {
    // array to store the frequencies of chars in a
    // sentence. Storing false as default values
    std::bitset<26> bset;

    // calculate the frequencies of chars in the input
    for (char& ch : sentence) {
        bset[ch - 'a'] = true;
    }

    return bset.all();
}

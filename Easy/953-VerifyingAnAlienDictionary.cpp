
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 953: Verifying An Alien dictionary
 *
 * In an alien language, surprisingly they also use english lowercase
 * letters, but possibly in a different order. The order of the alphabet
 * is some permutation of lowercase letters.
 *
 * Given a sequence of words written in the alien language, and the order
 * of the alphabet, return true if and only if the given words are sorted
 * lexicographicaly in this alien language.
 *
 * Example 1:
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence
                is sorted.
 * Example 2:
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1],
               hence the sequence is unsorted.
 * Example 3:
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string is
               shorter (in size.) According to lexicographical rules "apple" > "app",
               because 'l' > @, where @ is defined as the blank character which
               is less than any other character (More info).
 *
 * Constraints:
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are English lowercase letters.
 */
bool isAlienSorted(vector<string>& words, string order) {

    // Array to record the relations between each letter and
    // its ranking
    int mp[26];

    // Update the ranking of each letter into array
    for (int i = 0; i < order.length(); i++) {
        mp[order[i] - 'a'] = i;
    }

    // Iterate over the words and compare adjacent words
    for (int i = 0; i < words.size() - 1; i++) {
        string currentword = words[i];
        string nextword = words[i + 1];
        for (int j = 0; j < words[i].length(); j++) {
            // Examine the case when words are like ("apple", "app").
            if (j >= nextword.length()) {
                // current word is greater than nextword ie.., words
                // are not sorted
                return false;
            }

            // If we do not find a mismatch letter between words[i] and words[i + 1],
            if (currentword[j] != nextword[j]) {
                int currentWordChar = currentword[j] - 'a';
                int nextWordChar = nextword[j] - 'a';

                // Check if the chars of current word and next word are sorted
                // lexicographical.
                if (mp[currentWordChar] > mp[nextWordChar]) {
                    // not in lexicographical order
                    return false;
                }
                // if we find the first different letter and they are sorted,
                // then there's no need to check remaining letters
                else
                    break;
            }
        }
    }
    return true;
}


/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 318: Maximum Product of Word Lengths
 *
 * Given a string array words, return the maximum value of length(word[i]) * length(word[j])
 * where the two words do not share common letters. If no such two words exist, return 0.
 *
 * Example 1:
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 * Example 2:
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 * Example 3:
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 * Constraints:
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
*/
/*
 * As the constraints given are only lower case letters Approach
 * is to calculate a bit manipulation int for each input string
 * ie.., if a is present in the input string, then set 0th idx
 * of state variable for that string.
 * Eg: a-> 000000000000000000000001  = 1
 * Eg: ab -> 0000 0000 0000 0011 = 3
 * Eg: abc -> 0000 0000 0000 0111 = 7
 *
 * If two strings are different, then logical AND of their states
 * is zero.
 * Will take this into consideration, will calcualte the lengths
 *
 * Pseudo code:
 * . First find the states for each string in the input vector and
 *   find the corresponding int
 * . Now compare each string with other strings, if they are not
 *   same, calculate the product of their length and update the max
 *
*/
int maxProduct(vector<string>& words) {
    // Vector to store the state variables, equal to size of input
    // vector of words
    vector<int> states(words.size(), 0);

    // Traverse each word and calcualte the state
    for (int i = 0; i < words.size(); i++) {
        for (char& ch : words[i]) {
            // Set the bit for the current char
            states[i] |= 1 << (ch - 'a');
        }
    }

    // variable to store maxlength
    int maxlength = 0;

    // Iterate over each word and compare with the other words
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            // check if both strings are equal or not
            if ((states[i] & states[j]) == 0) {
                // Both the strings are not equal, evaluate the max length
                maxlength = max(maxlength, (int)(words[i].length() * words[j].length()));
            }
        }
    }

    return maxlength;
}

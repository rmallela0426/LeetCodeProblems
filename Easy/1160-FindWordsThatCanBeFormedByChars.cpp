
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1160: Find Words that can be formed by Characters
 *
 * You are given an array of strings words and a string chars.
 * A string is good if it can be formed by characters from chars (each character
 * can only be used once).
 * Return the sum of lengths of all good strings in words.
 *
 * Example 1:
 * Input: words = ["cat","bt","hat","tree"], chars = "atach"
 * Output: 6
 * Explanation:
 * The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
 *
 * Example 2:
 * Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * Output: 10
 * Explanation:
 * The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 *
 * Note:
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, chars.length <= 100
 * All strings contain lowercase English letters only.
*/
/*
 * Approach is first to find the frequencies of all chars in input chars
 * Iterate over each word and try to remove the characters
*/
int countCharacters(vector<string>& words, string chars) {
    // As constraint is that it has only lower case letters
    // we can have an array of 26 integers
    vector<int> freq(26, 0);

    // Calculate the frequencies of each char in chars
    for (char& ch : chars) {
        freq[ch - 'a']++;
    }

    // Vector to store the frequencies of chars in the word
    vector<int> wordfq(26, 0);
    int sum = 0;

    // Iterate over each word
    for (string& word : words) {
        sum += word.length();

        // calculate the freq
        for (char& ch : word) {
            wordfq[ch - 'a']++;

            // Check if word can be formed from chars 
            if (wordfq[ch - 'a'] > freq[ch - 'a']) {
                // Word can't be formed, subtract the length
                sum -= word.length();
                break;
            }
        }
        // clear all the values for the word freq vector
        fill(wordfq.begin(), wordfq.end(), 0);
    }

    return sum;
}

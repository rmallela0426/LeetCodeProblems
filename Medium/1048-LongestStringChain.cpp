
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1048: Longest String Chain
 *
 * Given a list of words, each word consists of English lowercase letters.
 * Let's say word1 is a predecessor of word2 if and only if we can add
 * exactly one letter anywhere in word1 to make it equal to word2. For
 * example, "abc" is a predecessor of "abac".
 * A word chain is a sequence of words
 *      [word_1, word_2, ..., word_k] with k >= 1,
 *   where word_1 is a predecessor of word_2, word_2 is a predecessor of
 *   word_3, and so on.
 * Return the longest possible length of a word chain with words chosen
 * from the given list of words.
 *
 * Example 1:
 * Input: words = ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: One of the longest word chain is "a","ba","bda","bdca".
 *
 * Example 2:
 * Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output: 5
 *
 * Constraints:
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of English lowercase letters.
*/
/*
 * Approach followed is the Dynamic Programming BottoUp approach
 * solution for each subproblem is stored in a map which stores
 * the maxlength of the word which is predecessor.
 * Input array is sorted in increasing order of length and iterating
 * over all words. For each word, try to delete each character and
 * try to check if it is available in the map,
 * If available ie.., predecessor, then add +1 to the previous length.
 * If not available ie.., not predecessor try to remove another char.
*/
int longestStrChain(vector<string>& words) {
    // Map to store the max length of the word ie., suproblem solution
    unordered_map<string, int> mp;

    // Lambda function which helps to sort the strings based on length
    auto comp = [&](string& str1, string& str2) {
        return str1.size() < str2.size();
    };

    // Sort the input array of string based on the length
    sort(words.begin(), words.end(), comp);

    // Variable to store the longest word length
    int longestWordLength = 0;

    // Iterate over all words
    for (string& word : words) {
        // variable to store current word length
        int currentWordLength = 1;

        // Iterate over all characters of current word
        for (int i = 0; i < word.length(); i++) {
            string predecessor = word;
            // Delete the character at index i
            predecessor.erase(predecessor.begin() + i);

            // Check if predecessor is available in map ie.., whether the
            // subproblem is already evaluated or not
            if (mp.count(predecessor) == 1) {
                // This subproblem is already evaluated
                currentWordLength = max(currentWordLength, mp[predecessor] + 1);
            }
        }

        // Store the solution for the current problem
        mp[word] = currentWordLength;
        longestWordLength = max(longestWordLength, currentWordLength);
    }

    return longestWordLength;
}

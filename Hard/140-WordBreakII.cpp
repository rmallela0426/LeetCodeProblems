
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 140: Word Break II
 * Given a string s and a dictionary of strings wordDict, add spaces
 * in s to construct a sentence where each word is a valid dictionary
 * word. Return all such possible sentences in any order.
 *
 * Note that the same word in the dictionary may be reused multiple times
 * in the segmentation.
 *
 * Example 1:
 * Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * Output: ["cats and dog","cat sand dog"]
 *
 * Example 2:
 * Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
 * Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: []
 *
 * Constraints:
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
*/
/*
 * TopDown Approach or Recursive Solution
 *
 * As the solution is to construct a sentence with the words that are in Dictionary,
 * Loop through each word in the dictionary and check if the word in dictionary is
 * found in s
 *    . If found, remove the word from s and do a recursive call to find remaining
 *      string in dictionary
 *    . If it is not found, move onto next word in dictionary
 *    . Once the sentence is found, return it to result.
 *
 * Base cases:
 * If string is empty, then return vector
 * If the ip string is found in the dictionary, then add to result and proceed.
*/
vector<string> wordBreakII(string s, vector<string>& wordDict) {
    // Vector to store the result
    vector<string> res;

    // Check if the string is empty
    if (s.empty()) {
        // input string is empty, returning an empty result as there
        // are no sentances that can formed.
        return res;
    }

    if (std::find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) {
        // Input string is found as a word in dictionary, add to result and proceed
        // to see if some if some other words can be found in the input string that
        // are in dictionary.
        res.push_back(s);
    }

    // Loop through all words in dictionary
    for (string word : wordDict) {
        // Generate a word which is of a legth of word in dictionary
        string left = s.substr(0, word.size());

        if (word == left) {
            // Word found in dictionary, generate other strings in the remaining substr
            vector<string> sentance = wordBreakII(s.substr(word.size()), wordDict);

            for (string sen : sentance) {
                // Constructing a space seperated sentence and push it to result.
                res.push_back(left + " " + sen);
            }
        }
    }

    // Return the result
    return res;
}

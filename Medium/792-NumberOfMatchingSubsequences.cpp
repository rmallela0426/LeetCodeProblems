
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 792: Number Of Matching Subsequences
 *
 * Given a string s and an array of strings words, return the number of words[i] that is a
 * subsequence of s.
 * A subsequence of a string is a new string generated from the original string with some
 * chars (can be none) deleted without changing the relative order of the remaining chars.
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 * Example 1:
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 *
 * Example 2:
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 *
 * Constraints:
 * 1 <= s.length <= 5 * 104
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 50
 * s and words[i] consist of only lowercase English letters.
*/

/*
 * Approach followed is a Hashmap + Binary search
 * where we save all indices of each char of s in a map ie..,
 * Eg:  s = abacedba
 *            key   value
 *     map =  [a]   0, 2, 7
 *            [b]   1, 6
 *            [c]   3
 *            [e]   4
 *
 * Now traverse each word in the input vector and check whether it is a
 * subsequence of s using a binary search approach
 *
 * Eg:  word = aad, traverse each char by char
 *   As a is present twice and in the map when we check for the 2nd char a
 * then we need to take the 2nd index instead of the 1st index.
 *
*/
int numMatchingSubseq(string s, vector<string>& words) {
    // Initialize a map to store the indicies of all chars in s
    unordered_map<char, vector<int>> mp;

    // Traverse all the chars in s and add the indices to map
    for (int i = 0; i < s.length(); i++) {
        // push the index to map for the current char
        // The indices will be in ascending order for the character
        mp[s[i]].push_back(i);
    }

    // Variable to store result
    int numSubseq = 0;

    // Temporary variables
    int low;
    bool isSubseq;

    // Traverse all the words of the input 
    for (string& word : words) {
        // Lower Index
        // Index that needs to be found should be greater than this low index
        low = -1;
        // Assume current word is a subsequence
        isSubseq = true;

        for (char& ch : word) {
            // Perform a binary search 
            int pos = upper_bound(mp[ch].begin(), mp[ch].end(), low) - mp[ch].begin();
            // Check if the current char is present in map or not
            if (pos == mp[ch].size()) {
                // no such char present,
                isSubseq = false;
                break;
            }

            low = mp[ch][pos];
        }

        // Increment result if current word is subsequence of s
        numSubseq += isSubseq;
    }

    return numSubseq;
}

/*
 * Approach followed is a Hashmap, which stores all the words of
 * same starting char into vector
 *
 * Traverse a loop that goes for all chars in s.
 *   . Retrieve the vector of words and delete the current char key from map
 *   . Retrieve all words which starts with current char, remove the starting
 *     char, if they are empty then that word is a subsequence increase the
 *     result.
 *   . Push the words based on the new starting char to map
 *
 *
*/
int numMatchingSubseq(string s, vector<string>& words) {
    // Initialize a map to store the indicies of all chars in s
    unordered_map<char, vector<string>> mp;

    // Traverse all words from the input and arrange it based on starting char
    for (string& word : words) {
        mp[word[0]].push_back(word);
    }

    // Variable to store result
    int numSubseq = 0;

    // Traverse all the chars in string s
    for (char& ch : s) {
        // check if key(current char) is available at map
        if (mp.count(ch) == 1) {
            // Retrieve all words that starts with current char
            vector<string> wrds(mp[ch]);

            // Delete the current entry in queue
            mp.erase(ch);

            // Traverse all words that starts with current char
            for (string& word : wrds) {
                // check if the current word has only one char
                if (word.size() == 1) {
                    // current word size is only 1 char, then this word is a subsequence
                    // of input string s
                    numSubseq++;
                }
                else {
                    // push the word to map based on the starting char excluding the current char
                    // Remove the first char and push the words to mp based on starting char
                    mp[word[1]].push_back(word.substr(1));
                }
            }
        }
    }

    return numSubseq;
}

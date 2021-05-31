
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 890: Find And Replace Pattern
 *
 * Given a list of strings words and a string pattern, return a list of words[i] that
 * match pattern. You may return the answer in any order.
 * A word matches the pattern if there exists a permutation of letters p so that after
 * replacing every letter x in the pattern with p(x), we get the desired word.
 * Recall that a permutation of letters is a bijection from letters to letters: every
 * letter maps to another letter, and no two letters map to the same letter.
 *
 * Example 1:
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
 * since a and b map to the same letter.
 *
 * Example 2:
 * Input: words = ["a","b","c"], pattern = "a"
 * Output: ["a","b","c"]
 *
 * Constraints:
 * 1 <= pattern.length <= 20
 * 1 <= words.length <= 50
 * words[i].length == pattern.length
 * pattern and words[i] are lowercase English letters.
*/
/*
 * Approach is to convert the pattern and each word in the input array to a
 * normalize string and compare ie..,
 * for Eg: abc => a->1, b->2, c->3
 *         abb => a->1, b->2, c->2
 * From above we can see that each char in the word starts with 0 and the
 * value will be incremented if the next char is not same as previous chars
 * i.e.., the chars whose value is not assigned.
 * Once we find the normalize string for each word, then compare with the
 * normalize string of the pattern.
*/
string normalize(string& inp) {
    // Create a HashMap to hold the normalize char
    map<char, char> mp;

    // Output string
    string normString = "";

    // Normalize the input string char by char
    for (char& ch : inp) {
        // check if the current char is normalized or not
        if (mp.count(ch) == 0) {
            // Current char is not normalized, assing a normalize char
            // Assigning map size because the size will changed based
            // on the chars that are pushed to map
            mp[ch] = mp.size();
        }
        // Generate the normalized string
        normString += mp[ch];
    }

    return normString;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    // Result vector
    vector<string> res;

    // convert the pattern to a normalize string
    pattern = normalize(pattern);

    // Loop each word, convert it to normalize and compare with pattern
    for (string& word : words) {
        // convert to normalized string and check with normaized pattern
        if (pattern == normalize(word)) {
            // word matches with pattern
            res.push_back(word);
        }
    }

    return res;
}

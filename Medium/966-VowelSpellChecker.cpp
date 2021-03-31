
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 966: Vowels Spell Checker
 *
 * Given a wordlist, we want to implement a spellchecker that converts
 * a query word into a correct word.
 * For a given query word, the spell checker handles two categories of
 * spelling mistakes:
 *  . Capitalization: If the query matches a word in the wordlist (case
 *                    -insensitive), then the query word is returned with
 *                    the same case as the case in the wordlist.
 *  Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
 *  Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
 *  Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
 *
 *  . Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u')
 *                  of the query word with any vowel individually, it matches
 *                  a word in the wordlist (case-insensitive), then the query
 *                  word is returned with the same case as the match in the
 *                  wordlist.
 *  Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
 *  Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
 *  Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
 *
 * In addition, the spell checker operates under the following precedence rules:
 *  . When the query exactly matches a word in the wordlist (case-sensitive),
 *    you should return the same word back.
 *  . When the query matches a word up to capitlization, you should return the
 *    first such match in the wordlist.
 *  . When the query matches a word up to vowel errors, you should return the
 *    first such match in the wordlist.
 *  . If the query has no matches in the wordlist, you should return the empty
 *    string.
 *
 * Given some queries, return a list of words answer, where answer[i] is the
 * correct word for query = queries[i].
 *
 * Example 1:
 * Input: wordlist = ["KiTe","kite","hare","Hare"],
 *        queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
 * Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 *
 * Example 2:
 * Input: wordlist = ["yellow"], queries = ["YellOw"]
 * Output: ["yellow"]
 *
 * Constraints:
 * 1 <= wordlist.length, queries.length <= 5000
 * 1 <= wordlist[i].length, queries[i].length <= 7
 * wordlist[i] and queries[i] consist only of only English letters.
*/
/*
 * Solution is to find the set of words that are queried should be present
 * in wordlist. For doing this, there are set of rules
 * Rules:
 * 1. If the word matches the wordlist, return the same word
 *    Eg: wordList- [kite], query - [kite] => o/p = [kite]
 *
 * 2. If the word matches the wordlists by doing a lowercase check, then
 *    word should be returned as same case in the wordlist
 *    Eg: wordList - [kite], query - [KITE, KiTE, KItE] => [kite, kite, kite]
 *
 * 3. If the wordList has same case-sensitive words and if the query word
 *    matches the word in wordlist by converting it to a lower-case, then
 *    word returned is the first such match in wordlist
 *    Eg: wordList - [KiTe, kite], query - [Kite] => [KiTe]
 *
 * 4. If the query word by replacing the vowels matches a word in wordlist,
 *    then word returned with same case as the first such match in wordlist
 *    Eg: wordList - [KiTe, kite], query - [keti] => [KiTe]
 *
 * 5. If query word is not found in wordlist, then word returned is an empty
 *    word
 *    Eg: wordList - [KiTe, kite], query - [keet] => []
*/
string lower(string word) {
    for (int i = 0; i < word.size(); i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

string vowelRemovedString(string word) {
    for (int i = 0; i < word.length(); i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            word[i] = '*';
        }
    }
    return word;
}

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    // Set to store the unique words from the wordlist
    std::unordered_set<string> uniqueWords;
    // Map to store the lowercase wordlist and original word
    std::unordered_map<string, string> mp;
    // Map to store the words after changing the vowels with '*'
    std::unordered_map<string, string> devowels;

    // Fill all the maps and sets
    for (string word : wordlist) {
        // push it in set
        uniqueWords.insert(word);

        // LowerCase Rule
        string lowercaseword = lower(word);
        if (mp.count(lowercaseword) == 0)
            mp[lowercaseword] = word;

        // Vowel Replacing rule
        string vowelreplacedword = vowelRemovedString(lowercaseword);
        if (devowels.count(vowelreplacedword) == 0)
            devowels[vowelreplacedword] = word;
    }

    // Loop over queries, returing results in queries
    for (int i = 0; i < queries.size(); i++) {
        string word = "";
        if (uniqueWords.count(queries[i]) == 1) {
            // Same word found in wordList
            // nothing to update
        }
        else if (mp.count(word = lower(queries[i])) == 1) {
            // Lower Case word is found, replace with the
            // first occurence of the word in wordlist
            queries[i] = mp[word];
        }
        else if (devowels.count(word = vowelRemovedString(word)) == 1) {
            // After replacing the vowels, the string is
            // present in the wordlist, return the first
            // matched word
            queries[i] = devowels[word];
        }
        else {
            // Nothing found, push empty string
            queries[i] = "";
        }
    }
    return queries;
}

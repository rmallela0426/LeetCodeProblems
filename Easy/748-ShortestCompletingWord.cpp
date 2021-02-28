
/*
*  Author: Raghavendra Mallela
*/

/*
 * LeetCode 748: Shortest Completing Word
 *
 * Given a string licensePlate and an array of strings words, find the shortest completing word in words.
 * A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces
 * in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate,
 * then it must appear in the word the same number of times or more.
 *
 * Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple
 * shortest completing words, return the first one that occurs in words.
 *
 * Example 1:
 * Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
 * Output: "steps"
 * Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
 * "step" contains 't' and 'p', but only contains 1 's'.
 * "steps" contains 't', 'p', and both 's' characters.
 * "stripe" is missing an 's'.
 * "stepple" is missing an 's'.
 * Since "steps" is the only word containing all the letters, that is the answer.
 *
 * Constraints:
 * 1 <= licensePlate.length <= 7
 * licensePlate contains digits, letters (uppercase or lowercase), or space ' '.
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 15
 * words[i] consists of lower case English letters.
*/

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    // Map to store the freq of the chars in license plate
    std::unordered_map<char, int> freq;
    // stores the min length of word required
    int minWordLength = 0;

    // Generate the freq of chars in license plate
    // As the chars in license plate is Case senstive, upper case
    // chars are converted to lower case and add it to map.
    for (char ch : licensePlate) {
        if (isalpha(ch)) {
            freq[tolower(ch)]++;
            minWordLength++;
        }
    }

    // variable to store shortest word of vector words
    string res = "";

    for (string word : words) {
        if (word.length() < minWordLength) {
            // No need to check this word as we need minWordLength of chars
            continue;
        }

        // temp array to store the freq of chars in license plate
        std::unordered_map<char, int> mp(freq);
        // Loop each char of the word
        for (char ch : word) {
            // Check if the char is present in the freq map
            if (mp.count(ch) > 0) {
                // Char is present in license plate and is needed
                // Decrement the freq of the char in temp map and remove the char
                // if we got the freq
                if (--mp[ch] == 0)
                    mp.erase(ch);
            }

        }
        // If the size of temp map is zero i.e.., all the chars in the license plate
        // are present in the word. Need to update if it is shortest.
        if (mp.size() == 0) {
            if (res == "")
                res = word;
            else if (word.length() < res.length())
                res = word;
        }
    }
    return res;
}
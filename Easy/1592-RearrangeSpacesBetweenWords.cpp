
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1592: Rearrange Spaces Between Words
 *
 * You are given a string text of words that are placed among some number of spaces. Each word
 * consists of one or more lowercase English letters and are separated by at least one space.
 * It's guaranteed that text contains at least one word.
 *
 * Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent
 * words and that number is maximized. If you cannot redistribute all the spaces equally, place
 * the extra spaces at the end, meaning the returned string should be the same length as text.
 *
 * Return the string after rearranging the spaces.
 *
 * Example 1:
 * Input: text = "  this   is  a sentence "
 * Output: "this   is   a   sentence"
 * Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces
 * between the words: 9 / (4-1) = 3 spaces.
 *
 * Example 2:
 * Input: text = " practice   makes   perfect"
 * Output: "practice   makes   perfect "
 * Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space.
 * We place this extra space at the end of the string.
 *
 * Example 3:
 * Input: text = "hello   world"
 * Output: "hello   world"
 *
 * Example 4:
 * Input: text = "  walks  udp package   into  bar a"
 * Output: "walks  udp  package  into  bar  a "
 *
 * Example 5:
 * Input: text = "a"
 * Output: "a"
 *
 * Constraints:
 * 1 <= text.length <= 100
 * text consists of lowercase English letters and ' '.
 * text contains at least one word.
*/
string reorderSpaces(string text) {
    // Check if the input string is empty or not
    if (text.empty()) {
        // input string is empty, return ""
        return "";
    }

    // Vector to store all words in input string
    vector<string> words;
    // variable to store num of spaces
    int numSpaces = 0;

    // string to save the word
    string word = "";

    // Traverse all charecters in input string, count all spaces
    // retrieve the words and push it to a vector
    for (char& ch : text) {
        // Check if the current char is a space if so increment the count
        // else add it to the word list
        if (ch == ' ') {
            numSpaces++;
        }
        else {
            word += ch;
        }

        // Check if we got a word
        if (ch == ' ' && !word.empty()) {
            // Got a word, push it to vector
            words.push_back(word);
            word = "";
        }
    }

    // If there is a word left ie.., the last word
    if (!word.empty()) {
        words.push_back(word);
    }

    // Generate the output string
    word = "";

    int n = words.size();

    // num spaces to be applied in between the words
    int count = n > 1 ? numSpaces / (n - 1) : numSpaces;

    // Traverse all the words and append the words
    for (int i = 0; i < n; i++) {
        // append the current word to result
        word += words[i];

        // check if this is not a last word
        if (i < n - 1) {
            // Current word is not a last word, append spaces
            word.append(count, ' ');
        }
    }

    // append any extra spaces
    count = n > 1 ? numSpaces % (n - 1) : numSpaces;
    word.append(count, ' ');

    return word;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1189: Maximum Number of Balloons
 *
 * Given a string text, you want to use the characters of text to form as
 * many instances of the word "balloon" as possible.
 *
 * You can use each character in text at most once. Return the maximum number of instances that can be formed.
 *
 * Example 1:
 * Input: text = "nlaebolko"
 * Output: 1
 *
 * Example 2:
 * Input: text = "loonbalxballpoon"
 * Output: 2
 *
 * Example 3:
 * Input: text = "leetcode"
 * Output: 0
 *
 * Constraints:
 * 1 <= text.length <= 10^4
 * text consists of lower case English letters only.
*/
int maxNumberOfBalloons(string text) {
    // Variable to store the frequencies of chars
    // in the input string
    std::vector<int> freq(26, 0);

    // Calculate the frequencies
    for (char ch : text) {
        freq[ch - 'a']++;
    }

    // As char l & o are repeated twice in ballon, decrement
    // the count by 1.
    freq['l' - 'a'] >>= 1;
    freq['o' - 'a'] >>= 1;

    // Initialize to MAX element
    int count = INT_MAX;
    // Loop all chars of ballon and find the min times the string is formed
    string str = "balon";
    for (char ch : str) {
        if (freq[ch - 'a'] >= 0)
            count = std::min(count, freq[ch - 'a']);
    }

    return count;
}

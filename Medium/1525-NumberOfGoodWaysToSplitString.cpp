
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1525: Number Of Good Ways to Split String
 *
 * You are given a string s, a split is called good if you can split s into 2 non-empty strings
 * p and q where its concatenation is equal to s and the number of distinct letters in p and q
 * are the same.
 *
 * Return the number of good splits you can make in s.
 *
 * Example 1:
 * Input: s = "aacaba"
 * Output: 2
 * Explanation: There are 5 ways to split "aacaba" and 2 of them are good.
 *  ("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
 *  ("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
 *  ("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
 *  ("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
 *  ("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
 *
 * Example 2:
 * Input: s = "abcd"
 * Output: 1
 * Explanation: Split the string as follows ("ab", "cd").
 *
 * Example 3:
 * Input: s = "aaaaa"
 * Output: 4
 * Explanation: All possible splits are good.
 *
 * Example 4:
 * Input: s = "acbadbaada"
 * Output: 2
 *
 * Constraints:
 * s contains only lowercase English letters.
 * 1 <= s.length <= 10^5
*/
/*
 * Approach is to save the frequencies of chars of s in a map.
 * Now traverse each character of input string 's' ie.,splitting
 * the string into 2 at that index. Now increment the frequecy of
 * char of left string and decrement frequency of right string.If
 * at any particular split left and right frequencies size matches
 * ie..,, has same no of distinct elements then it is a goodsplit
 * increment the count
*/
int numSplits(string s) {
    // Basecase: If input string is empty
    if (s.empty()) {
        // Input string is empty, nothing to split
        return 0;
    }

    // map to store the frequencies of input map
    unordered_map<char, int> rfreq;

    // Calculate the frequencies of input string
    for (char& ch : s) {
        // Increment the frequency of the current char
        rfreq[ch]++;
    }

    // map to store teh frequencies of left string after splitting
    unordered_map<char, int> lfreq;

    // Counter to store the total no of good strings
    int numGoodSplits = 0;

    // Traverse the input string for each char, so the string is
    // splitted into 2
    // For Eg: s = "aacaba"
    // 1st iteration, a   acaba
    // 2nd iteration, aa  caba
    // 3rd iteration, aac aba
    for (char& ch : s) {
        // Insert the current char into lfreq map and remove it from
        // right freq map.
        lfreq[ch]++;

        // decrease the frequency of current char and remove it from
        // map only if the frequecy of char is 0 ie.., all characters
        // are in left substring
        if (--rfreq[ch] == 0) {
            // Remove from the amp
            rfreq.erase(ch);
        }

        // Check if both left and right substrings has same num of chars
        // ie.., distinct chars
        if (lfreq.size() == rfreq.size()) {
            // Both substrings has distinct characters, which is a good
            // split
            numGoodSplits++;
        }
    }

    // return the num of good splits
    return numGoodSplits;
}

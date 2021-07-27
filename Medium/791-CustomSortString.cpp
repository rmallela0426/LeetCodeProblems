
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 791: Custom Sort String
 *
 * order and str are strings composed of lowercase letters. In order, no
 * letter occurs more than once.
 * order was sorted in some custom order previously. We want to permute
 * characters of str so that they match the order that order was sorted.
 * More specifically, if x occurs before y in order, then x should occur
 * before y in the returned string.
 * Return any permutation of str (as a string) that satisfies this property.
 *
 * Example:
 * Input:
 * order = "cba"
 * str = "abcd"
 *
 * Output: "cbad"
 * Explanation:
 * "a", "b", "c" appear in order, so the order of "a", "b", "c" should be
 * "c", "b", and "a".
 * Since "d" does not appear in order, it can be at any position in returned
 * string. "dcba", "cdba", "cbda" are also valid outputs.
 *
 * Note:
 * order has length at most 26, and no character is repeated in order.
 * str has length at most 200.
 * order and str consist of lowercase letters only.
*/
/*
 * Approach followed is using a greedy solution where frequencies
 * of characters are stored in a map. Traverse all characters of
 * the input order. Try checking if char is present in freq map,
 * if present append total no of current char to the output string
 * based on frequency. Remove freq of char frome map.
 * Once all chars of order is done, append the remaining chars from
 * the map.
 *
 * order: "trabed"
 * str: "abcdefe"
 * o/p = abeedcf
 * we can clearly see that 'e' should come before 'd', the total no
 * of 'e' in str should come before char 'd'.
 * This approach will add all the chars that are not present in input
 * at the end of the output string.
 *
*/
string customSortString(string order, string str) {
    // Base case: If the inputs are empty
    if (order.empty() || str.empty()) {
        return str;
    }

    // map to store the frequencies of the string str
    // as the constraint is that there will be only lower case letters
    // and there are 26 such letters defining an array of 26 ints
    vector<int> freq(26, 0);

    // Calculate the frequencies of the chars in string str
    for (char& ch : str) {
        // Increment the frequency of current char
        freq[ch - 'a']++;
    }

    // Reset the input string str
    str = "";

    // Traverse all the chars of the input order which are sorted
    // previously
    for (char& ch : order) {
        // Check if the current char is present in the input str
        if (freq[ch - 'a'] > 0) {
            // The current char is present in input string, need
            // to append all the count of chars in the output string
            str.append(freq[ch - 'a'], ch);
            // As the curr char is done, removing the char from map
            freq[ch - 'a'] = 0;
        }
    }

    // Append the left over chars in the frequency map
    for (int i = 0; i < freq.size(); i++) {
        // Check if there are any chars left or not
        if (freq[i] > 0) {
            // There are chars that needs to be appended.
            str.append(freq[i], i + 'a');
        }
    }

    return str;
}

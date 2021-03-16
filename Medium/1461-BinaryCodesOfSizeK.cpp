
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1461: Check if a string contains all Binary Codes of Size K
 *
 * Given a binary string s and an integer k.
 * Return True if every binary code of length k is a substring of s. Otherwise,
 * return False.
 *
 * Example 1:
 * Input: s = "00110110", k = 2
 * Output: true
 * Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They
 * can be all found as substrings at indicies 0, 1, 3 and 2 respectively.
 *
 * Example 2:
 * Input: s = "00110", k = 2
 * Output: true
 *
 * Example 3:
 * Input: s = "0110", k = 1
 * Output: true
 * Explanation: The binary codes of length 1 are "0" and "1", it is clear that both
 * exist as a substring.
 *
 * Example 4:
 * Input: s = "0110", k = 2
 * Output: false
 * Explanation: The binary code "00" is of length 2 and doesn't exist in the array.
 *
 * Constraints:
 * 1 <= s.length <= 5 * 10^5
 * s consists of 0's and 1's only.
 * 1 <= k <= 20
*/
/*
 * Logic is to find the substrings of length k in
 * a set which will be unique.
 * If the length of set is equal to 2^k, then all
 * substrings are present in the input string.
*/
bool hasAllCodes(string s, int k) {
    // There will be 2^k permutations of binary code for size k
    // set to store the unique substrings of input
    std::unordered_set<string> unique;

    // Loop all the characters in input
    // Loop until there are enough characters to get a substring
    for (int i = 0; i + k <= s.length(); i++) {
        // Generate a substring from index i and k characters
        // and add it to set
        unique.insert(s.substr(i, k));
    }

    // There will be 2^k permutations of binary code for size k
    // i.e.., for k = 2 there will 4 codes 00,01,10,11.
    // Check if the set has 2^k codes
    return unique.size() == (1 << k);
}


/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 383 Ransom Note
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the ransom
 * note can be constructed from the magazines ; otherwise, it will return false.
 *
 * Each letter in the magazine string can only be used once in your ransom note.
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 *
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 *
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
*/
bool canConstruct(string ransomNote, string magazine) {
    // Hash map to store the freq of letters from magazine
    std::map<char, int> freq;

    // Generate the freq of the letters in magazine
    for (char ch : magazine) {
        freq[ch]++;
    }

    // Loop for each letter in ransomNote and check whether it
    // is present in magazine. If not present return error
    for (char ch : ransomNote) {
        if (freq.count(ch) == 0)
            return false;
        else if (--freq[ch] == 0)
            freq.erase(ch);
    }

    return true;
}

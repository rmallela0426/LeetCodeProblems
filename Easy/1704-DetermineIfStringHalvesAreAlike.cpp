
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1704: Determine If strings halves are alike
 *
 * You are given a string s of even length. Split this string into two halves
 * of equal lengths, and let a be the first half and b be the second half.
 *
 * Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
 * 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
 * lowercase letters.
 *
 * Return true if a and b are alike. Otherwise, return false.
 *
 * Example 1:
 * Input: s = "book"
 * Output: true
 * Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
 *
 * Example 2:
 * Input: s = "textbook"
 * Output: false
 * Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
 * Notice that the vowel o is counted twice.
 *
 * Constraints:
 * 2 <= s.length <= 1000
 * s.length is even.
 * s consists of uppercase and lowercase letters.
*/

// function to check whether char is vowel or not
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

bool halvesAreAlike(string s) {
    // Variable to store no of vowels in first half and second
    // half of a string s
    int numVowels1 = 0;
    int numVowels2 = 0;

    // two pointers of string
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        numVowels1 += isVowel(s[start++]);
        numVowels2 += isVowel(s[end--]);
    }
    return numVowels1 == numVowels2;
}

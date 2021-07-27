
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 205: Isomorphic Strings
 *
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same char,
 * but a character may map to itself.
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 *
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 *
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 * Constraints:
 * 1 <= s.length <= 5 * 104
 * t.length == s.length
 * s and t consist of any valid ascii character.
*/
bool isIsomorphic(string s, string t) {
    // BaseCase: Where both strirngs S and T are of different lengths
    if (s.length() != t.length()) {
        // Both the strings are of different length, no need to check
        // they are not isomorphic
        return false;
    }

    // Map to store the char mapping from s to t
    unordered_map<char, char> stMap;

    // Set to store the t characters as no two characters of s should
    // map to same char of t ie..,
    //     s = ead   t = cac
    //  => e->c, a->a, 'd' shouldn't map to 'a' as 'e' already mapped
    // to c.
    unordered_set<char> st;

    // Temporary variables to store the current chars of s and t
    char sChar;
    char tChar;

    // Traverse all the characters of the string and check whether the
    // string s is isomorphic to t
    for (int i = 0; i < s.size(); i++) {
        // Retrieve the current chars at index i;
        sChar = s[i];
        tChar = t[i];

        // Check if the current char of string s is mapped to any char,
        // previously if so, the current char should map to the same char
        // as of previous char
        // Eg: s = aad  t = eef    a->e, for index i = 1, a is already in
        // map and it should  map to e
        // Check if char at s is previously mapped or not
        if (stMap.count(sChar)) {
            // The current char is already mapped to a char and the current
            // tChar is not same as previous mapped char
            if (stMap[sChar] != tChar) {
                return false;
            }
        }
        // Check if the current char at string t is already mapped to some
        // other char of s, if so the stirngs are not isomorphic as no two
        // chars shouldn't map to same character.
        else if (st.count(tChar)) {
            // Current char at string t is already mapped to a char in s
            return false;
        }

        // Push the mapping to a map
        stMap[sChar] = tChar;
        // push the char at t to the set
        st.insert(tChar);
    }

    // Checked all possibilities, the strings are isomorphic
    return true;
}

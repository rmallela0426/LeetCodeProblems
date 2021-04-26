
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1209: Remove All Adjacent Duplicates In a string
 *
 * Given a string s, a k duplicate removal consists of choosing k adjacent and equal
 * letters from s and removing them causing the left and the right side of the deleted
 * substring to concatenate together.
 *
 * We repeatedly make k duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made.
 * It is guaranteed that the answer is unique.
 *
 * Example 1:
 * Input: s = "abcd", k = 2
 * Output: "abcd"
 * Explanation: There's nothing to delete.
 *
 * Example 2:
 * Input: s = "deeedbbcccbdaa", k = 3
 * Output: "aa"
 * Explanation: 
 * First delete "eee" and "ccc", get "ddbbbdaa"
 * Then delete "bbb", get "dddaa"
 * Finally delete "ddd", get "aa"
 *
 * Example 3:
 * Input: s = "pbbcggttciiippooaais", k = 2
 * Output: "ps"
 *
 * Constraints:
 * 1 <= s.length <= 10^5
 * 2 <= k <= 10^4
 * s only contains lower case English letters.
*/
/*
 * Approach is to use the stack
*/
string removeDuplicates(string s, int k) {
    // stack to store the indices of the chars
    // that are not duplicate
    stack<int> st;
    // push the 0th index to stack
    st.push(0);

    // Loop from 1st char to end of the string
    for (int i = 1; i < s.length(); i++) {
        // Push to stack if the last 2 chars doesn't match
        if (i == 0 || s[i] != s[i - 1]) {
            st.push(i);
        }
        // Chars are equal check whether we have K such chars adjacent toeach other
        // +1 is for index starts with zero
        else if (i - st.top() + 1 == k) {
            // All the K chars are adjacent to each other, remove the characters
            s.erase(st.top(), k);
            // Update i from where it should start
            i = st.top() - 1;
            // pop the stack as it is done
            st.pop();
        }
    }

    return s;
}
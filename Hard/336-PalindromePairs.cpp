
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 336: Palindrome Pairs
 *
 * Given a list of unique words, return all the pairs of the distinct indices (i, j)
 * in the given list, so that the concatenation of the two words words[i] + words[j]
 * is a palindrome.
 *
 * Example 1:
 * Input: words = ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
 *
 * Example 2:
 * Input: words = ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 *
 * Example 3:
 * Input: words = ["a",""]
 * Output: [[0,1],[1,0]]
 *
 * Constraints:
 * 1 <= words.length <= 5000
 * 0 <= words[i].length <= 300
 * words[i] consists of lower-case English letters.
*/

/*
 * Approach is similar to trie but using it a map
 *
 * We have 3 cases where
 * . If the string is "" and if there is a palindromic substring, then there will
 *   2 palindrome pairs
 *   Eg: s1 = ""  s2 = aba =>  ""aba or aba"" => 2 palindromic pairs
 *
 * . Case where there are 2 strings with equal length
 *   Eg: s1 = abcd s2 = dcba => abcddcba & dcbaabcd are palindrome pairs
 *
 * . Case with strings having non equal lengths
 *   Eg: s1 = lls   s2 = s
 *   In this case, we can s1 into 2 substrings at indices 1....s1.length()
 *   say left, right, check whether left is palindrome and reverse of right is equal
 *   to s2, then there will a pair
 *   Simillarly, if right is palindrome and reverse of left is equal to s2, then there
 *   is also a pair.
 *
*/

bool isPalindrome(string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    // 2d vector to store teh indices of palindrome pairs
    vector<vector<int>> res;

    // map to store the words and their indices, using map because the contents
    // can be accessed in O(1) time
    unordered_map<string, int> mp;

    // Loop all the words and update the map
    for (int i = 0; i < words.size(); i++) {
        // Store the index and word int the map
        mp[words[i]] = i;
    }

    // Empty string case
    if (mp.count("") == 1) {
        // We have an empty string in the input words

        // get the idx of the empty word
        int idx = mp[""];

        // Loop over all words in the input vector, check whether the stirng is
        // palindrome or not
        for (int i = 0; i < words.size(); i++) {
            // Check if the input word is not "" and check if it is a palindrome or not
            if (i != idx && isPalindrome(words[i])) {
                // word at index i is a palindrome, add the indices to result
                res.push_back({ i, idx });
                res.push_back({ idx, i });
            }
        }
    }

    // Equal length strings
    // Traverse all the words and find whether reverse of the string is available in map
    // or not
    for (int i = 0; i < words.size(); i++) {
        // Get the reverse of the current word
        string s(words[i].rbegin(), words[i].rend());

        // Check if is available in map or not
        if (mp.count(s) == 1 && mp[s] != i) {
            // reverse word is available in map, we got a pair add it to result
            res.push_back({ i, mp[s] });
        }
    }

    // Temp Variables
    string s = "";
    string left, right;
    string rev;

    // Non- Equal Strings
    for (int i = 0; i < words.size(); i++) {
        // Retrieve the current word
        s = words[i];

        // Generate the substrings at different intervals
        for (int j = 1; j < s.length(); j++) {
            // Generate the two substrings that are divide at index j
            left = s.substr(0, j);
            right = s.substr(j);

            // Need to check whether left is palindrome and reverse of right is
            // available in the input vector
            if (isPalindrome(left)) {
                // left word is palindrome, check reverse of right substring is
                // in input vector
                string rev(right.rbegin(), right.rend());
                // Check if this is available in input map or not
                if (mp.count(rev) == 1) {
                    // Reverse word is available at input vector, got a pair
                    res.push_back({ mp[rev], i });
                }
            }

            // Check if right substring is palindrome or not
            if (isPalindrome(right)) {
                // Right substring is palindrome, check reverse of left substring
                // is available in input vector or not
                string rev(left.rbegin(), left.rend());

                // Check if this is available in input map or not
                if (mp.count(rev) == 1) {
                    // Reverse word is availble, we got a pir
                    res.push_back({ i, mp[rev] });
                }
            }
        }
    }

    return res;
}

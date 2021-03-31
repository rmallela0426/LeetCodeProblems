
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 916: Word Subsets
 *
 * We are given two arrays A and B of words.  Each word is a string of lowercase
 * letters.
 * Now, say that word b is a subset of word a if every letter in b occurs in a,
 * including multiplicity.  For example, "wrr" is a subset of "warrior", but is
 * not a subset of "world".
 * Now say a word a from A is universal if for every b in B, b is a subset of a. 
 *
 * Return a list of all universal words in A.  You can return the words in any order.
 *
 * Example 1:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
 * Output: ["facebook","google","leetcode"]
 *
 * Example 2:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
 * Output: ["apple","google","leetcode"]
 *
 * Example 3:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
 * Output: ["facebook","google"]
 *
 * Example 4:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
 * Output: ["google","leetcode"]
 *
 * Example 5:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
 * Output: ["facebook","leetcode"]
 *
 * Note:
 * 1 <= A.length, B.length <= 10000
 * 1 <= A[i].length, B[i].length <= 10
 * A[i] and B[i] consist only of lowercase letters.
 * All words in A[i] are unique: there isn't i != j with A[i] == A[j].
*/
/*
 * Approach followed is to find the max frequencies of each characters in B and check
 * each word in A if the all the words matches the frequencies of B.
*/
vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    // Calculate the max frequencies of chars in B
    // As all the letters are lower case, there will be 26, the
    // array size is 26
    vector<int> maxFreqB(26, 0);

    // Calculate the max frequencies of chars in B
    for (string word : B) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
            maxFreqB[ch - 'a'] = max(maxFreqB[ch - 'a'], freq[ch - 'a']);

        }
    }

    std::vector<string> res;
    // Now check each word in A whether B is subset of A
    for (string word : A) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        // check if freq matches the freq of B
        bool issubset = true;
        for (int i = 0; i < 26; i++) {
            if (freq[i] < maxFreqB[i]) {
                issubset = false;
                break;
            }
        }
        if (issubset)
            res.push_back(word);
    }

    return res;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 139: Word Break
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can be segmented
 * into a space-separated sequence of one or more dictionary words.
 *
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 *
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
*/
/*
    * TopDown Approach or Recursive Solution
    *
    * As the solution is to find whether the input string is segmented into
    * words in the dictionary.
    * Loop through each word in the dictionary and check if a word in
    * dictionary is found in s
    *    . If found, remove the word from s and do a recursive call to find
    *      remaining string in dictionary
    *    . If it is not found, move onto next word in dictionary
    *
    * If all words  is not matched, then return false. If incase, any of the
    * recursive calls return true, then solution is also true
    *
    * Base case is that if string is empty, then return true, empty string is
    * always true
*/
bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) {
        return true;
    }

    // string is not empty, loop all words in dictionary
    for (string word : wordDict) {
        string left = s.substr(0, word.size());

        if (left == word && wordBreak(s.substr(word.size()), wordDict)) {
            return true;
        }
    }
    return false;
}

/*
 * TopDown Approach or Recursive Solution with Memoization
 *
 * There will be many duplicate subproblems if the input
 * string has many continous duplicate letters,
 *
 * For eg: s = "aaaaaaaa" wordDict = ["a", "aa", "aaa", "aaaa"]
 * In order for not to evaluate the duplicate sub problems,
 * the intermediate results are stored in the dp, so the time
 * complexity can be reduced from O(2^n) to O(n^2)
*/
std::unordered_map<string, bool> dp1;
bool wordBreak_memo(string s, vector<string>& wordDict) {
    if (s.empty()) {
        // String is empty, return true 
        return true;
    }

    // Check if this subproblem is evaluated
    if (dp1.count(s) == 1) {
        // The subproblem is already evaluated, returning previous
        // calculated solution
        return dp1[s];
    }

    // string is not empty, loop all words in dictionary
    for (string word : wordDict) {
        string left = s.substr(0, word.size());

        if (left == word && wordBreak(s.substr(word.size()), wordDict)) {
            return dp1[left] = true;
        }
    }
    return dp1[s] = false;
}

/*
 * Bottom Up Solution
 *
 * Similar to Memoization but will be an iterative not recursive.
 *
 * The DP array holds whether the substring from 0 is present in dictionary or not
 * The length of dp array is n + 1 where n = length of i/p string, +1 to accomidate
 * for empty string
*/
bool wordBreak_BU(string s, vector<string>& wordDict) {
    // DP array to hold whether the substring till that point are available in 
    // Dictionary or not.
    vector<bool> dp(s.size() + 1, false);

    // Empty string is always true
    dp[0] = true;

    // Try to fill the dp array, concpet is 2 index solution where the first
    // idx runs from 1... dp.size() and the other idx runs from first idx -1
    // till >= 0
    // first idx holds the length of substr
    // second idx is starting idx of substr in input S
    for (int i = 1; i < dp.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

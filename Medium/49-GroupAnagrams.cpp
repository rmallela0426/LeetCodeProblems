
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 49: Group Anagrams
 *
 * Given an array of strings strs, group the anagrams together. You can return the answer
 * in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or
 * phrase, typically using all the original letters exactly once.
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 *
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 * Constraints:
 * 1 <= strs.length <= 104
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lower-case English letters.
*/
/*
 * Approach is to sort each string in input vector and save
 * indices in a map. After traversing all the input strings
 * the map contains indices of group of anagrams.
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Map to store the group of indices that are anangram
    std::map<string, vector<int>> mp;

    string inp;
    // Traverse all the input string
    for (int i = 0; i < strs.size(); i++) {
        inp = strs[i];
        // Sort the input string
        sort(inp.begin(), inp.end());

        // Push the input index to the map with the modified key
        mp[inp].push_back(i);
    }

    // 2d vector to store the result, size of the vector will be
    // number of unique strings
    vector<vector<string>> res(mp.size());

    // variable to tell the index in input result
    int i = 0;

    // Traverse all the strings in input map
    for (auto& mpgrp : mp) {
        // Retrieve the indices of the input string that are anagrams
        vector<int> indices = mpgrp.second;

        // traverse all the indices
        for (int& idx : indices) {
            // push the anagrams to the result
            res[i].push_back(strs[idx]);
        }

        i++;
    }

    return res;
}

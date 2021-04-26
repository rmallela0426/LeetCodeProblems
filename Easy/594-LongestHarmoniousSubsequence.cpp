
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 594: Longest Harmonious Subsequence
 *
 * We define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * Given an integer array nums, return the length of its longest harmonious
 * subsequence among all its possible subsequences.
 * A subsequence of array is a sequence that can be derived from the array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 * Example 1:
 * Input: nums = [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 *
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: 2
 *
 * Example 3:
 * Input: nums = [1,1,1,1]
 * Output: 0
 *
 * Constraints:
 * 1 <= nums.length <= 2 * 104
 * -109 <= nums[i] <= 109
*/
/*
 * Approach is to store the frequencies of each num in
 * a map. Once frequencies are calculated then loop all
 * keys and find the longest harmonious sequences as
 *  maxvalue - minvalue = 1 => maxvalue = 1 + minvalue
 * For each key, try to find whether key+1 is available
 * in map, if so find the longest sequence
 *
 * Eg: [1, 7, 4, 6, 2, 6, 5, 5] o/p: 4=> [6,6,5,5]
 * frequencies: 1 - 1     7 - 1
 *              4 - 1     6 - 2
 *              2 - 1     5 - 2
 * Now loop all keys
 *   if key+1 is available in frequency map
 *       res = max(res, mp[key] + mp[key+1]);
 *
 * Base case: If there are no elements in array return 0
*/
int findLHS(vector<int>& nums) {
    if (nums.empty()) {
        // An empty input array
        return 0;
    }

    // Map to store the frequencies of each num
    unordered_map<int, int> mp;

    // Find the frequencies of each number
    for (int& num : nums) {
        mp[num]++;
    }

    // size of the longest subsequence
    int size = 0;

    // Loop for all frequencies and find the size of longest
    // subsequence
    for (auto& elem : mp) {
        // check if the key+1 is available in the input list
        if (mp.count(elem.first + 1)) {
            // Max value for the current key is available in
            // the input, calculate the length of the subsequenc
            // that are having the current key and current key
            // max value
            size = max(size, elem.second + mp[elem.first + 1]);
        }
    }

    // return the size of the longest subsequence
    return size;
}

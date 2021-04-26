
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1394: Find Lucky Integer In An Array
 *
 * Given an array of integers arr, a lucky integer is an integer which has a
 * frequency in the array equal to its value.
 * Return a lucky integer in the array. If there are multiple lucky integers
 * return the largest of them. If there is no lucky integer return -1.
 *
 * Example 1:
 * Input: arr = [2,2,3,4]
 * Output: 2
 * Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
 *
 * Example 2:
 * Input: arr = [1,2,2,3,3,3]
 * Output: 3
 * Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
 *
 * Example 3:
 * Input: arr = [2,2,2,3,3]
 * Output: -1
 * Explanation: There are no lucky numbers in the array.
 *
 * Example 4:
 * Input: arr = [5]
 * Output: -1
 *
 * Example 5:
 * Input: arr = [7,7,7,7,7,7,7]
 * Output: 7
 *
 * Constraints:
 * 1 <= arr.length <= 500
 * 1 <= arr[i] <= 500
*/
/*
 * Approach is to calculate the frequencies of all inputs
 * Loop and find the lucy integer
 * TimeComplexity: O(2N) Space: O(N)
*/
int findLucky(vector<int>& arr) {
    // Map to store the frequencies of all integers
    unordered_map<int, int> freq;

    // count the frequencies
    for (int& num : arr) {
        freq[num]++;
    }

    // Variable to store the lucky integer
    int luckyInt = -1;

    // Loop through all frequencies and check if the key and
    // value are equal. If so, then store it in luckyInt if
    // it is largest
    for (auto& mp : freq) {
        if (mp.first == mp.second) {
            // Both the frequency and number is equal i.e..,
            // it is a lucky number
            luckyInt = max(luckyInt, mp.first);
        }
    }

    return luckyInt;
}

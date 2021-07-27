
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1004: Max Consecutive Ones III
 *
 * Given a binary array nums and an integer k, return the maximum number of
 * consecutive 1's in the array if you can flip at most k 0's.
 *
 * Example 1:
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *
 * Example 2:
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *
 * Constraints:
 * 1 <= nums.length <= 105
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
*/

/* Approach followed is a sliding window technique where there
 * are 2 pointers wStart and wEnd and wEnd will be traversing
 * the entire numbers.
 * . If we encounter 0 at wEnd, then we start decrementing K
 * . If k < 0, then we start incrementing wStart ie.., we have
 *   more number of 0's than k.
 * . If there is 0 at wStart, then we start incrementing K bcz
 *   we need to have only one's.
 * Once we are done with traversing, the number of consecutive
 * 1's are calculated using window length
 */
int longestOnes(vector<int>& nums, int k) {
    // Basecase: check if the input nums is empty
    if (nums.empty()) {
        // Input vector is empty, return
        return 0;
    }

    // Initialize the window variables
    int wStart = 0;
    int wEnd = 0;

    // Traverse the window for whole input array
    while (wEnd < nums.size()) {
        // If the current number is 0 at WEnd, then reduce the k
        // as only k 0's can be flipped
        if (nums[wEnd] == 0) {
            // Reduce k
            k--;
        }

        // Check if more than k 0's are flipped, then slide the window
        if (k < 0) {
            // Check if the num at wStart is zero, then increase the
            // k as we are removing one zero from our window
            k += (nums[wStart] == 0 ? 1 : 0);

            // Increment the wStart
            wStart++;
        }

        // Increment the window
        wEnd++;
    }


    // Now window size is the number of consecutive 1's after flipping
    // k zeros
    return wEnd - wStart;
}

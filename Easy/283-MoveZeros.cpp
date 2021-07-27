

/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 283:Move Zeros
 *
 * Given an integer array nums, move all 0's to the end of it
 * while maintaining the relative order of non-zero elements.
 *
 * Note that you must do this in-place without making a copy
 * of the array.
 *
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
*/
/*
 * Approach followed is a two pointer algorithm where read
 * and write pointers. Traverse all the numbers in input
 * array and if the current num is not zero, then write the
 * current value to index pointed by write ptr else nothing
 * to be done.
 *
 */
void moveZeroes(vector<int>& nums) {
    // Base case: If the input is empty
    if (nums.empty()) {
        // input is empty, nothing to process
        return;
    }

    // Initialize read and write indices that initalizes to 0
    int rIdx = 0;
    int wIdx = 0;

    // Variable to store number of zeros
    int numzeros = 0;

    // Traverse the loop for all input numbers
    while (rIdx < nums.size()) {
        // Check whether the current number is zero or not
        if (nums[rIdx] != 0) {
            // Current number is not zero, push it to the write
            // index
            nums[wIdx++] = nums[rIdx];
        }
        else{
            // The current number is a zero, increment the count
            numzeros++;
        }

        // Increment the read index
        rIdx++;
    }

    // Fill the zeros at the end of array
    while (numzeros--) {
        nums[wIdx++] = 0;
    }

    return;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 485: Max Consecutive Ones
 *
 * Given a binary array nums, return the maximum number of consecutive 1's in the array.
 *
 * Example 1:
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s. The maximum
 * number of consecutive 1s is 3.
 *
 * Example 2:
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 *
 * Constraints:
 * 1 <= nums.length <= 105
 * nums[i] is either 0 or 1.
*/
/* Approach followed is greedy approach where the number of
 * ones will be counted and the count will be reset when the
 * current number is zero. For every iteration, calculate
 * the max no of consecutive 1's
 */
int findMaxConsecutiveOnes(vector<int>& nums) {
    // Basecase: Input vector is empty
    if (nums.empty()) {
        // Input vector is empty, so there will be no 1's
        return 0;
    }

    // Variable to store the count of consecutive 1's
    int count = 0;
    // Variable to store the max no of consecutive 1's
    int maxCount = 0;

    // Loop all number of 1
    for (int& num : nums) {
        // increment the count if current num is 1
        if (num == 1) {
            count++;
        }
        else {
            // Current number is 0, reset the count update the
            // maxCOunt
            maxCount = max(maxCount, count);
            count = 0;
        }
    }

    return max(maxCount, count);
}

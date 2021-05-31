
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1827: Min Operations to Make Array Increasing
 *
 * You are given an integer array nums (0-indexed). In one operation, you can choose an element
 * of the array and increment it by 1.
 * For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
 * Return the minimum number of operations needed to make nums strictly increasing.
 *
 * An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1.
 * An array of length 1 is trivially strictly increasing.
 *
 * Example 1:
 * Input: nums = [1,1,1]
 * Output: 3
 * Explanation: You can do the following operations:
 * 1) Increment nums[2], so nums becomes [1,1,2].
 * 2) Increment nums[1], so nums becomes [1,2,2].
 * 3) Increment nums[2], so nums becomes [1,2,3].
 *
 * Example 2:
 * Input: nums = [1,5,2,4,1]
 * Output: 14
 *
 * Example 3:
 * Input: nums = [8]
 * Output: 0
 *
 * Constraints:
 * 1 <= nums.length <= 5000
 * 1 <= nums[i] <= 104
*/
/*
 * As the solution is to find min operations for making the array increasing
 * nums[i + 1] element is greater than or equal to nums[i] + 1 ie.., the min
 * no of moves required to make the number increasing is
 *                  abs(nums[i] - nums[i-1]) + 1
 * Iterate over the loop and check if the current number is less than previous
 * number. If so, calculate the no of moves required to make the current number
 * greater than the previous and update the number in input array
 *
*/
int minOperations(vector<int>& nums) {
    // min operations required to make array increasing
    int minOps = 0;

    // Interate over all numbers
    for (int i = 1; i < nums.size(); i++) {
        // Check if the current number is greater than previous or not
        if (nums[i] <= nums[i - 1]) {
            // Current number is not increasing, calculate the no of operations
            // required to make current number greater than previous
            minOps += abs(nums[i] - nums[i - 1]) + 1;
            // Current number should at least greater than one
            nums[i] = nums[i - 1] + 1;
        }
    }

    return minOps;
}

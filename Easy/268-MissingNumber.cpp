
/*
 *  Author: Raghavendra Mallela
*/

/*
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 * Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity?
 *
 * Example 1:
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the
 * range [0,3]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 * Example 2:
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the range
 * [0,2]. 2 is the missing number in the range since it does not appear in nums.
 *
 * Example 3:
 * Input: nums = [0]
 * Output: 1
 * Explanation: n = 1 since there is 1 number, so all numbers are in the range
 * [0,1]. 1 is the missing number in the range since it does not appear in nums.
 *
 * Constraints:
 * n == nums.length
 * 1 <= n <= 104
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 */

int missingNumber(vector<int>& nums) {
    // sort the array so that numbers in ascending order
    std::sort(nums.begin(), nums.end());

    // If the last number in input is not the size
    // of the array then return the size 
    // Ensure that n is at the last index
    if (nums.back() != nums.size())
        return nums.size();

    // Loop for all numbers in input vector
    // If the difference from current no and previous is
    // greater than 1, ie.., num is missing, return current -1
    for (int idx = 1; idx < nums.size(); idx++) {
        if (nums[idx] - nums[idx - 1] > 1)
            return nums[idx] - 1;
    }
    return 0;
}

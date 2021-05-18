
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1464: Max Product of Two Elements in an array
 *
 * Given the array of integers nums, you will choose two different indices i and j of
 * that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 *
 * Example 1:
 * Input: nums = [3,4,5,2]
 * Output: 12
 * Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the
 * maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
 *
 * Example 2:
 * Input: nums = [1,5,4,5]
 * Output: 16
 * Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum
 * value of (5-1)*(5-1) = 16.
 *
 * Example 3:
 * Input: nums = [3,7]
 * Output: 12
 *
 * Constraints:
 * 2 <= nums.length <= 500
 * 1 <= nums[i] <= 10^3
*/
/*
 * Approach is to use bruteforce method but it takes O(n^2)
 * If we sort the values from the input vector, then max values
 * are at end of the array, evaluate the max value with last
 * 2 values
*/
int maxProduct(vector<int>& nums) {
    // Sort the input vector
    sort(nums.begin(), nums.end());

    int n = nums.size();
    // max value is attained by considering last 2 values which
    // are largest values
    return (nums[n - 2] - 1) * (nums[n - 1] - 1);
}

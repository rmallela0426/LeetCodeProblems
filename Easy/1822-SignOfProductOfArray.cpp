
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1822: Sign Of the Product of an Array
 *
 * There is a function signFunc(x) that returns:
 * 1 if x is positive.
 * -1 if x is negative.
 * 0 if x is equal to 0.
 * You are given an integer array nums. Let product be the product of all values
 * in the array nums.
 *
 * Return signFunc(product).
 *
 * Example 1:
 * Input: nums = [-1,-2,-3,-4,3,2,1]
 * Output: 1
 * Explanation: The product of all values in the array is 144, and signFunc(144) = 1
 *
 * Example 2:
 * Input: nums = [1,5,0,2,-3]
 * Output: 0
 * Explanation: The product of all values in the array is 0, and signFunc(0) = 0
 *
 * Example 3:
 * Input: nums = [-1,1,-1,1,-1]
 * Output: -1
 * Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
 *
 * Constraints:
 * 1 <= nums.length <= 1000
 * -100 <= nums[i] <= 100
*/
// Approach is to find the num of -ve numbers.
// If it is even then the result of product of
// the array will be positive. If there are
// odd number of -ve numbers, then produce of
// all elements in array is negative.
int arraySign(vector<int>& nums) {
    // variable to tell the result of product 
    // will be positive.
    bool isPositive = true;

    // Loop all the numbers and check if the
    // number is zero or negative.
    for (int& num : nums) {
        if (num == 0) {
            // current number is zero and the
            // product will be zero.
            return 0;
        }

        if (num < 0) {
            // curr number is negative, update the
            // result appropriately
            isPositive = !isPositive;
        }
    }

    return isPositive ? 1 : -1;
}

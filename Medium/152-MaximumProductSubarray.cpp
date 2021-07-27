
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 152: Maximum Product Subarray
 *
 * Given an integer array nums, find a contiguous non-empty subarray within the array
 * that has the largest product, and return the product.
 * It is guaranteed that the answer will fit in a 32-bit integer.
 * A subarray is a contiguous subsequence of the array.
 *
 * Example 1:
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 * Example 2:
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 * Constraints:
 * 1 <= nums.length <= 2 * 104
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/
/*
 * Approach followed is a greedy solution where the idea is to traverse
 * the input array from left to right by maintaining 3 variables minvalue
 * , maxvalue and maxProduct. Initially the values of all the variables
 * is the value at 0th index of input array. while traversing, if the
 * current element is negative, swap the minvalue and maxvalue evaluate
 * the product with curr value and update the maxProduct.
*/
int maxProduct(vector<int>& nums) {
    // BaseCase: input array is empty
    if (nums.empty()) {
        // Input array is empty, there won't be any product
        return 0;
    }

    // Initialize the minValue, maxValue
    int minValue = nums[0];
    int maxValue = nums[0];

    // variable to store the max subarray product
    int maxProduct = nums[0];

    // Travers the input array
    for (int i = 1; i < nums.size(); i++) {
        // check if the number at index i is a -ve value or not
        if (nums[i] < 0) {
            // Current number is a -ve value, swap the min and max values
            int temp = maxValue;
            maxValue = minValue;
            minValue = temp;
        }

        // Evaluate the min and max values by getting the products of the current
        // element
        maxValue = max(nums[i], nums[i] * maxValue);
        minValue = min(nums[i], nums[i] * minValue);

        // Update the result
        maxProduct = max(maxProduct, maxValue);
    }

    return maxProduct;
}

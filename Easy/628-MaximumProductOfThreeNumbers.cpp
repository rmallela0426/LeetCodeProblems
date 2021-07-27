
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 628: Maximum Product Of Three Numbers
 *
 * Given an integer array nums, find three numbers whose product is maximum and return
 * the maximum product.
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: 6
 *
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: 24
 *
 * Example 3:
 * Input: nums = [-1,-2,-3]
 * Output: -6
 *
 * Constraints:
 * 3 <= nums.length <= 104
 * -1000 <= nums[i] <= 1000
*/
/*
 * Approach followed is sorting the array in ascending order and evaluating
 * the product of the last 3 numbers which gives us the max product but the
 * input array can have negative values, there could be a maximum product
 * when we multiply 2 -ve numbers with that of max +ve number.
*/
int maximumProduct(vector<int>& nums) {
    // Retrieving the length of the input array
    int n = nums.size();

    // Sort the input array in ascending order
    sort(nums.begin(), nums.end());

    // As the input has -ve numbers result will max of 2 -ve numbers with max
    // +ve number or the last 3 max values of input array
    return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
}

/*
 * Approach followed is to evaluate the product of max 3 nos which gives
 * us the max product but the  input array can have negative values, there
 * could be a maximum product when we multiply 2 -ve numbers with that of'
 * max +ve number.
 * Basically we need to find 2 min nos and 3 max nos and evaluate result.
*/
int maximumProduct(vector<int>& nums) {
    // Initialize 2 variables that can store the first 2 min variables
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    // Initialize 3 variables that can store the last 3 max values
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    // Traverse the input array and evaluate the 5 values
    for (int& num : nums) {
        // Check if the num is with in the range of min1 and min2
        if (num <= min1) {
            // current number is less than first min value
            // push the min value to min2
            min2 = min1;
            min1 = num;
        }
        else if (num <= min2) {
            // Current num is less than min2 but greater than min1
            // update min2
            min2 = num;
        }

        // Check if the num is with in range of max1, max2, max3
        if (num >= max3) {
            // Current num is greater than of all the previous values
            // update max1, max2, max3
            max1 = max2;
            max2 = max3;
            max3 = num;
        }
        else if (num >= max2) {
            // Current num is greaer than max2 but less than max1
            // update max2 and max1
            max1 = max2;
            max2 = num;
        }
        else if (num >= max1) {
            // CUrrent num is greter than or equal to max1 but less than max2
            // and max3
            max1 = num;
        }
    }

    // As the input has -ve numbers result will max of 2 -ve numbers with max
    // +ve number or the last 3 max values of input array
    return max(min1 * min2 * max3, max1 * max2 * max3);

}



/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 53: Maximum Subarray
 *
 * Given an integer array nums, find the contiguous subarray (containing
 * at least one number) which has the largest sum and return its sum.
 *
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 * Example 2:
 * Input: nums = [1]
 * Output: 1
 *
 * Example 3:
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 * Constraints:
 * 1 <= nums.length <= 3 * 104
 * -105 <= nums[i] <= 105
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
*/

// Brute Force Solution
int maxSubArray(vector<int>& nums) {
    int maxsum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        int sum = nums[i];
        maxsum = max(maxsum, sum);

        for (int j = i + 1; j < nums.size(); j++) {
            sum += nums[j];
            maxsum = max(maxsum, sum);
        }
    }

    return maxsum;
}

// DP Solution
int maxSubArray(vector<int>& nums) {
    /*
     * Approach followed is a DP BottomUp solution, where the
     * solution for subproblems are saved in a dp array. The
     * dp array max sum at that index ie..,
     *     dp[i] = max(nums[i], nums[i]+dp[i-1]);
     *
     * As there a need of only the previous max subarray sum,
     * just one integer is enough.
    */

    // Variable that stores the maximum subarra
    int maxsum = nums[0];
    // variable that stores the max sum at that
    // particular index
    int sum = nums[0];

    // Loop for all the values of the input array 
    for (int i = 1; i < nums.size(); i++) {
        // Check whether the current value or the sum of the
        // contiguos subarray(including this value) is maximum
        sum = max(nums[i], nums[i] + sum);
        // Update the global max
        maxsum = max(maxsum, sum);
    }

    // return the Global Max
    return maxsum;
}

// Kaden's algorithm
int maxSubArray(vector<int>& nums) {
    /*
       Kaden's algorithm:
       Tells that at particular jth elem, we need take
       either jth element or sum of j elements
    */
     int currsum = 0; // Holds the sum of j elements at jth element
     int maxsum = INT_MIN; // Holds the max subarra

     for (int num : nums) {
         currsum += num;
         currsum = std::max(num, currsum);
         maxsum = std::max(maxsum, currsum);
     }
     return maxsum;
}

/* Approach followed is sliding window technique where the wend
 * traverse from start to input vector and calculate the running
 * sum and update the result if it is maximum. If the running sum
 * is less than 0, then slide the window by incrementing window
 * start.
*/
int maxSubArray(vector<int>& nums) {
    // Check if input vector is empty
    if (nums.empty()) {
        // Input vector is empty, the sum will be zero
        return 0;
    }

    // Initialize the window values
    int wStart = 0;
    int wEnd = 0;

    // Running sum
    int sum = 0;
    // Result for storing Maximum subarray sum
    int maxSum = INT_MIN;

    // Traverse the input vector
    while (wEnd < nums.size()) {
        // Calculate the current sum
        sum += nums[wEnd];

        // Update the result
        maxSum = max(maxSum, sum);

        // Check if the current sum is <= 0
        if (sum <= 0) {
            // Current sum is <= 0
            // slide the window and reset the sum
            wStart++;
            sum = 0;
        }
        wEnd++;
    }

    return maxSum;
}

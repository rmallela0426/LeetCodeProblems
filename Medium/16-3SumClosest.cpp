
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 16: 3Sum Closest
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example 1:
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * Constraints:
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
*/
/*
 * Approach followed is greedy solution where the input array
 * is sorted and two pointer approach to traverse the input
 * array for calculating the sum. As we need to calculater the
 * closest sumInitialize diff to INT_MAX and once the sum is
 * calculated for the 3 nos, will save if this is a minimum
 * difference of the target. If the target is equal to sum then
 * return 0. Once the loop done, sum of the 3 integers whose
 * closest sum of 3 nos  will be target - diff
 *
 * BaseCase:
 * If there are less than 3 nos, then no point to loop.
 *
*/

int threeSumClosest(vector<int>& nums, int target) {
    // check if we have sufficient elements to find the triplets
    if (nums.size() < 3) {
        // no sufficient elemets for finding triplets
        return 0;
    }

    // Sort the input array in increasing order
    sort(nums.begin(), nums.end());

    // Retrieve the size of input array
    int n = nums.size();

    // Initialize the difference which will be the closest sum
    int diff = INT_MAX;

    // temp variables
    int sum = 0;

    // traverse the loop and find all triplets
    for (int i = 0; i < n; i++) {
        // Need to find the next two numbers
        // defining lo & hi indices
        int lo = i + 1;
        int hi = n - 1;

        // Traverse to find the remaining 2 nums so that sum is closest
        // to target
        // Perform a binary search
        int sum = 0;

        while (lo < hi) {
            // Evaluate the triplets sum
            sum = nums[i] + nums[lo] + nums[hi];

            // Check if the triplet sum is equal to target
            if (sum == target) {
                // Found the triplets which matches the target which is
                // closest.
                return sum;
            }
            // Check if the sum is closest to target
            else if (abs(target - sum) < abs(diff)) {
                // Triplets sum is closest to target
                diff = target - sum;
            }

            // check if the sum is greater than target, if so reduce hi
            // if sum is less than target, then increase lo
            sum < target ? lo++ : hi--;
        }
    }

    // As we need the sum of 3 nos which can be retrieved as target - diff
    // => target - target + sum = sum
    return target - diff;
}

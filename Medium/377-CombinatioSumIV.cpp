
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 377: Combination Sum IV
 *
 * Given an array of distinct integers nums and a target integer target, return the number
 * of possible combinations that add up to target.
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 * Example 1:
 * Input: nums = [1,2,3], target = 4
 * Output: 7
 * Explanation:
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * Note that different sequences are counted as different combinations.
 *
 * Example 2:
 * Input: nums = [9], target = 3
 * Output: 0
 *
 * Constraints:
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * All the elements of nums are unique.
 * 1 <= target <= 1000
 *
 * Follow up: What if negative numbers are allowed in the given array? How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
*/
/*
 * Approach followed is dynamic programming where recursive
 * call goes till the remaining target is < or or = 0
 * Eg: [1,2,3] target = 4
 *                          [1,2,3], 4
 *                                |
 *            ---------------------------------------------------
 *          1|                    2|                           3|
 *        [1], 3                 [2], 2                      [3], 1
 *           |
 *      ------------------------
 *    1|            2|        3 |
 *  [1,1], 2      [1,2], 1   [1,3], 0
 *     |
 *   -------------------------
 *  1|             2|        3|
 * [1,1,1], 1    [1,1,2],0
 *
 * Base Cases:
 * . When the remaining target is < 0, then return nothing or return zero
 * . When the target is 0 ie.., we got all the integers, increment the count
 *
 * Top Down or Recursive : TLE
 * Memoization : time: O(N*target), space : O(target)
 * BottomUp : time: O(N*target), space : O(target)
*/
int combinationSum4(vector<int>& nums, int target) {
    // Check if target is <= 0
    if (target <= 0) {
        // target is < 0 ie.., exceeded the target, return 0
        // target is 0 then there is a combination, return 1
        return target == 0 ? 1 : 0;
    }

    // variable to store the num of combinations to get the target
    int count = 0;
    for (int& num : nums) {
        count += combinationSum4(nums, target - num);
    }
    return count;
}

/*
 * As there are many duplicate subproblems and the solution of the problem can
 * be attained if solution of subproblem is known, Dynamic programming can be
 * applied where intermediate subproblem solutions are stored in a dp array.
*/

int combinationSum4_memo(vector<int>& nums, int target, vector<int>& dp) {
    // Check if target is < 0
    if (target < 0) {
        // target is < 0 ie.., exceeded the target, return 0
        return 0;
    }

    // Check if this subproblem is already solved
    if (dp[target] != -1) {
        // subproblem is already solved, return the num of combinations
        // that adds up to target
        return dp[target];
    }

    // variable to store the num of combinations to get the target
    int count = 0;
    for (int& num : nums) {
        count += combinationSum4_memo(nums, target - num, dp);
    }

    return dp[target] = count;
}

int combinationSum4(vector<int>& nums, int target) {
    // Dp array that store the num of combinations for that target
    // As count is needed till and equal to target, +1 is added
    vector<int> dp(target + 1, -1);

    // If the target is zero, then there is a combination
    dp[0] = 1;
    return combinationSum4_memo(nums, target, dp);
}

/*
 * BottomUP solution, conditions are similar to recursive but the results of
 * subproblems are stored in dp table. Bottom up is to find bottom solutions
 * first to yield the top solution i.e.., solution of the problem
 *
 * The DP table at i holds the num of combinations that adds up to target
*/
int combinationSum4_BU(vector<int>& nums, int target) {
    // Dp array that store the num of combinations for that target
    // As count is needed till and equal to target, +1 is added
    vector<unsigned int> dp(target + 1, 0);

    // If the target is zero, then there is a combination
    dp[0] = 1;

    // Loop for every target
    for (int t = 1; t <= target; t++) {
        // For each target, there can be a combination with all the input nums
        for (int& num : nums) {
            // Discard the num if it is > current target
            if (t >= num) {
                // Add the combinations that are needed for remaining target
                // i.e.., current target - current num
                dp[t] += dp[t - num];
            }
        }
    }

    // return the numcombination for the input target
    return dp[target];
}

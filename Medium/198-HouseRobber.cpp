
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 198: House Robber
 *
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security systems connected and it will automatically contact the police
 * if two adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each
 * house, return the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 2:
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 * Constraints:
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
*/
/*
 * TopDown Approach or Recursive Solution
 *
 * There will be 2 subproblems for each problem i.e.., one to rob the current house and rob the
 * houses that are not adjacent, and other subproblem was to skip the adjacent house
 *         std::max(arr[idx] + rob(arr, i-2), rob(arr, i-1)) where i = arrLength-1 to 0
 *
 * Base cases:
 * If the idx < 0 then there are no houses to rob, return  0
 *
 */
int rob(vector<int>& nums, int index) {
    // Handling base case
    if (index < 0 || nums.empty()) {
        // There are no houses to rob, return 0
        return 0;
    }

    return std::max(nums[index] + rob(nums, index - 2), rob(nums, index - 1));
}
int rob(vector<int>& nums) {
    return rob(nums, nums.size() - 1);
}

/*
 * RobHouse BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main problem
 * can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find bottom solutions first to yield the top solution i.e.., solution of
 * the problem
 *
 * As there are 2 subproblems for each problem i.e.., one to rob the current house and rob the
 * houses that are not adjacent, and other subproblem was to skip the adjacent house
 *            dp[i] =  std::max(input[i] + dp[i-2], dp[i-1])
 *
 */
int rob_BU(vector<int>& nums) {
    if (nums.empty()) {
        // There are no houses to rob, return 0
        return 0;
    }

    // only 2 subproblems are needed to evaluate the current solution, so initializing 2 variables to zero
    int prev2 = 0;
    int prev1 = 0;
    int maxamt = 0;

    for (int idx = 0; idx < nums.size(); idx++) {
        maxamt = std::max(nums[idx] + prev2, prev1);

        prev2 = prev1;
        prev1 = maxamt;
    }
    return maxamt;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1770: Maximum Score from performing Multiplication Operation
 *
 * You are given two integer arrays nums and multipliers of size n and m respectively,
 * where n >= m. The arrays are 1-indexed.
 *
 * You begin with a score of 0. You want to perform exactly m operations. On the ith
 * operation (1-indexed), you will:
 *       Choose one integer x from either the start or the end of the array nums.
 *       Add multipliers[i] * x to your score.
 *       Remove x from the array nums.
 * Return the maximum score after performing m operations.
 *
 * Example 1:
 * Input: nums = [1,2,3], multipliers = [3,2,1]
 * Output: 14
 * Explanation: An optimal solution is as follows:
 * - Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
 * - Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
 * - Choose from the end, [1], adding 1 * 1 = 1 to the score.
 * The total score is 9 + 4 + 1 = 14.
 *
 * Example 2:
 * Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
 * Output: 102
 * Explanation: An optimal solution is as follows:
 * - Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
 * - Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
 * - Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
 * - Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
 * - Choose from the end, [-2,7], adding 7 * 6 = 42 to the score.
 * The total score is 50 + 15 - 9 + 4 + 42 = 102.
 *
 * Constraints:
 * n == nums.length
 * m == multipliers.length
 * 1 <= m <= 103
 * m <= n <= 105
 * -1000 <= nums[i], multipliers[i] <= 1000
*/
/*
 * TopDown Approach or Recursive Solution
 *
 * The solution is to find the maximum score after performing m multiplications and only
 * two ways to get the score ie.., select either first or last num
 * If incase the length of nums is 2 and there is only one multiplier, then result will be
 * For Eg: [1, 2]  [3]
 *      res = std::max(1*3, 2*1}
 *
 *  In general score = std::max(A[i]*B[j] + maxscore(A[i+1], B[j+1]),
 *                              A[last] * B[j] + maxscore(A[last-1], B[j+1]))
 * where i = 0... A.size() -1
 *       last = A.size()-1 ....... 0
 *       j = 0.... B.size() -1
 * Base cases:
 * If the multiplier reaches end, then return 0 as there are no more elements
 * If the i reaches last, then return the current result
 */
int maxscore(vector<int>& nums, vector<int>& multipliers, int left, int right, int midx) {
    if (midx >= multipliers.size()) {
        // Reaches the end, return 0
        return 0;
    }

    // As we move either first to last or last to first, if its reaches the end
    // return the product i.e.., if we have only one element in nums
    if (left == right) {
        return nums[left] * multipliers[midx];
    }

    return std::max(nums[left] * multipliers[midx] + maxscore(nums, multipliers, left + 1, right, midx + 1),
        nums[right] * multipliers[midx] + maxscore(nums, multipliers, left, right - 1, midx + 1));
}

int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    return maxscore(nums, multipliers, 0/*startidx of nums*/, nums.size() - 1 /*end idx of nums*/, 0);
}
/*
 * Top Down with Memonization
 *
 * As there are many duplicate subproblems problems, results can intermediately stored
 * in dp array.
 * Conditions are similar to Recursive Solution
*/
int dp[1001][1001];
int maxscore_memo(vector<int>& nums, vector<int>& multipliers, int left, int right, int midx) {
    if (midx >= multipliers.size()) {
        // Reaches the end, return 0
        return 0;
    }
    if (dp[midx][left] != 0) {
        // Subproblem is already evaluated, no need to reevaluated
        return dp[midx][left];
    }

    // As we move either first to last or last to first, if its reaches the end
    // return the product i.e.., if we have only one element in nums
    if (left == right) {
        return dp[midx][left] = nums[left] * multipliers[midx];
    }

    return dp[midx][left] = std::max(
        nums[left] * multipliers[midx] + maxscore(nums, multipliers, left + 1, right, midx + 1),
        nums[right] * multipliers[midx] + maxscore(nums, multipliers, left, right - 1, midx + 1));
}

int maximumScore_memo(vector<int>& nums, vector<int>& multipliers) {
    memset(dp, 0, sizeof(dp));
    return maxscore_memo(nums, multipliers, 0/*startidx of nums*/, nums.size() - 1 /*end idx of nums*/, 0);
}
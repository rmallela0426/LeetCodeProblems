
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 55: Jump Game
 *
 * Given an array of non-negative integers nums, you are initially positioned at
 * the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 *
 * Example 1:
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Example 2:
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum jump
 * length is 0, which makes it impossible to reach the last index.
 *
 * Constraints:
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
*/
/*
 * Solution si to find whether we reach end or not. The approach is
 * greedy solution where traversal is from end to start. Initially
 * the lastIdx will point to the last index of the input array. Will
 * traverse the loop from last to first and check whether we can reach
 * the next position from the current position or not
 *          idx + nums[idx] >= lastIdx
 * If the next index can be reached, then we can modify the last index
 * Once we are done with the traversal, then last index should be equal
 * to start index.
*/
bool canJump(vector<int>& nums) {
    // Index to store the last Jump
    int lastJumpIdx = nums.size() - 1;

    // Traverse the loop from last to first
    for (int idx = nums.size() - 1; idx >= 0; idx--) {
        // Check whether we can reach the last index from the current
        // Jump
        if (idx + nums[idx] >= lastJumpIdx) {
            // Next index can be reached from the current index as the
            // current index has max jumps that helps to reach next index
            // Update the lastJumpIdx
            lastJumpIdx = idx;
        }
    }

    // Check whether we reach the start index
    return lastJumpIdx == 0;
}

/*
 * TopDown or Recursive Solution:
 *
 * Each index represents the maximum jump length at tha position
 * the max index that can be jumped is from startidx to startidx
 * + nums[startidx].
 *
 * Eg: [2, 3, 1, 1, 4]
 *                     0  -- index
 *         nums[0] = 2 |
 *              ---------------
 *             |               |
 *             1               2
 *  nums[1]= 3 |     nums[2]=1 |
 *      ---------------        3
 *     |       |       |
 *     2       3       4
 *
 * BaseCase:
 * . When idx reaches end then we have a path
 * . When the max jumps is 0 at the current index, then there is
 *   no path
*/
bool canJump(vector<int>& nums, int sIdx) {
    // Basecase: When the sIdx reaches the end
    if (sIdx == nums.size() - 1) {
        // Reached last index of the array
        return true;
    }

    // Check if the max jumps at the current index is zero
    if (nums[sIdx] == 0) {
        // There is no jumps from current index
        return false;
    }

    // Retrieve the max Jumps that we can go from current index
    int maxJumpIdx = sIdx + nums[sIdx];

    // Traverse the max jumps from this current index
    for (int idx = sIdx + 1; idx <= maxJumpIdx; idx++) {
        // check whether we can jump to end from next index
        if (canJump(nums, idx)) {
            return true;
        }
    }

    return false;
}

/*
 * TopDown or Recursive Solution:
 *
 * Each index represents the maximum jump length at tha position
 * the max index that can be jumped is from startidx to startidx
 * + nums[startidx].
 *
 * Eg: [2, 3, 1, 1, 4]
 *                     0  -- index
 *         nums[0] = 2 |
 *              ---------------
 *             |               |
 *             1               2
 *  nums[1]= 3 |     nums[2]=1 |
 *      ---------------        3
 *     |       |       |
 *     2       3       4
 *
 * Since there are many overlapping subproblems in Recursive solution,
 * and the Solution for the main problem can ba attained if we have
 * solutions of suproblems, Dynamic Programming can be applied. The
 * intermediate solutions for subproblems are saved in a dp array.
 *
 * BaseCase:
 * . When idx reaches end then we have a path
 * . When the max jumps is 0 at the current index, then there is
 *   no path
*/
bool canJump(vector<int>& nums, int sIdx, vector<int>& dp) {
    // Basecase: When the sIdx reaches the end
    if (sIdx == nums.size() - 1) {
        // Reached last index of the array
        return true;
    }

    // Check if the max jumps at the current index is zero
    if (nums[sIdx] == 0) {
        // There is no jumps from current index
        return false;
    }

    // Check whether this subproblem is already evaluated
    if (dp[sIdx] != INT_MAX) {
        // This subproblem is already evaluated
        return dp[sIdx] == 1;
    }

    // Retrieve the max Jumps that we can go from current index
    int maxJumpIdx = sIdx + nums[sIdx];

    // Traverse the max jumps from this current index
    for (int idx = sIdx + 1; idx <= maxJumpIdx; idx++) {
        // check whether we can jump to end from next index
        if (canJump(nums, idx, dp)) {
            dp[sIdx] = 1;
            return true;
        }
    }

    dp[sIdx] = 0;
    return false;
}

bool canJump(vector<int>& nums) {
    // dp vector to store the reuslts of subproblems. Initial value will
    // be INT_MAX which helps to know whether it is visited or not.
    // 1 - valid path, 0 - not valid path
    vector<int> dp(nums.size(), INT_MAX);

    return canJump(nums, 0, dp);
}

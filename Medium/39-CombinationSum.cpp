
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 39: Combination Sum
 *
 * Given an array of distinct integers candidates and a target integer
 * target, return a list of all unique combinations of candidates where
 * the chosen numbers sum to target. You may return the combinations
 * in any order.
 * The same number may be chosen from candidates an unlimited number of
 * times. Two combinations are unique if the frequency of at least one
 * of the chosen numbers is different.
 *
 * It is guaranteed that the number of unique combinations that sum up
 * to target is less than 150 combinations for the given input.
 *
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used
 * multiple times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 * Example 2:
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * Example 3:
 * Input: candidates = [2], target = 1
 * Output: []
 *
 * Example 4:
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 *
 * Constraints:
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
*/
/*
 * Approach followed is dfs backtracking method where recursive
 * call goes till the remaining target is < or or = 0
 * Eg: [2,3,6,7] target = 7
 *                          [2,3,6,7], 7
 *                                |
 *            --------------------------------------------------
 *          2|               3|              6|                7|
 *        [2], 5           [3], 4           [6], 1           [7], 0
 *           |
 *      ----------------
 *    2|      3|
 *  [2,2], 3   [2,3], 2
 *     |
 *   ---------------
 *  |              |
 * [2,2,2], 1    [2,2,3],0
 *
 * Base Cases:
 * . When the remaining target is < 0, then return nothing
 * . When the target is 0 ie.., we got all the integers, add it to result
*/

// variable to store result
vector<vector<int>> res;

// DFS method to loop through all elements
void dfs(vector<int>& candidates, int idx, int target, vector<int>& temp) {
    // check if the target is < 0
    if (target < 0) {
        // target is negative, return
        return;
    }

    // Check if we reached the target
    if (target == 0) {
        // Got the target, push the subvector to result
        res.push_back(temp);
        return;
    }

    while (idx < candidates.size()) {
        temp.push_back(candidates[idx]);
        dfs(candidates, idx, target - candidates[idx], temp);
		idx++;
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty() || target <= 0) {
        return res;
    }

    vector<int> temp;
    dfs(candidates, 0, target, temp);

    return res;
}

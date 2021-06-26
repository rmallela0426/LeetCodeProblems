
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 40: Combination Sum II
 *
 * Given a collection of candidate numbers (candidates) and a target number (target), find
 * all unique combinations in candidates where the candidate numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 * Note: The solution set must not contain duplicate combinations.
 *
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 * Constraints:
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
*/
/*
 * Approach followed is a DFS backtrack solution where the input array is sorted
 * and does a dfs backtracking as we need to find the combination that matches the
 * target.
 * Eg: candidates = [10, 1, 2,7,6,1,5] => [1,1,2,5,6,7,10]
 *
 *                     arr          index  target
 *                 [1,1,2,5,6,7,10], 0th, 8
 *                      |
 *        -----------------------------------
 *      1|               1|
 *    [1], 1, 8 -1       [1], 2, 7
 *       |
 *    ----------------------------------
 *  1|              2|
 * [1,1], 2, 6     [1,2], 3, 5
 *
 * BaseCases:
 * . If the target is < 0, then the combination is not valid, return and generate a
 *   new combination.
 * . If the target is 0, then this is a valid combination, push it to res only if that
 *   combination is not present in result
*/

vector<vector<int>> res;
// DFS method to loop through all elements
void dfsBacktrack(vector<int>& candidates, int idx, int target, vector<int>& curr) {
    // Check if we have reached the target
    if (target == 0) {
        // Got the target, valid combination of nos push the subvector to result
        // Current combination of nos are not present in res
        res.push_back(curr);
        return;
    }

    // Generate a valid combinations starting from index idx
    // Loop all the numbers starting from the index idx
    for (int i = idx; i < candidates.size(); i++) {
        // Check if there is any duplicate number, exclude that so that it will
        // be a unique combination
        if (i > idx && candidates[i - 1] == candidates[i]) {
            // This could be a duplicate combination, no need to further procced
            continue;
        }

        // check if the curr number is greater than the target, if so no need
        // to procced the loop as the numbers are sorted and number after this
        // index will be always greater and target will be -ve
        if (candidates[i] > target) {
            break;
        }
        // Push the current value to the curr vector
        curr.push_back(candidates[i]);
        // Check whether the generated combination is valid or not
        dfsBacktrack(candidates, i + 1, target - candidates[i], curr);
        // backtrack, remove the current number and try to generate a new
        // combination of nos
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // Temporary vector to store the current combination
    vector<int> curr;

    // Sort the input vector
    sort(candidates.begin(), candidates.end());

    // DFS Backtrack method for stating index 0
    dfsBacktrack(candidates, 0, target, curr);

    // Return the result
    return res;
}

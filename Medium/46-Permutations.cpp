
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 46: Permutations
 *
 * Given an array nums of distinct integers, return all the possible permutations. You
 * can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 *
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 * Constraints:
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
*/
/*
 * Approach followed is dfs + backtracking solution, where we traverse from
 * index 0 and push the current element into vector
 *
*/
void dfsBacktrack(vector<int>& nums, bitset<8>& bt, vector<int>& curr, vector<vector<int>>& res) {
    // Base case: check whether curr permutation has all nos
    if (curr.size() == nums.size()) {
        // Got a valid permutation, push it to result
        res.push_back(curr);
    }

    // Traverse all the numbers of the input
    for (int i = 0; i < nums.size(); i++) {
        // Check if the current number is already in current permutation or not
        if (!bt[i]) {
            // Mark this number as visited
            bt.set(i);

            // Push the curr value to curr vector
            curr.push_back(nums[i]);

            // Add a new number to generate a permutation ie.., by performing dfs
            dfsBacktrack(nums, bt, curr, res);

            // backtrack
            curr.pop_back();

            bt.reset(i);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    // vector to store the permutations of the input array
    vector<vector<int>> res;

    // Temporary vector to store the current permutation
    vector<int> curr;

    // Bitset to know whether the current index is visited or not
    bitset<8> bt;

    dfsBacktrack(nums, bt, curr, res);

    return res;
}

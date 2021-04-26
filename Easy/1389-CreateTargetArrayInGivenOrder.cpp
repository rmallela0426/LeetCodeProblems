
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1389: Create Target Array in the Given Order
 *
 * Given two arrays of integers nums and index. Your task is to create target
 * array under the following rules:
 * Initially target array is empty.
 * . From left to right read nums[i] and index[i], insert at index index[i] the
     value nums[i] in target array.
 * . Repeat the previous step until there are no elements to read in nums and index.
 * Return the target array.
 * It is guaranteed that the insertion operations will be valid.
 *
 * Example 1:
 * Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
 * Output: [0,4,1,3,2]
 * Explanation:
 * nums       index     target
 * 0            0        [0]
 * 1            1        [0,1]
 * 2            2        [0,1,2]
 * 3            2        [0,1,3,2]
 * 4            1        [0,4,1,3,2]
 *
 * Example 2:
 * Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
 * Output: [0,1,2,3,4]
 * Explanation:
 * nums       index     target
 * 1            0        [1]
 * 2            1        [1,2]
 * 3            2        [1,2,3]
 * 4            3        [1,2,3,4]
 * 0            0        [0,1,2,3,4]
 *
 * Example 3:
 * Input: nums = [1], index = [0]
 * Output: [1]
 *
 * Constraints:
 * 1 <= nums.length, index.length <= 100
 * nums.length == index.length
 * 0 <= nums[i] <= 100
 * 0 <= index[i] <= i
*/
vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    // variable to store the target array
    vector<int> res;

    // If both target, index sizes are differentm, return empty result
    if (nums.size() != index.size()) {
        // nums, index sizes are different, return
        return res;
    }

    // Loop for all values of index, nums
    for (int i = 0; i < nums.size(); i++) {
        // Insert value at nums[i] in the place specified in index array
        res.insert(res.begin() + index[i], nums[i]);
    }

    return res;
}


/*
 *  Author: Raghavendra Mallela
*/

/*
 * LeetCode 645: Set Mismatch
 * You have a set of integers s, which originally contains all the numbers
 * from 1 to n. Unfortunately, due to some error, one of the numbers in s
 * got duplicated to another number in the set, which results in repetition
 * of one number and loss of another number.
 *
 * You are given an integer array nums representing the data status of this
 * set after the error.
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 *
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 *
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 *
 * Constraints:
 * 2 <= nums.length <= 104
 * 1 <= nums[i] <= 104
*/

vector<int> findErrorNums(vector<int>& nums) {
    // vector to store the result
    vector<int> res;

    // sort the array so that the nums are in ascending order
    std::sort(nums.begin(), nums.end());

    // Last number of array should be the size of the array
    // first number of array should be 1
    if (nums.back() != nums.size())
        res.push_back(nums.size());
    else if (nums.front() != 1)
        res.push_back(1);

    // As numbers are in order, the logic to see the current
    // with previous if it repeats, repeat is current
    // else if current - previous is greter than 1, then
    // missing is previous + 1
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            // num is repeated, push to result
            res.insert(res.begin(), nums[i]);
        }
        else if (nums[i] - nums[i - 1] > 1) {
            // there is a missing number ie.., nums[i-1] + 1
            res.push_back(nums[i - 1] + 1);
        }

        // Return if there is a result
        if (res.size() == 2)
            return res;
    }

    return res;
}

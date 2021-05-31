
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 453: Minimum Moves To Equal Array Elements
 *
 * Given an integer array nums of size n, return the minimum number of moves required to
 * make all array elements equal.
 * In one move, you can increment n - 1 elements of the array by 1.
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: 3
 * Explanation: Only three moves are needed (remember each move increments two elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * Example 2:
 * Input: nums = [1,1,1]
 * Output: 0
 *
 * Constraints:
 * n == nums.length
 * 1 <= nums.length <= 105
 * -109 <= nums[i] <= 109
 * The answer is guaranteed to fit in a 32-bit integer.
*/
/*
 * Approach is to get min element in the array and iterate over
 * the numbers to find the min moves required to make min number
 * to current number i.e.., difference between current number as
 * that of min number
 * Eg:  [1, 5] - we need to make 1 to 5 inorder for
 * the array to be equal i.e.., 4 moves which is
 * 5 - 1  = 4 moves
 *
*/
int minMoves(vector<int>& nums) {
    // find min element of the input vector
    // As min_element returns the iterator, get the value by dereferencing it
    int minNumber = *min_element(nums.begin(), nums.end());

    // variable to store min moves
    int minMoves = 0;

    // Traverse from right to left
    for (int& num : nums) {
        // Get min moves required to make the  min number to current number
        minMoves += num - minNumber;
    }

    return minMoves;
}

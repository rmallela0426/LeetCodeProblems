
/*
 * LeetCode 462: Minimum Moves To Equal Array Elements II
 *
 * Given an integer array nums of size n, return the minimum number of moves required to make
 * all array elements equal.
 * In one move, you can increment or decrement an element of the array by 1.
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 * Example 2:
 * Input: nums = [1,10,2,9]
 * Output: 16
 *
 * Constraints:
 * n == nums.length
 * 1 <= nums.length <= 105
 * -109 <= nums[i] <= 109
*/
/*
 * Solution is to find the min no of moves that are required
 * to make the array elements equal either by incrementing or
 * decrementing.
 * Approach followed is to sort the input array and find the
 * middle element and try to make all the elements equal to
 * midlle element i.e..., elements to left of middle needs to
 * increment and elements to right should decrement inorder for
 * making all the elements equal to middle element.
 *
 * For Eg: [-10, -3, -4, 8, 6, 1, 3]
 *     sort => [-10, -4, -3, 1, 3, 6, 8]
 * Middle element = 1
 * It takes 11 moves for making -10 to 1 (incrementing -10 by 1)
 * It takes 7 moves for making 8 to 1(decrementing 8 by 1)
 *
 * From above, it is clear that elements to the left will increment
 * and elements to right will decrement in order to make array
 * elements equal.
 *    -10 to 1 => 1 -(-10) = 1+10 = 11 moves
 *      8 to 1 => 1 - 8 = -7  = abs(-7) = 7 moves
 * In general, number of moves for making a number equal to middle
 * element is
 *             numMoves = abs(MiddleElement - CurrentElement)
 * By traversing the loop and adding all the moves will get the min
 * required moves for making all array elements equal.
*/
int minMoves2(vector<int>& nums) {
    // Sort the array elements
    sort(nums.begin(), nums.end());

    // Get the middle number
    int middleNum = nums[nums.size() / 2];

    // Min number of moves required to make all elements equal
    int minMoves = 0;

    // Iterate all the elements in the input array
    for (int num : nums) {
        // Calculate the no of moves required to make the current element
        // equal the middle element
        minMoves += abs(num - middleNum);
    }

    // return the min num of moves
    return minMoves;
}

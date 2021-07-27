
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 915: Partition Array into Disjoint Intervals
 *
 * Given an array nums, partition it into two (contiguous) subarrays left and
 * right so that:
 *
 * Every element in left is less than or equal to every element in right.
 *       left and right are non-empty.
 *       left has the smallest possible size.
 * Return the length of left after such a partitioning.  It is guaranteed that
 * such a partitioning exists.
 *
 * Example 1:
 * Input: nums = [5,0,3,8,6]
 * Output: 3
 * -Explanation: left = [5,0,3], right = [8,6]
 *
 * Example 2:
 * Input: nums = [1,1,1,0,6,12]
 * Output: 4
 * Explanation: left = [1,1,1,0], right = [6,12]
 *
 * Note:
 * 2 <= nums.length <= 30000
 * 0 <= nums[i] <= 106
 * It is guaranteed there is at least one way to partition nums as described.
*/

/*
 * As a partition need to be taken where every element in the
 * left partitition should be lessthan or equal to every element
 * in right partition ie.., max element in left partition should
 * be <=  min element on the right partition.
 * Approach is brute force where first loop traverse from 0 to n
 * and get the max element on left, and traverse loop from i + 1
 * to n to find the min index. If the maxelem in left <= minelem
 * in right, then i + 1 is the number of elements on left.
 * Eg: [5, 0, 3, 8, 6]
 *  if i = 0 then partitions are
 *                5    0, 3, 8, 6
 *      =>  lmax = 5, rmin = 0 , lmax > rmin so procced for next i
 *  if i = 1 then partitions are
 *                5, 0,   3, 8, 6
 *      =>  lmax = 5, rmin = 3 , lmax > rmin so procced for next i
 *  if i = 2 then partitions are
 *                5, 0, 3,   8, 6
 *      =>  lmax = 5, rmin = 6 , lmax < rmin we got a partition, no
 *  of elements on left partitions is i + 1
 * TC: O(n^2)
 * Submission: TLE
 *
*/
int partitionDisjoint(vector<int>& nums) {
    // Basecase: If the input vector is empty
    if (nums.empty()) {
        // If the input vector is empty, there is nothing to partition
        return 0;
    }

    // Variabel to store the maximum of left partition
    int lmax = INT_MIN;
    // Variable to store the minimum of right partition
    int rmin = INT_MAX;

    // Traverse loop for all input nums
    for (int i = 0; i < nums.size(); i++) {
        // As a new element is added to left partition, update the max
        // in the left partition
        lmax = max(lmax, nums[i]);
        // Reset the min element
        rmin = INT_MAX;

        // Traverse to right partition and find the min element in it
        for (int j = i + 1; j < nums.size(); j++) {
            // Find the min element in this partition
            rmin = min(rmin, nums[j]);
        }

        // Check if max of left partition <= min of right partition
        if (lmax <= rmin) {
            // Got a right partition. return the num of elements in left
            // partition.
            return i + 1;
        }
    }

    // All the elements is increasing order, return 
    return 1;
}

/*
 * Approach is a greedy solution where a left maximum and global max
 * is calculated, and when the current element is less than left max
 * then that element needs to be included in that partition, leftmax
 * is updated with the global max
*/
int partitionDisjoint(vector<int>& nums) {
    // Basecase: If the input vector is empty
    if (nums.empty()) {
        // If the input vector is empty, there is nothing to partition
        return 0;
    }

    // Variabel to store the maximum of left partition
    int lmax = nums[0];
    // Variable to store the minimum of right partition
    int gmax = nums[0];
    // index of where to partition
    int index = 0;

    // Traverse loop for all input nums
    for (int i = 1; i < nums.size(); i++) {
        // As a new element is added to left partition, update the global
        // max
        gmax = max(gmax, nums[i]);

        // Check if the current number is less than  lmax
        if (nums[i] < lmax) {
            // update the lmax with global max
            lmax = gmax;

            // update the partition index
            index = i;
        }
    }

    return index + 1;
}


/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 162: Find Peak Element
 *
 * A peak element is an element that is strictly greater than its neighbors.
 * Given an integer array nums, find a peak element, and return its index. If
 * the array contains multiple peaks, return the index to any of the peaks.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 * You must write an algorithm that runs in O(log n) time.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 *              number 2.
 *
 * Example 2:
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 *              element is 2, or index number 5 where the peak element is 6.
 *
 * Constraints:
 * 1 <= nums.length <= 1000
 * -231 <= nums[i] <= 231 - 1
 * nums[i] != nums[i + 1] for all valid i.
*/
/*
 * As the algorithm should run in logarthmic time, binary seach can
 * be used on the input array. As the input array is unsorted still
 * the binary search can be used because the peak element should be
 * greater than it right neighbour ie.., if the current element is
 * less than the next element then no need to check on the left side
 * and can be checked on right side ie..,
 *   a[i] < a[i + 1], for sure a[i] can't be peak
*/
int findPeakElement(vector<int>& nums) {
    // Define start and end indices for performing the binary search
    int start = 0;
    int end = nums.size() - 1;

    // Perform Binary Search until all elements are done ie..,
    //     start < end
    while (start < end) {
        // Calculate the mid element
        int mid = start + (end - start) / 2;

        // Check if the current element at mid is a peak or not
        if (nums[mid] > nums[mid + 1]) {
            // Current element might be peak as it is greater than its
            // right element need to traverse  on the left subarray so
            // left element of the current can be checked.
            end = mid;
        }
        else {
            // Current element is not a peak as it is smaller than its
            // right element, so we can traverse on the right subarray.
            start = mid + 1;
        }
    }

    // we are done with binary search, the peak element will be at start
    // index
    return start;
}

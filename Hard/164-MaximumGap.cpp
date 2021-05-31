
/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 164: Maximum Gap
 *
 * Given an integer array nums, return the maximum difference between two
 * successive elements in its sorted form. If the array contains less than
 * two elements, return 0.
 *
 * You must write an algorithm that runs in linear time and uses linear extra
 * space.
 *
 * Example 1:
 * Input: nums = [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9)
 * has the maximum difference 3.
 *
 * Example 2:
 * Input: nums = [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * 0 <= nums[i] <= 109
*/
/*
 * Approach followed is bucket sorting technique because the
 * algorithm should take only linear time
*/
int maximumGap(vector<int>& nums) {
    // check if the array hase less than two elements
    if (nums.size() < 2) {
        // Input has less than 2 elements return 0;
        return 0;
    }

    // For Performing bucket sort, first thing to do is to
    // find the range of the elements in input array ie...,
    // min and max elements in the input array
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    // variable to hold the size of input vector
    int n = nums.size();

    // Calculate the gap between each bucket and no of buckets
    // Eg: 3, 6, 9, 1 -> min = 1, max = 9
    // gap = 9 - 1 / n - 1 = 8 / 3 = 2.66
    // =>   -------------------------------------------------
    //     1     2.66          5.32          7.98           9
    // From above, it is clear that we have 4 buckets
    float gap = (float)(maxVal - minVal) / (float)(n - 1);

    // Cornor case where if the gap is zero
    if (gap == 0.0) {
        // Gap between buckets is zero ie.., we have same elements
        // in input array for eg: [1,1,1,1]
        // Max difference will be always zero
        return 0;
    }

    // Vectors to store min and max elements in each bucket
    vector<int> minBucket(n, INT_MAX);
    vector<int> maxBucket(n, INT_MIN);

    int idx;
    // Traverse the input vector and put the elements in correct bucket
    for (int& num : nums) {
        // Identify in which bucket this number should go
        idx = (num - minVal) / gap;

        // place the current number in min and max buckets
        minBucket[idx] = min(num, minBucket[idx]);
        maxBucket[idx] = max(num, maxBucket[idx]);
    }

    // Traverse the loop to find the max differnece between successive elements
    int prev = minBucket[0];
    // variable to store maxDifference
    int maxDiff = 0;

    for (int i = 0; i < n; i++) {
        // Check if the bucket is empty
        if (minBucket[i] != INT_MAX) {
            maxDiff = max(maxDiff, minBucket[i] - prev);
            prev = maxBucket[i];
        }
    }

    return maxDiff;
}

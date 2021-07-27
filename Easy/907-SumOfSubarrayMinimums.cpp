
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 907: Sum Of SubArray Minimums
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over every
 * (contiguous) subarray of arr. Since the answer may be large, return the answer
 * modulo 109 + 7.
 *
 * Example 1:
 * Input: arr = [3,1,2,4]
 * Output: 17
 * Explanation:
 * Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
 * Sum is 17.
 *
 * Example 2:
 * Input: arr = [11,81,94,43,3]
 * Output: 444
 *
 * Constraints:
 * 1 <= arr.length <= 3 * 104
 * 1 <= arr[i] <= 3 * 104
*/
// Brute force method, where we calculate the min
// of each subarray and add it to sum.
// TimeComplexity : TLE
int sumSubarrayMins(vector<int>& arr) {
    // Basecase: If input array is empty
    if (arr.empty()) {
        // Input array is empty, no sum
        return 0;
    }

    // As we are adding up the sum of all subarrays, the
    // can cross 32 bits so declering it as long
    long long int sum = 0;
    // Variable to store the min element for each subarray
    int minElem = 0;

    // Retrieve the arr length
    int n = arr.size();

    // Traverse the loop from 0 ... n
    for (int i = 0; i < n; i++) {
        // Update the min element initialized to start of the
        // subarray
        minElem = arr[i];

        // As we need to find continous subarray, traverse from
        // i to n
        for (int j = i; j < n; j++) {
            // update teh min element
            minElem = min(minElem, arr[j]);

            // Add the min element to the sum
            sum += minElem;
        }
    }

    int mod = 1e9 + 7;

    return (sum % mod);
}

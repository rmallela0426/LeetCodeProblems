
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1539: Kth Missing Positive Number
 *
 * Given an array arr of positive integers sorted in a strictly increasing order,
 * and an integer k.
 * Find the kth positive integer that is missing from this array.
 *
 * Example 1:
 * Input: arr = [2,3,4,7,11], k = 5
 * Output: 9
 * Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th
 * missing positive integer is 9.
 *
 * Example 2:
 * Input: arr = [1,2,3,4], k = 2
 * Output: 6
 * Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive
 * integer is 6.
 *
 * Constraints:
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * arr[i] < arr[j] for 1 <= i < j <= arr.length
*/
/*
 * Approach is to scan the missing numbers during the
 * traversal of the loop
*/
int findKthPositive(vector<int>& arr, int k) {
    // varaible to store the current number
    int curr = 1;

    // Interate over the numbers of the input array
    int i = 0;
    while (i < arr.size() && k > 0) {
        // Check the curr number is in the array or not
        if (arr[i] != curr) {
            // The current number is missing, decrement k
            k--;
        }
        else {
            // Number is available in input array, go for the
            // next one
            i++;
        }

        // Increment the current number
        curr++;
    }

    // Add the K ie.., if the Kth number is out of the numbers that
    // are present in the input array
    curr += k;

    // As curr is incremented at each step in the loop, decrement and
    // send the result
    return curr - 1;
}

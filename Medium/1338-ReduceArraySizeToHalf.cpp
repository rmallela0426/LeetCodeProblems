
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1338: Reduce Array Size To Half
 *
 * Given an array arr.  You can choose a set of integers and remove all the occurrences
 * of these integers in the array.
 * Return the minimum size of the set so that at least half of the integers of the array
 * are removed.
 *
 * Example 1:
 * Input: arr = [3,3,3,3,5,5,5,2,2,7]
 * Output: 2
 * Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e
 * equal to half of the size of the old array).
 * Possible sets of size 2 are {3,5},{3,2},{5,2}.
 * Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which
 * has size greater than half of the size of the old array.
 *
 * Example 2:
 * Input: arr = [7,7,7,7,7,7]
 * Output: 1
 * Explanation: The only possible set you can choose is {7}. This will make the new array
 * empty.
 *
 * Example 3:
 * Input: arr = [1,9]
 * Output: 1
 *
 * Example 4:
 * Input: arr = [1000,1000,3,7]
 * Output: 1
 *
 * Example 5:
 * Input: arr = [1,2,3,4,5,6,7,8,9,10]
 * Output: 5
 *
 * Constraints:
 * 1 <= arr.length <= 10^5
 * arr.length is even.
 * 1 <= arr[i] <= 10^5
*/
/*
 * Approach followed is a greedy solution where a frequency map
 * is calculated, map is sorted based on the value, travese all
 * the map elements and calculated the min elements need to be
 * removed so that the array can become less than or equal to the
 * size of the input array.
 *
 * Eg: [1, 1, 2, 3, 4, 4, 4, 5, 5, 5]
 * Freq map : [1 -> 2]
 *            [2 -> 1]
 *            [3 -> 1]
 *            [4 -> 3]
 *            [5 -> 3]
 * Sort the freq map based on value in decreasing order
 *   map : [4 -> 3]
 *         [5 -> 3]
 *         [1 -> 2]
 *         [2 -> 1]
 *         [3 -> 1]
 *
 * Traverse the map and remove the elements such that the left over
 * elements in the array should be <= n / 2
*/
int minSetSize(vector<int>& arr) {
    // Base case: if the input array is empty
    if (arr.empty()) {
        // Input array is empty
        return 0;
    }

    // Retrieve the size of the input array
    int n = arr.size();

    // Frequency map to store the frequencies of the elements
    unordered_map<int, int> mp;

    // Fill the frequency map
    for (int& num : arr) {
        // Increment the frequency of the current number
        mp[num]++;
    }

    // Initialize priority queue that sorts the elements using frequency in decreasing
    // order
    priority_queue<int> pq;
    // Push the map elements to priority queue ie.., values
    for (auto& num : mp) {
        pq.push(num.second);
    }

    // Now that the queue is sorted in decreasing order, traverse the queue to
    // find the min elements required to remove
    // min size required to make the array half
    int count = 0;

    // Running sum
    int sum = n;

    // Traverse while the remaining elements in array is <= n / 2 
    while (sum > n / 2) {
        // Add total number of elements that are removed
        sum -= pq.top();
        pq.pop();

        // Increment the count
        count++;
    }

    return count;
}

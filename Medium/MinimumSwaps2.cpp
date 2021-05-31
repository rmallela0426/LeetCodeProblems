
/*
 *  Author: Raghavendra Mallela
*/
/*
 * HackerRank Problem: Minimum Swaps 2
 *
 * You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n]
 * without any duplicates. You are allowed to swap any two elements. Find the minimum number
 * of swaps required to sort the array in ascending order.
 *
 * Example
 * arr = [7, 1, 3, 2, 4, 5, 6]
 * Perform the following steps:
 * i        arr                swap (indices)
 * 0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
 * 1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
 * 2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
 * 3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
 * 4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
 * 5   [1, 2, 3, 4, 5, 6, 7]
 * It took 5 swaps to sort the array.
 *
 * Function Description
 * Complete the function minimumSwaps in the editor below.
 * minimumSwaps has the following parameter(s):
 *     int arr[n]: an unordered array of integers
 * Returns
 *     int: the minimum number of swaps to sort the array
 *
 * Constraints:
 *  . 1 <= n <= 10^5
 *  . 1 <= arr[i] <= n
*/
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int numSwaps = 0;

    // As there are values from 1...n, solving the problem by
    // comparing elements with original position
    for (int i = 0; i < arr.size();) {
        if (arr[i] != i + 1) {
            // number is not at right position, swap it with
            // the number at original position
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
            // Increment a swap
            numSwaps++;

        }
        else {
            i++;
        }
    }

    return numSwaps;
}

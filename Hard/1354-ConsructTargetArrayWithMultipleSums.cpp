
/*
*  Author: Raghavendra Mallela
*/

/*
 * LeetCode 1354: Construct Target Array With Multiple Sums
 *
 * Given an array of integers target. From a starting array, A consisting of all
 * 1's, you may perform the following procedure :
 *        let x be the sum of all elements currently in your array.
 *        choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
 *        You may repeat this procedure as many times as needed.
 * Return True if it is possible to construct the target array from A otherwise return False.
 *
 * Example 1:
 * Input: target = [9,3,5]
 * Output: true
 * Explanation: Start with [1, 1, 1]
 * [1, 1, 1], sum = 3 choose index 1
 * [1, 3, 1], sum = 5 choose index 2
 * [1, 3, 5], sum = 9 choose index 0
 * [9, 3, 5] Done
 *
 * Example 2:
 * Input: target = [1,1,1,2]
 * Output: false
 * Explanation: Impossible to create target array from [1,1,1,1].
 *
 * Example 3:
 * Input: target = [8,5]
 * Output: true
 *
 * Constraints:
 * N == target.length
 * 1 <= target.length <= 5 * 10^4
 * 1 <= target[i] <= 10^9
*/
/*
 * Approach is to follow in reverse way, where in the loop tries to
 * convert the input vector to all 1's. Will use a priority queue
 * because it has constant lookup time for getting the largets number
 * To solve this, we will follow these steps −
 *     sum := 0
 *     n := size of target
 *     Calculate sum which is total of all ememnts in vector target
 *     Define priority queue pq, and initialize it with target array
 *     while true, do −
 *          x := top element of pq
 *          delete element from pq
 *          Return true if longest number is 1
 *          Calculate remaining by subrtracting the current from sum
 *          Return false if remaining is zero or it is >= current
 *          Calculate prev = current % remaining
 *          insert prev into pq
 *          sum := prev + remaining
 *     return true when sum is same as size of target, otherwise false
*/
bool isPossible(vector<int>& target) {
	// Check if the input vector is empty
	if (target.empty()) {
		// Input vector is empty, no way to create the vector
		return false;
	}

	// Check if the input vector has only one element
	if (target.size() == 1) {
		// Only one element is present, possible to construct the target
		// array only when the element is 1
		return target[0] == 1;
	}

	// Calculate the sum of all elements of the input vector
	long sum = accumulate(target.begin(), target.end(), (long)0);

	// Initialize a priority Queue with input vector
	std::priority_queue<int> pq(target.begin(), target.end());

	// Loop all the until the input vector is all 1's
	while (true) {
		// Retreive the largest element from Queue
		auto current = pq.top();
		pq.pop();
		if (current == 1) {
			// The longest element in the Queue is one which
			// is what needed
			return true;
		}

		// calculate the remaining sum
		auto remaining = sum - current;
		if (remaining == 0 || current <= remaining) {
			// Current value is less than remaining
			return false;
		}

		auto prev = current % remaining;
		pq.push(prev);
		sum = prev + remaining;
	}
	return true;
}

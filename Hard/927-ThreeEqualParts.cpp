
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 927: Three Equal Parts
 *
 * You are given an array arr which consists of only zeros and ones, divide the array into
 * three non-empty parts such that all of these parts represent the same binary value.
 *
 * If it is possible, return any [i, j] with i + 1 < j, such that:
 *   . arr[0], arr[1], ..., arr[i] is the first part,
 *   . arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
 *   . arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
 * All three parts have equal binary values.
 * If it is not possible, return [-1, -1].
 *
 * Note that the entire part is used when considering what binary value it represents. For
 * example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so
 * [0,1,1] and [1,1] represent the same value.
 *
 * Example 1:
 * Input: arr = [1,0,1,0,1]
 * Output: [0,3]
 *
 * Example 2:
 * Input: arr = [1,1,0,1,1]
 * Output: [-1,-1]
 *
 * Example 3:
 * Input: arr = [1,1,0,0,1]
 * Output: [0,2]
 *
 * Constraints:
 * 3 <= arr.length <= 3 * 104
 * arr[i] is 0 or 1
*/
/*
 * As the solution to get the arrays with 3 non-empty parts such
 * that all parts have same binary number, that means there should
 * be equal number of 1's. Count numbers of 1's in the input array
 * and if it is multiple of 3, then array can be split into 3 parts
 *
 * . Calculate the required number of 1's in each partition.
 * . Intialize an idx to last element in array and reduce the array
 *   until we get the required no of 1's in 3rd partition.
 *    Eg: [0,1,1,0,0,1,1,0,0,1,1,0]
 *                           |
 *                          idx
 * . Try to find the first partition index where it ends. Traverse
 *   from 0 index, find first 1 in first partition. Check binary
 *   number in 1st and 3rd partiotion. If not equal, then partition
 *   can't be possible.
 * . Find the 2nd partition index strating from first partition + 1
*/
// Gets the end of the partition, requires the partition start index
// for whom the end index needs to be found and third partition idx
// Which points to 1st one in that partion.
int getIndex(vector<int>& arr, int pIdx, int p3Idx) {
	// Move the partition start index until there is 1
	while (pIdx < p3Idx && arr[pIdx] == 0) {
		// Current element is 0, procced to next element
		pIdx++;
	}
	
	// Now that partition index points to the first 1, try to change
	// pIdx until the binary number matches that of 3rd partition
	while (p3Idx < arr.size()) {
		// Check if numbers in both partitions are same or not
		if (arr[pIdx] != arr[p3Idx]) {
			// Both the elements are not matching, partition is not
			// possible
			return -1;
		}
		
		// Current numbers in both partition matches, proceed to next
		// element
		pIdx++;
		p3Idx++;
	}
	
	// Now that pIdx points to first element of the next partition
	return pIdx - 1;
}

vector<int> threeEqualParts(vector<int>& arr) {
	// Vector to strore the result
	vector<int> res = {-1, -1};
	
	// BaseCase: If the input array is empty or if array has less than
	// 3 elements
	if (arr.empty() || arr.size() < 3) {
		// Partition is not possible
		return res;
	}
	
	// Retrieve the size of the input array
	int n = arr.size();
	
	// Count the number of 1's in the input array
	int num1s = 0;
	for (int& num : arr) {
		num1s += num;
	}
	
	// Check if the input contains only 0's
	if (num1s == 0) {
		// Input has only 0's return the indices of the input array
		return {0, (int)arr.size() - 1};
	}
	
	// Check if the num of 1s are not multiple of 3
	if (num1s % 3 != 0) {
		// Number of 1's is not a multiple of 3, partition is not
		// possible
		return res;
	}
	
	// No of 1s in input array is multiple of 3, calculate the total no
	// of 1s required in each partition
	int req1s = num1s / 3;
	
	// Index to hold the first 1 in the third partition
	int idx = n - 1;
	
	// Traverse the loop and find first 1 in the third partion
	while (idx >= 0 && req1s > 0) {
		// Check if the current num is 1
		if (arr[idx] == 1) {
			// Current num is one, reduce the req1s
			req1s--;
		}
		// decrement the current index;
		idx--;
	}
	
	// Since the idx points to one less than the first 1 in third partition
	// increment 1 to idx
	idx++;
	
	// Get the index where the first partition ends
	// Get Index function returns the end index of the partion if possible
	// otherwise reutrns -1.
	int fIdx = getIndex(arr, 0, idx);
	// Check if valid first partition is available or not
	if (fIdx < 0) {
		// Partition is not possible
		return res;
	}
	
	// Get the index where the second partition ends
	int sIdx = getIndex(arr, fIdx + 1, idx);
	// Check if valid second partition is available or not
	if (sIdx < 0) {
		// Partition is not possible
		return res;
	}
	
	// Now that we got the partitions, return the fIdx and sIdx + 1;
	return {fIdx, sIdx + 1};
}
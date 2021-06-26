
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1365: How many numbers are smaller than current number
 *
 * Given the array nums, for each nums[i] find out how many numbers in the array are smaller
 * than it. That is, for each nums[i] you have to count the number of valid j's such that
 * j != i and nums[j] < nums[i].
 *
 * Return the answer in an array.
 *
 * Example 1:
 * Input: nums = [8,1,2,2,3]
 * Output: [4,0,1,1,3]
 * Explanation:
 * For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
 * For nums[1]=1 does not exist any smaller number than it.
 * For nums[2]=2 there exist one smaller number than it (1).
 * For nums[3]=2 there exist one smaller number than it (1).
 * For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
 *
 * Example 2:
 * Input: nums = [6,5,4,8]
 * Output: [2,1,0,3]
 *
 * Example 3:
 * Input: nums = [7,7,7,7]
 * Output: [0,0,0,0]
 *
 * Constraints:
 * 2 <= nums.length <= 500
 * 0 <= nums[i] <= 100
*/
/*
 * Approach followed is a HashMap which is associative i.e.., stores
 * the values in sorting order and stores the frequencies of each
 * element in input.
 * Traverse the map and update the number of smaller element than of
 * current element.
 * Now traverse the input array find the no of smaller elements for
 * the current key and update the result
*/
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    // Vector to store the could of smaller numbers
    vector<int> res;

    // BaseCase: Check if the input is empty
    if (nums.empty()) {
        // Input is empty, return
        return res;
    }

    // vector to store the sorted elements of the input array
    std::map<int, int> mp;

    // Update the frequencies of each element of the input
    for (int& num : nums) {
        // Increment the frequencies of each individual element
        mp[num]++;
    }

    // Holds the number of smaller elements
    int count = 0;
    int freq = 0;

    // Calculate the no of smaller elements in the input
    for (auto& m : mp) {
        // Retrieve the frequecy of the current element
        freq = m.second;
        // Update the number of smaller elements that are in array
        mp[m.first] = count;
        // Update the count with the no of current elements, so that the
        // no of smaller elements will be adjusted accordingly when we
        // traverse to next element
        count += freq;
    }

    // Update the result vector
    for (int& num : nums) {
        // Find the no of smaller elements in the array from map for the
        // current key
        res.push_back(mp[num]);
    }

    return res;
}

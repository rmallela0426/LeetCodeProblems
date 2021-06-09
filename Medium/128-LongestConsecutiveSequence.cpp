
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 128: Longest Consecutive Sequence
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 *
 * Example 1:
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 *
 * Example 2:
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 * Constraints:
 * 0 <= nums.length <= 105
 * -109 <= nums[i] <= 109
*/
/*
 * Approach followed is to use an set which will store unique values
 * and sort in ascending order. Traverse all the elements of set from
 * index 1, check whether the current element is in sequence to previous
 * if so, increment the current length if not update length of sequence
 * till the current index
*/
int longestConsecutive(vector<int>& nums) {
    // Check if the input is empty
    if (nums.empty()) {
        return 0;
    }

    // Set to store the elements in sorted order and
    // remove duplicates
    set<int> st(nums.begin(), nums.end());

    // Variables to store the current length of consecutive sequence
    // and longestConsecutive Sequence
    // Initialized to 1 because we start traversing from 1st index
    int currSeq = 1;
    int longSeq = 1;

    // Traverse all elements in set
    auto prev = st.begin();
    auto it = prev;
    it++;
    for (; it != st.end(); it++, prev++) {
        if (*it == *prev + 1) {
            // current element is a sequence of prev element, increment
            // the length of the current sequence
            currSeq++;
        }
        else {
            // Current element is not in sequence to prev element,
            // update the longest sequence size
            longSeq = max(longSeq, currSeq);
            currSeq = 1;
        }
    }

    // Incase the longest sequence is the whole array length then it should
    // return the max length
    return max(longSeq, currSeq);
}

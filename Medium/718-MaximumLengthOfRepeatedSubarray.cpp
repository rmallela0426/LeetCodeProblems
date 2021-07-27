
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 718: Maximum Length Of Repeated Subarray
 *
 * Given two integer arrays nums1 and nums2, return the maximum length of a subarray that
 * appears in both arrays.
 *
 * Example 1:
 * Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * Output: 3
 * Explanation: The repeated subarray with maximum length is [3,2,1].
 *
 * Example 2:
 * Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * Output: 5
 *
 * Constraints:
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 100
*/
/*
 * Recursive Solution:
 *
 * If the last elements matches, then we have a solution and we can remove the last element
 * and find the solution for the remaining subproblems
 * i.e.., for Eg([1,2,3,2,1], [3,2,1,4,1])  ->   1 + MCS([1,2,3,2], [3,2,1,4]);
 *
 * Evaluate teh solutions for subproblems which should be max return value of either the solution
 * MAX(MCS([1,2,3,2,1], [3,2,1,4]), MCS([1,2,3,2], [3,2,1,4,1]));
 *
 * If either of the arrays is empty, then it should be zero as there is no LCS if iput is empty
*/
int maxCommonSubarray(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2, int maxlength) {
    // BaseCase: If either is empty
    if (idx1 == 0 || idx2 == 0) {
        // Either nums1 or num2 is empty, there wont be any common subarray
        // Return the max common subarray length
        return maxlength;
    }

    // Check if the both the elements at respective indices are equal or not
    if (nums1[idx1] == nums2[idx2]) {
        // Both the elements are equal ie.., we have a solution, get the solution
        // for remaining subproblems ie.., excluding the last characters
        maxlength = maxCommonSubarray(nums1, idx1 - 1, nums2, idx2 - 1, maxlength + 1);
    }

    // Now evaluate the subproblems by excluding the either of the last element
    return max(maxlength, max(maxCommonSubarray(nums1, idx1, nums2, idx2 - 1, maxlength),
                              maxCommonSubarray(nums1, idx1 - 1, nums2, idx2, maxlength)));
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
    return maxCommonSubarray(nums1, nums1.size() - 1, nums2, nums2.size() - 1, 0);
}

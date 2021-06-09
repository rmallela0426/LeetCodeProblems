
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 15: 3 Sum
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 *
 * Example 2:
 * Input: nums = []
 * Output: []
 *
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 * Constraints:
 * 0 <= nums.length <= 3000
 * -105 <= nums[i] <= 105
*/
/*
 * Approach is to sort the input in increasing order so that all
 * duplicate elements are adjacent to each other.
 * Traverse the loop from starting index 0, now we have nums[i],
 * now to find the sum of 2 nos which is equal to - nums[i] so that
 *    nums[i] + nums[j] + nums[k] = 0
 *
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    // variable to store the result
    vector<vector<int>> res;

    // check if we have sufficient elements to find the triplets
    if (nums.size() < 3) {
        // no sufficient elemets for finding triplets
        return res;
    }

    // Sort the input array in increasing order
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // variable to define the target
    int target;

    // Traverse and find all the triplets
    for (int i = 0; i < n; i++) {
        // Check if the current is duplicate or not
        if (i == 0 || nums[i] != nums[i - 1]) {
            // Not a duplicate number

            // By default the target should be target but
            // nums[i] + nums[j] + nums[k] = 0
            // => nums[j] + nums[k] = -nums[i]
            target = -nums[i];

            // Need to find the next two numbers
            // defining j & k indices
            int j = i + 1;
            int k = n - 1;

            // Traverse the remaining element to find 2 elements
            // such that sums equals the target
            // performing a binary search
            // Temp variables
            int a, b;

            while (j < k) {
                a = nums[j];
                b = nums[k];

                if (a + b == target) {
                    // sum of the nums is zero, found a triplet
                    res.push_back({ nums[i], a, b });

                    // check if the next element is a duplicate, if so
                    // exclude it as duplicate triplets are not allowed
                    while (j < k && nums[j] == a) {
                        // duplicate, exclude this
                        j++;
                    }

                    while (j < k&& nums[k] == b) {
                        // duplicate, exclude this
                        k--;
                    }
                }
                else {
                    // check if the sum is greater than target, if so reduce k
                    // if sum is less than target, then reduce j
                    a + b > target ? --k : ++j;
                }
            }
        }
    }

    // return generated triplets
    return res;
}

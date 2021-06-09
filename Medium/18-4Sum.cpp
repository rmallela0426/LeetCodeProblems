
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 18: 4 Sum
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 *
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 * Example 2:
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *
 * Constraints:
 * 1 <= nums.length <= 200
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
*/
/*
 * Approach followed is similar to 3 sum where first we sort the
 * input array in increasing order and traverse first loop start
 * with index i and second loop traverse from i + 1, now we need
 * to find 2 nos using Binary search that sums up to target.
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // variable to store the result
    vector<vector<int>> res;

    // check if we have sufficient elements to find the quadruplets
    if (nums.size() < 4) {
        // no sufficient elemets for finding quadruplets
        return res;
    }

    // Sort the input array in increasing order
    sort(nums.begin(), nums.end());

    int n = nums.size();
    // variable to define remaining target
    int target_2;

    // Temp variables
    int a, b, c, d;

    // Traverse and find all quadruplets
    for (int i = 0; i < n; i++) {
        a = nums[i];

        for (int j = i + 1; j < n; j++) {
            b = nums[j];

            // a + b + c + d = target
            // => c + d = target - a - b
            target_2 = target - a - b;

            // Need to find the remaning two numbers that sum up to target_2
            // defining k & l indicies
            int k = j + 1;
            int l = n - 1;

            // Traverse remainig elements such that sum is equal to target_2
            // using binary search
            while (k < l) {
                c = nums[k];
                d = nums[l];

                // check if the sum is equal to target_2
                if (c + d == target_2) {
                    // sum of the nums is zero, found a triplet
                    res.push_back({ a, b, c, d });

                    // check if the next element is a duplicate, if so
                    // exclude it as duplicate triplets are not allowed
                    while (k < l && nums[k] == c) {
                        // duplicate, exclude this
                        k++;
                    }

                    while (k < l&& nums[l] == d) {
                        // duplicate, exclude this
                        l--;
                    }
                }
                else {
                    // check if the sum is greater than target, if so reduce k
                    // if sum is less than target, then reduce j
                    c + d > target_2 ? --l : ++k;
                }
            }

            // Check if the next element is duplicate, if so exclude it
            while (j + 1 < n && nums[j + 1] == b) {
                j++;
            }
        }

        // check if the next element is duplicate, if so exclude it
        while (i + 1 < n && nums[i + 1] == a) {
            i++;
        }
    }

    // return the quadruplets
    return res;
}
